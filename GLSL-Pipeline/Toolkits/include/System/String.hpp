#pragma once

#include "Property.hpp"
#include "Object.hpp"
#include "Int32.hpp"

#include <string>

namespace System
{
    struct Single;
    struct Double;

    /**
     * \brief Represents text as a sequence of UTF-16 code units.
     */
    class DLLExport String final : public Object
    {
    public:

        /**
         * \brief Represents the empty string. This field is read-only.
         */
        static const String Empty;

#pragma region Public Constructos

        String(const char value);
        String(const char value[]);
        String(const std::string value);
        String(const Object value);

#pragma endregion 

#pragma region Public Destructor

        ~String();

#pragma endregion

#pragma region Public Instance Properties

        ReadonlyProperty(Int32, Lenght);
        Get(Lenght)
        {
            return value->length();
        }

#pragma endregion 

#pragma region Public Instance Methods

        String Append(char c);
        String Append(char c[]) const;
        String Append(std::string value) const;
        String Append(String value) const;

#pragma endregion 

#pragma region  Public Overrided Methods

        String ToString() const override;

#pragma endregion 

#pragma region Public Arithmetic Operators

        String operator+(const String& value) const;
        String operator+(const Object& value) const;

#pragma endregion 

        operator std::string() const;

    private:
        std::string* value;
    };

#pragma region Global Operator Overloads

    inline String operator+(const char lhs[], const String& rhs)
    {
        return String(lhs) + rhs;
    }

    inline String operator+(const char lhs[], const Object& rhs)
    {
        return String(lhs) + rhs.ToString();
    }

#pragma endregion 

}

