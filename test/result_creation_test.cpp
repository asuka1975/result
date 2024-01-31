#include <iostream>

#include <gtest/gtest.h>
#include <variant>

#include "result/result.hpp"

#include "Error.hpp"

asuka1975::Result<Error, int> genResult(int n) {
    return asuka1975::Result<Error, int>(n);
}

asuka1975::Result<Error, int> genResult(Error err) {
    return asuka1975::Result<Error, int>(err);
}

TEST(CreationTest, NormalCase1) {
    EXPECT_EQ(genResult(0).get(), 0);
}

TEST(CreationTest, NormalCase2) {
    EXPECT_EQ(genResult(10).get(), 10);
}

TEST(CreationTest, ErrorCase1) {
    Error error = genResult(Error {1, "message"}).getError();
    EXPECT_EQ(error.errorCode, 1);
    EXPECT_EQ(error.message, "message");
}

TEST(CreationTest, ErrorCase2) {
    EXPECT_THROW(genResult(Error{1, "message"}).get(), std::bad_variant_access);
}

TEST(CreationTest, ErrorCase3) {
    EXPECT_FALSE(genResult(Error {1, "message"}).hasValue());
}