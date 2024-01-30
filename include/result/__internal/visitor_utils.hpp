#ifndef RESULT___INTERNAL_VISITOR_UTILS_HPP
#define RESULT___INTERNAL_VISITOR_UTILS_HPP

#include <functional>
#include <variant>

namespace asuka1975::internal::visitor_utils {
    template <class Left, class Right, class RightOut> 
    class MapVisitor {
    public:

        MapVisitor(std::function<RightOut(Right)> func) : func(std::move(func)) {}
        std::variant<Left, RightOut> operator()(Left l) {
            return std::variant<Left, RightOut>(std::move(l));
        }
        std::variant<Left, RightOut> operator()(Right r) {
            return std::variant<Left, RightOut>(func(std::move(r)));
        }
    private:
        std::function<RightOut(Right)> func;
    };

    template <class Left, class Right, class RightOut> 
    class FlatMapVisitor {
    public:

        FlatMapVisitor(std::function<Result<Left, RightOut>(Right)> func) : func(std::move(func)) {}
        asuka1975::Result<Left, RightOut> operator()(Left l) {
            return std::variant<Left, RightOut>(std::move(l));
        }
        asuka1975::Result<Left, RightOut> operator()(Right r) {
            return func(std::move(r));
        }
    private:
        std::function<Result<Left, RightOut>(Right)> func;
    };
}

#endif