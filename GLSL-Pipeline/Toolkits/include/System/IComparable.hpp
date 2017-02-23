#pragma once

#include "DLL.hpp"
#include "Interface.hpp"

namespace System
{
    struct Int32;

    /**
     * \brief Defines a generalized comparison method that a struct or class implements to create a type-specific comparison method
     *        for ordering or sorting its instances.\n
     *        If no type is specified, defines a generalized type-specific comparison method that a value type or class implements
     *        to order or sort its instances.
     * \tparam T The type of object to compare. Default is Object.
     */
    template<typename T = Object>
    interface DLLExport IComparable
    {
    protected:
        ~IComparable() = default;

    public:

        /**
         * \brief Compares the current instance with another object of the same type and returns an integer that indicates whether
         *        the current instance precedes, follows, or occurs in the same position in the sort order as the other object.
         * \param other An object to compare with this instance.
         * \return A value that indicates the relative order of the objects being compared. The return value has these meanings:\n
         *         Less than zero: This instance precedes other in the sort order.\n
         *         Zero: This instance occurs in the same position in the sort order as other.\n
         *         Greater than zero: This instance follows other in the sort order.
         * \remarks CompareTo provides a strongly typed comparison method for ordering members of a generic collection object.
         *          Because of this, it is usually not called directly from developer code. Instead, it is called automatically by
         *          methods such as List<T>.Sort() and Add.\n
         *          This method is only a definition and must be implemented by a specific class or value type to have effect. The 
         *          meaning of the comparisons specified in the Return Values section ("precedes", "occurs in the same position 
         *          as", and "follows) depends on the particular implementation.\n
         *          By definition, any object compares greater than null, and two null references compare equal to each other.
         */
        virtual Int32 CompareTo(T other) = 0;
    };
}
