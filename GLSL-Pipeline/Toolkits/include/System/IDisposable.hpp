#pragma once

#include "Interface.hpp"

namespace System
{
    /**
     * \brief Provides a mechanism for releasing unmanaged resources.
     */
    interface DLLExport IDisposable
    {
    public:

        /**
         * \brief Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged resources.
         */
        virtual void Dispose() = 0;
    };
}
