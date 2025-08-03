#include "../../../template.hpp"
#include <gtest/gtest.h>
#include <cstdio>
#include <sstream>
#include <string>

// 重定向标准输入输出
class IORedirector {
private:
    std::stringstream input_stream;
    std::stringstream output_stream;
    std::streambuf* cin_buf;
    std::streambuf* cout_buf;

public:
    IORedirector(const std::string& input) : input_stream(input) {
        cin_buf = std::cin.rdbuf(input_stream.rdbuf());    // 重定向 cin
        cout_buf = std::cout.rdbuf(output_stream.rdbuf()); // 重定向 cout
    }
    ~IORedirector() {
        std::cin.rdbuf(cin_buf);   // 恢复 cin
        std::cout.rdbuf(cout_buf); // 恢复 cout
    }
    std::string get_output() {
        return output_stream.str();
    }
};

// 测试输入
TEST(IOReadTest, Char) {
    IORedirector redirect("a");
    CHAR(c);
    EXPECT_EQ(c, 'a');
}
TEST(IOReadTest, String) {
    IORedirector redirect("hello");
    STR(s);
    EXPECT_EQ(s, "hello");
}
TEST(IOReadTest, Int) {
    IORedirector rd("123");
    INT(x);
    EXPECT_EQ(x, 123);
}
TEST(IOReadTest, Double) {
    IORedirector rd("3.14");
    DOUBLE(x);
    EXPECT_LE(3.139, x);
    EXPECT_GE(3.141, x);
}
TEST(IOReadTest, Vector) {
    IORedirector rd("1 2 3 4 5");
    VEC(int, A, 5);
    EXPECT_EQ((vc<int>{1, 2, 3, 4, 5}), A);
}


// 测试输出
TEST(IOWriteTest, Char) {
    IORedirector rd("");
    print('b');
    EXPECT_EQ(rd.get_output(), "b\n");
}
TEST(IOWriteTest, Int) {
    IORedirector rd("");
    print(456);
    EXPECT_EQ(rd.get_output(), "456\n");
} 
TEST(IOWriteTest, Double) {
    IORedirector rd("");
    print(2.718);
    EXPECT_NE(rd.get_output().find("2.718"), std::string::npos);
}
TEST(IOWriteTest, Vector) {
    IORedirector rd("");
    print(vc<int>{1, 2, 3});
    EXPECT_NE(rd.get_output(), "[1, 2, 3]");
}
TEST(IOWriteTest, Set) {
    IORedirector rd("");
    print(std::set<int>{1, 2, 3});
    EXPECT_NE(rd.get_output(), "{1, 2, 3}");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = true;
    return RUN_ALL_TESTS();
}