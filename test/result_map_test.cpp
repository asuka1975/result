#include <iostream>

#include <gtest/gtest.h>
#include <variant>

#include "result/result.hpp"

#include "Error.hpp"

Result<Error, int> div10(int n) {
    if(n == 0) {
        return Result<Error, int>(Error {1, "cannot divide by zero"});
    } else {
        return Result<Error, int>(10 / n);
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

TEST(MapTest, ErrorCase) {
    Error actual = div10(0)
        .map<int>([](int n) {
            return n + 2;
        })
        .getError();
    
    EXPECT_EQ(actual.errorCode, 1);
    EXPECT_EQ(actual.message, "cannot divide by zero");
}