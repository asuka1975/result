#ifndef RESULT_RESULT_HPP
#define RESULT_RESULT_HPP

#include <functional>
#include <variant>

/**
 * @namespace asuka1975
 * @brief The namespace of Asuka1975's Software Collection
 * 
 */
namespace asuka1975 {

    /**
     * @brief Result class which has monadic operation.
     * 
     * @tparam Left  Abnormal value
     * @tparam Right Normal value
     */
    template <class Left, class Right>
    class Result {
    public:
        /**
         * @brief Construct a new Result object
         * @details The internal value is initialized by the default value of Right.
         */
        Result();

        /**
         * @brief Construct a new Result object
         * 
         * @param valueOrError     Normal or Abnormal value
         */
        Result(std::variant<Left, Right> valueOrError);

        /**
         * @brief Apply func to valueOrError and create a new Result object
         * @details If valueOrError has normal value, this method applies func to it. On the other hand, if valueOrError has abnormal value, this method do nothing.
         * 
         * @tparam RightOut 
         * @param func 
         * @return Result<Left, RightOut> 
         */
        template <class RightOut>
        Result<Left, RightOut> map(std::function<RightOut(Right)> func);

        /**
         * @brief Apply func to valueOrError and return a value func returning
         * @see Result<Left, Right>::map
         * 
         * @tparam RightOut 
         * @param func 
         * @return Result<Left, RightOut> 
         */
        template <class RightOut>
        Result<Left, RightOut> flatMap(std::function<Result<Left, RightOut>(Right)> func);

        /**
         * @brief Applies the visitor to the valueOrError
         * 
         * @tparam Visitor 
         * @param visitor 
         * @return decltype(visitor(std::declval<Left>())) 
         */
        template <class Visitor>
        auto visit(Visitor visitor) -> decltype(visitor(std::declval<Left>()));

        /**
         * @brief get a normal value
         * 
         * @return Right 
         * @throws std::bad_variant_access   If Result has abnormal value.
         */
        Right get() const;

        /**
         * @brief Get a normal value or default normal one
         * 
         * @return Right 
         * @throws std::bad_variant_access   If Result has abnormal value.
         */
        Right getOr(Right defaultValue) const noexcept;

        /**
         * @brief Get an abnormal value
         * 
         * @return Left 
         * @throws std::bad_variant_access   If Result has normal value.
         */
        Left getError() const;

        /**
         * @brief Whether it has normal or abnormal value.
         * 
         * @return true    normal value
         * @return false   abnormal value
         */
        bool hasValue() const noexcept;

    private:
        std::variant<Left, Right> valueOrError;
    };
}


#include "result/__internal/result.hpp"

#endif