#ifndef RESULT_RESULT_HPP
#define RESULT_RESULT_HPP

#include <variant>

template <class Left, class Right>
class Result {
public:
    Result();
    Result(std::variant<Left, Right> valueOrError);

private:
    std::variant<Left, Right> valueOrError;
};

#include "result/__internal/result.hpp"

#endif