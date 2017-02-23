#pragma once

#include "DLL.hpp"
#include "Object.hpp"

#include <cstdint>

namespace System
{
    struct DLLExport Int64 final : public Object
    {
    public:

#pragma region Public Constants

        static const Int64 MaxValue;
        static const Int64 MinValue;

#pragma endregion 

#pragma region  Public Constructors

        Int64(int64_t value);

#pragma endregion 

        ~Int64();

        String ToString() const override;

        operator int64_t() const;

    private:
        int64_t value;
    };
}