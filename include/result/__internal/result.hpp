#ifndef RESULT___INTERNAL_RESULT_HPP
#define RESULT___INTERNAL_RESULT_HPP

template <class Left, class Right>
inline Result<Left, Right>::Result() : Right(Right{}) {}

template <class Left, class Right>
inline Result<Left, Right>::Result(std::variant<Left, Right> valueOrError) : valueOrError(valueOrError) {}

template <class Left, class Right>
template <class RightOut>
inline Result<Left, RightOut> Result<Left, Right>::map(std::function<RightOut(Right)> func) {

}

template <class Left, class Right>
template <class RightOut>
inline Result<Left, RightOut> Result<Left, Right>::flatMap(std::function<Result<Left, RightOut>(Right)> func) {

}

template <class Left, class Right>
template <class Visitor>
inline auto Result<Left, Right>::visit(Visitor visitor) -> decltype(visitor(std::declval<Left>())) {

}

template <class Left, class Right>
inline Right Result<Left, Right>::get() const {

}

template <class Left, class Right>
inline Right Result<Left, Right>::getOr(Right defaultValue) const noexcept {

}

template <class Left, class Right>
inline Right Result<Left, Right>::getOr(std::function<Right()> supplier) const {

}

template <class Left, class Right>
inline bool Result<Left, Right>::hasValue() const noexcept {

}

#endif