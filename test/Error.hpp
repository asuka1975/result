#ifndef RESULT_TEST_ERROR_HPP
#define RESULT_TEST_ERROR_HPP

#include <string>

struct Error {
    int errorCode;
    std::string message;
};

#endif