#ifndef RESULT___INTERNAL_RESULT_HPP
#define RESULT___INTERNAL_RESULT_HPP

#include "visitor_utils.hpp"

template <class Left, class Right>
inline Result<Left, Right>::Result() : Right(Right{}) {}

template <class Left, class Right>
inline Result<Left, Right>::Result(std::variant<Left, Right> valueOrError) : valueOrError(valueOrError) {}

template <class Left, class Right>
template <class RightOut>
inline Result<Left, RightOut> Result<Left, Right>::map(std::function<RightOut(Right)> func) {
    return std::visit(internal::visitor_utils::MapVisitor<Left, Right, RightOut>{ std::move(func) }, valueOrError);
}

template <class Left, class Right>
template <class RightOut>
inline Result<Left, RightOut> Result<Left, Right>::flatMap(std::function<Result<Left, RightOut>(Right)> func) {
    return std::visit(internal::visitor_utils::FlatMapVisitor<Left, Right, RightOut>{ std::move(func) }, valueOrError);
}

template <class Left, class Right>
template <class Visitor>
inline auto Result<Left, Right>::visit(Visitor visitor) -> decltype(visitor(std::declval<Left>())) {
    return std::visit(visitor, valueOrError);
}

template <class Left, class Right>
inline Right Result<Left, Right>::get() const {
    return std::get<1>(valueOrError);
}

template <class Left, class Right>
inline Right Result<Left, Right>::getOr(Right defaultValue) const noexcept {
    auto p = std::get<1>(valueOrError);
    if(!p) {
        return defaultValue;
    }
    return *p;
}

template <class Left, class Right>
inline Left Result<Left, Right>::getError() const {
    return std::get<0>(valueOrError);
}

template <class Left, class Right>
inline bool Result<Left, Right>::hasValue() const noexcept {
    return std::get_if<1>(&valueOrError) != nullptr;
}

#endif