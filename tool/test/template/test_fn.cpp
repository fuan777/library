#include "../../../template.hpp"
#include <gtest/gtest.h>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// 测试REV函数
TEST(FnTest, REVTest) {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> expected = {5, 4, 3, 2, 1};
    EXPECT_EQ(REV(v), expected);
    
    string s = "hello";
    string s_expected = "olleh";
    EXPECT_EQ(REV(s), s_expected);
}

// 测试COUNT函数
TEST(FnTest, COUNTTest) {
    vector<int> v = {1, 2, 2, 3, 2, 4};
    EXPECT_EQ(COUNT(v, 2), 3);
    EXPECT_EQ(COUNT(v, 5), 0);
    
    string s = "hello world";
    EXPECT_EQ(COUNT(s, 'l'), 3);
}

// 测试LB和UB函数
TEST(FnTest, LBUBTest) {
    vector<int> v = {1, 2, 2, 3, 4, 4, 5};
    EXPECT_EQ(LB(v, 3), 3);
    EXPECT_EQ(UB(v, 3), 4);
    EXPECT_EQ(LB(v, 2), 1);
    EXPECT_EQ(UB(v, 2), 3);
    EXPECT_EQ(LB(v, 6), 7);
}

// 测试UNIQUE函数
TEST(FnTest, UNIQUETest) {
    vector<int> v = {1, 2, 2, 3, 3, 3, 4};
    vector<int> expected = {1, 2, 3, 4};
    UNIQUE(v);
    EXPECT_EQ(v, expected);
}

// 测试chmax和chmin函数
TEST(FnTest, ChmaxChminTest) {
    int a = 5;
    EXPECT_EQ(chmax(a, 3), 0);
    EXPECT_EQ(a, 5);
    EXPECT_EQ(chmax(a, 7), 1);
    EXPECT_EQ(a, 7);
    
    int b = 5;
    EXPECT_EQ(chmin(b, 7), 0);
    EXPECT_EQ(b, 5);
    EXPECT_EQ(chmin(b, 3), 1);
    EXPECT_EQ(b, 3);
}

// 测试GCD函数
TEST(FnTest, GCDTest) {
    vector<int> v1 = {12, 18, 24};
    EXPECT_EQ(GCD(v1), 6);
    
    vector<int> v2 = {7, 13, 17};
    EXPECT_EQ(GCD(v2), 1);
    
    vector<int> v3 = {15, 30, 45, 60};
    EXPECT_EQ(GCD(v3), 15);
}

// 测试floor和ceil函数
TEST(FnTest, FloorCeilTest) {
    EXPECT_EQ(floor(7, 3), 2);
    EXPECT_EQ(floor(-7, 3), -3);
    EXPECT_EQ(floor(7, -3), -3);
    EXPECT_EQ(floor(-7, -3), 2);
    
    EXPECT_EQ(ceil(7, 3), 3);
    EXPECT_EQ(ceil(-7, 3), -2);
    EXPECT_EQ(ceil(7, -3), -2);
    EXPECT_EQ(ceil(-7, -3), 3);
}

// 测试bmod函数
TEST(FnTest, BmodTest) {
    EXPECT_EQ(bmod(7, 3), 1);
    EXPECT_EQ(bmod(-7, 3), 2);
    EXPECT_EQ(bmod(7, -3), -2);
    EXPECT_EQ(bmod(-7, -3), -1);
}

// 测试divmod函数
TEST(FnTest, DivmodTest) {
    auto result1 = divmod(7, 3);
    EXPECT_EQ(result1.first, 2);
    EXPECT_EQ(result1.second, 1);
    
    auto result2 = divmod(-7, 3);
    EXPECT_EQ(result2.first, -3);
    EXPECT_EQ(result2.second, 2);
}

// 测试MIN和MAX函数
TEST(FnTest, MinMaxTest) {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2};
    EXPECT_EQ(MIN(v), 1);
    EXPECT_EQ(MAX(v), 9);
    
    EXPECT_EQ(MIN(3, 1, 4, 1, 5), 1);
    EXPECT_EQ(MAX(3, 1, 4, 1, 5), 5);
}

// 测试check_palindromic函数
TEST(FnTest, CheckPalindromicTest) {
    EXPECT_TRUE(check_palindromic("racecar"));
    EXPECT_FALSE(check_palindromic("hello"));
    EXPECT_TRUE(check_palindromic(121));
    EXPECT_FALSE(check_palindromic(123));
}

// 测试binary_transfer函数
TEST(FnTest, BinaryTransferTest) {
    EXPECT_EQ(binary_transfer(5LL, 2LL), "101");
    EXPECT_EQ(binary_transfer(15LL, 2LL), "1111");
    EXPECT_EQ(binary_transfer(255LL, 16LL), "FF");
    EXPECT_EQ(binary_transfer(0LL, 2LL), "");
}

// 测试to_string函数
TEST(FnTest, ToStringTest) {
    EXPECT_EQ(to_string(42), "42");
    EXPECT_EQ(to_string(3.14), "3.140000");
    EXPECT_EQ(to_string(3.14f), "3.140000");
}
