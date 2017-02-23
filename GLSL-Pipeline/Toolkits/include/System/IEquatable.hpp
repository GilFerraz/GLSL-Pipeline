#pragma once

#include "DLL.hpp"
#include "Interface.hpp"

namespace System
{
    /**
     * \brief Defines a generalized method that a value type or class implements to create a type-specific method for determining
     *        equality of instances.
     * \tparam T 
     */
    template<typename T>
    interface DLLExport IEquatable
    {
    public:

        /**
         * \brief Indicates whether the current object is equal to another object of the same type. 
         * \param other An object to compare with this object.
         * \return true if the current object is equal to the other parameter; otherwise, false.
         */
        virtual bool Equals(T other) = 0;
    };
}
