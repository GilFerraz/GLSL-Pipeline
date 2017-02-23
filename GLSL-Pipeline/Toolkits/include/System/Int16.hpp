#pragma once

#include "Object.hpp"
#include "IEquatable.hpp"
#include "IComparable.hpp"

#include <cstdint>

namespace System
{
    /**
     * \brief Represents a 16-bit signed integer.
     */
    struct DLLExport Int16 final : public Object, IComparable<>, IComparable<Int16>, IEquatable<Int16>
    {
    public:

#pragma region Public Constants

        /**
         * \brief Represents the largest possible value of an Int16. This field is constant.
         */
        static const Int16 MaxValue;

        /**
         * \brief Represents the smallest possible value of Int16. This field is constant.
         */
        static const Int16 MinValue;

#pragma endregion 

#pragma region Public Constructors

        Int16(int16_t value);

#pragma endregion 

#pragma region Public Destructor

        ~Int16();

#pragma endregion

#pragma region Public Overrided Instance Methods

        /**
         * \brief Converts the numeric value of this instance to its equivalent string representation.
         * \return The string representation of the value of this instance, consisting of a minus sign if the value is negative,
         *         and a sequence of digits ranging from 0 to 9 with no leading zeroes.
         */
        String ToString() const override;

        /**
         * \brief Returns a value indicating whether this instance is equal to a specified Int16 value.
         * \param value An Int16 value to compare to this instance.
         * \return true if obj has the same value as this instance; otherwise, false.
         */
        bool Equals(Int16 value) override;
        
        /**
         * \brief Compares this instance to a specified object and returns an integer that indicates whether the value of this
         *        instance is less than, equal to, or greater than the value of the object.
         * \param other An object to compare, or null.
         * \return A signed number indicating the relative values of this instance and value.
         */
        Int32 CompareTo(Object other) override;
        
        /**
         * \brief Compares this instance to a specified 16-bit signed integer and returns an integer that indicates whether the
         *        value of this instance is less than, equal to, or greater than the value of the specified 16-bit signed integer.
         * \param other An integer to compare.
         * \return A signed number indicating the relative values of this instance and value.
         */
        Int32 CompareTo(Int16 other) override;

#pragma endregion 

#pragma region Public Conversion Operators

        operator int16_t() const;

#pragma endregion

    private:
        int16_t value;
    };

}
