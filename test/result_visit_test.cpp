#include <iostream>

#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>

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

struct Visitor1 {
    std::string operator()(int n) {
        return std::to_string(n);
    }
    std::string operator()(Error e) {
        return e.message;
    }
};

struct Visitor2 {
    void operator()(int n) {
        std::cout << n << std::endl;
    }
    void operator()(Error e) {
        std::cout << e.message << std::endl;
    }
};

TEST(VisitTest, NormalCase) {
    std::string r = div10(2)
        .visit(Visitor1{});
    
    EXPECT_EQ(r, "5");
}

TEST(VisitTest, ErrorCase) {
    std::string r = div10(0)
        .visit(Visitor1{});
    
    EXPECT_EQ(r, "cannot divide by zero");
}

TEST(VisitTest, NormalReturnVoidCase) {
    testing::internal::CaptureStdout();
    div10(2)
        .visit(Visitor2{});
    
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "5\n");
    
}

TEST(VisitTest, ErrorReturnVoidCase) {
    testing::internal::CaptureStdout();
    div10(0)
        .visit(Visitor2{});
    
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "cannot divide by zero\n");
}