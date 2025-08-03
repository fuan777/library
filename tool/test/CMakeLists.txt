cmake_minimum_required(VERSION 3.10)
project(test)

# 添加 C++20 标准支持
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
# 修改文件遍历方式，精确排除 build 目录和编译器生成文件
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false "*.cpp")
list(FILTER TEST_SOURCES EXCLUDE REGEX "(/build/|CMakeFiles|CompilerIdCXX)")

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} GTest::GTest GTest::Main)
    
    # 使用 DISCOVER_TESTS 自动发现 GTest 测试
    include(GoogleTest)
    gtest_discover_tests(${TEST_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endforeach()

message(STATUS "当前工作目录: ${CMAKE_CURRENT_SOURCE_DIR}")
foreach(TEST_FILE ${TEST_SOURCES})
    message(STATUS "测试文件: ${TEST_FILE}")
endforeach()

enable_testing()