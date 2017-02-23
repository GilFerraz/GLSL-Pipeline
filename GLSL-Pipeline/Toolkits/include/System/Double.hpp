#pragma once

#include "DLL.hpp"
#include "Object.hpp"

namespace System
{
    /**
     * \brief Represents a double-precision floating-point number.
     */
    struct DLLExport Double final : public Object
    {
    public:

#pragma region  Public Constants

        /**
         * \brief Represents the smallest positive Double value that is greater than zero. This field is constant.
         */
        static const Double Epsilon;

        /**
         * \brief Represents the largest possible value of a Double. This field is constant.
         */
        static const Double MaxValue;

        /**
         * \brief Represents the smallest possible value of a Double. This field is constant.
         */
        static const Double MinValue;

        /**
         * \brief Represents a value that is not a number (NaN). This field is constant.
         */
        static const Double NaN;

        /**
         * \brief Represents negative infinity. This field is constant.
         */
        static const Double NegativeInfinity;

        /**
         * \brief Represents positive infinity. This field is constant.
         */
        static const Double PositiveInfinity;

#pragma endregion

        Double(double value);
        ~Double();

#pragma region Public Overrided Methods

        /**
         * \brief Converts the numeric value of this instance to its equivalent string representation.
         * \return The string representation of the value of this instance.
         */
        String ToString() const override final;

#pragma endregion

#pragma region Public Arithmetic Operators

        Double operator+(Double value) const;

#pragma endregion

#pragma region Public Convertsion Operators

        operator double() const;

#pragma endregion

    private:
        double value;
    };
}
