#!/bin/bash

BUILD_DIR="./build"
TEST_FILTER="${1:-}"  # 获取第一个参数作为过滤条件，默认为空

# 检查是否包含 --detail 参数
DETAIL_MODE=false
for arg in "$@"; do
    if [ "$arg" = "--detail" ]; then
        DETAIL_MODE=true
        break
    fi
done

cd "$(dirname "$0")"

if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

# CMake
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cmake ..
make

if [ $? -eq 0 ]; then
    echo "编译成功，开始运行测试..."
    if [ -n "$TEST_FILTER" ]; then
        echo "过滤条件: $TEST_FILTER"
        ctest -V -R "^${TEST_FILTER}.*$" > test_log.txt 2>&1
    else
        ctest -V > test_log.txt 2>&1
    fi
    
    # 定义颜色常量
    RED="\033[1;31m"
    GREEN="\033[1;32m"
    YELLOW="\033[4m\033[33m"
    BLUE="\033[4m\033[34m"
    RESET="\033[0m"

    # 颜色函数
    colorize() {
        local text="$1"
        local color="$2"
        echo -e "${color}${text}${RESET}"
    }
    
    while IFS= read -r line; do
        if [[ "$line" =~ "RUN" ]]; then
            # 提取 RUN 后的任务名
            if [[ $line =~ RUN[[:space:]]+\][[:space:]]+(.[a-zA-Z.]+) ]]; then
                task_name="${BASH_REMATCH[1]}"
                echo "任务名: $task_name"
                line="${line/$task_name/$(colorize "$task_name" $BLUE)}"
            fi
            echo -e "$line"
        elif [[ "$line" =~ "Passed" ]]; then
            # 匹配 Passed 行中的数字 (X.XX sec)
            if [[ $line =~ Passed[[:space:]]+(.[0-9.]+) ]]; then
                time="${BASH_REMATCH[1]}"
                line="${line/$time/$(colorize "$time" $YELLOW)}"
            fi
            echo -e "${line/Passed/$(colorize "Passed" $GREEN)}"
        elif [[ "$line" =~ "Failed" ]]; then
            echo -e "${line/Failed/$(colorize "Failed" $RED)}"
        elif [[ "$line" =~ "tests passed" ]]; then
            echo "$line"
        elif [[ "$line" =~ "Total Test time" ]]; then
            if [[ $line =~ =[[:space:]]+(.[0-9.]+) ]]; then
                time="${BASH_REMATCH[1]}"
                line="${line/$time/$(colorize "$time" $YELLOW)}"
            fi
            echo "$line"
        else
            # 详细模式：输出完整日志
            if [ "$DETAIL_MODE" = true ]; then
                echo "$line"
            fi
        fi
    done < test_log.txt
    rm test_log.txt
else
    echo "编译失败，请检查错误信息。"
fi