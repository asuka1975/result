#ifndef RESULT_RESULT_HPP
#define RESULT_RESULT_HPP

#include <functional>
#include <variant>

template <class Left, class Right>
class Result {
public:
    Result();
    Result(std::variant<Left, Right> valueOrError);
    template <class RightOut>
    Result<Left, RightOut> map(std::function<RightOut(Right)> func);
    template <class RightOut>
    Result<Left, RightOut> flatMap(std::function<Result<Left, Right>(Right)> func);
    template <class Visitor>
    auto visit(Visitor visitor);
    Right get() const;
    Right getOr(Right defaultValue) const noexcept;
    Right getOr(std::function<Right()> supplier) const noexcept;
    bool hasValue() const noexcept;

private:
    std::variant<Left, Right> valueOrError;
};

#include "result/__internal/result.hpp"

#endif