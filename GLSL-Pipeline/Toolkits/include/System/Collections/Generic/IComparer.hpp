#pragma once

#include "../../../Interface.hpp"

namespace System::Collections::Generic
{
    /**
     * \brief Defines a method that a type implements to compare two objects.
     * \tparam T The type of objects to compare.
     */
    template <typename T>
    interface IComparer
    {
        /**
         * \brief Compares two objects and returns a value indicating whether one is less than, equal to, or greater than the
         *        other.
         * \param x The first object to compare.
         * \param y The second object to compare.
         * \return A signed integer that indicates the relative values of x and y, as shown in the following table.
         * \remarks Implement this method to provide a customized sort order comparison for type T.\n
         *          Comparing null with any reference type is allowed and does not generate an exception. A null reference is
         *          considered to be less than any reference that is not null.
         */
        virtual int Compare(T x, T y) = 0;
    };
}
