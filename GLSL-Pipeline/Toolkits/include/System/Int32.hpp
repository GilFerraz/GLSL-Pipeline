#pragma once

#include "Object.hpp"
#include "IComparable.hpp"
#include "IEquatable.hpp"

#include <cstdint>

namespace System
{
    class String;

    struct DLLExport Int32 final : public Object, IComparable<>, IComparable<Int32>, IEquatable<Int32>
    {
    public:
        static const Int32 MaxValue;
        static const Int32 MinValue;

        Int32(int32_t value);
        ~Int32();


#pragma region Public Overrided Instance Methods

        String ToString() const override;
        bool Equals(Int32 value) override;
        Int32 CompareTo(Object other) override;
        Int32 CompareTo(Int32 other) override;

#pragma endregion

        operator int32_t() const;

    private:
        int32_t value;
    };
}
