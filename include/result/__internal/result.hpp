#ifndef RESULT___INTERNAL_RESULT_HPP
#define RESULT___INTERNAL_RESULT_HPP

#include "result/result.hpp"
#include "visitor_utils.hpp"

template <class Left, class Right>
inline asuka1975::Result<Left, Right>::Result() : Right(Right{}) {}

template <class Left, class Right>
inline asuka1975::Result<Left, Right>::Result(std::variant<Left, Right> valueOrError) : valueOrError(valueOrError) {}

template <class Left, class Right>
template <class RightOut>
inline asuka1975::Result<Left, RightOut> asuka1975::Result<Left, Right>::map(std::function<RightOut(Right)> func) {
    return std::visit(asuka1975::internal::visitor_utils::MapVisitor<Left, Right, RightOut>{ std::move(func) }, valueOrError);
}

template <class Left, class Right>
template <class RightOut>
inline asuka1975::Result<Left, RightOut> asuka1975::Result<Left, Right>::flatMap(std::function<Result<Left, RightOut>(Right)> func) {
    return asuka1975::Result<Left, RightOut>(std::visit(asuka1975::internal::visitor_utils::FlatMapVisitor<Left, Right, RightOut>{ std::move(func) }, valueOrError));
}

template <class Left, class Right>
template <class Visitor>
inline auto asuka1975::Result<Left, Right>::visit(Visitor visitor) -> decltype(visitor(std::declval<Left>())) {
    return std::visit(visitor, valueOrError);
}

template <class Left, class Right>
inline Right asuka1975::Result<Left, Right>::get() const {
    return std::get<1>(valueOrError);
}

template <class Left, class Right>
inline Right asuka1975::Result<Left, Right>::getOr(Right defaultValue) const noexcept {
    auto p = std::get<1>(valueOrError);
    if(!p) {
        return defaultValue;
    }
    return *p;
}

template <class Left, class Right>
inline Left asuka1975::Result<Left, Right>::getError() const {
    return std::get<0>(valueOrError);
}

template <class Left, class Right>
inline bool asuka1975::Result<Left, Right>::hasValue() const noexcept {
    return std::get_if<1>(&valueOrError) != nullptr;
}

#endif