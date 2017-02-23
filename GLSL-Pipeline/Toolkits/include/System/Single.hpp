#pragma once

#include "Object.hpp"

namespace System
{
    struct DLLExport Single final : public Object
    {
    public:

#pragma region  Public Constants

        static const Single Epsilon;
        static const Single MaxValue;
        static const Single MinValue;
        static const Single NaN;
        static const Single NegativeInfinity;
        static const Single PositiveInfinity;

#pragma endregion 

        Single();
        Single(float value);
        ~Single();

#pragma region Public Overrided Methods

        String ToString() const override;

#pragma endregion 

        operator float() const
        {
            return value;
        }

    private:
        float value;
    };

}
