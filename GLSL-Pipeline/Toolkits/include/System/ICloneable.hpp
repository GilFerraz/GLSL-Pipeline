#pragma once

#include "DLL.hpp"
#include "Interface.hpp"

namespace System
{
    class Object;

    /**
     * \brief Supports cloning, which creates a new instance of a class with the same value as an existing instance.
     */
    interface DLLExport ICloneable
    {
    protected:
        ~ICloneable() = default;

    public:
        /**
         * \brief Creates a new object that is a copy of the current instance.
         * \return A new object that is a copy of this instance.
         */
        virtual Object Clone() = 0;
    };
}
