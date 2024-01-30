#include <iostream>

#include <gtest/gtest.h>
#include <string>
#include <variant>

#include "result/result.hpp"

#include "Error.hpp"

asuka1975::Result<Error, int> div10(int n) {
    if(n == 0) {
        return asuka1975::Result<Error, int>(Error {1, "cannot divide by zero"});
    } else {
        return asuka1975::Result<Error, int>(10 / n);
    }
}

TEST(MapTest, NormalCase) {
    int actual = div10(2)
        .map<int>([](int n) {
            return n + 2;
        })
        .get();
    
    EXPECT_EQ(actual, 7);
}

TEST(MapTest, NormalChangeReturnTypeCase) {
    std::string actual = div10(2)
        .map<std::string>([](int n) {
            return std::to_string(n);
        })
        .get();
    
    EXPECT_EQ(actual, "5");
}

TEST(MapTest, ErrorCase) {
    Error actual = div10(0)
        .map<int>([](int n) {
            return n + 2;
        })
        .getError();
    
    EXPECT_EQ(actual.errorCode, 1);
    EXPECT_EQ(actual.message, "cannot divide by zero");
}

TEST(MapTest, ErrorChangeReturnTypeCase) {
    Error actual = div10(0)
        .map<std::string>([](int n) {
            return std::to_string(n);
        })
        .getError();
    
    EXPECT_EQ(actual.errorCode, 1);
    EXPECT_EQ(actual.message, "cannot divide by zero");
}