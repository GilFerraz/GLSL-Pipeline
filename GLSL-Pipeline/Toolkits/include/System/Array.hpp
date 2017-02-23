#pragma once

#include "Property.hpp"
#include "Object.hpp"
#include "Int32.hpp"
#include "Int64.hpp"

#include <array>

namespace System
{

#pragma region Global Types

    typedef unsigned int ArrayLength;

#pragma endregion 

    /**
     * \brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all
     *        arrays.
     */
    template<class T, ArrayLength TLength>
    class DLLExport Array : public Object
    {
    public:

#pragma region Public Constructors

        Array(const std::array<T, TLength>& obj);

#pragma endregion 

#pragma region Public Destructor

        ~Array();

#pragma endregion 

#pragma region Public Properties

        ReadonlyProperty(Int32, Lenght);
        Get(Lenght)
        {
            return TLength;
        }

        ReadonlyProperty(Int64, LongLenght);
        Get(LongLenght)
        {
            return TLength;
        }

#pragma endregion 

#pragma region Public Operators

        T& operator[](const Int32& index) const;

#pragma endregion 

#pragma region Public Conversion Operators

        operator std::array<T, TLength>() const;

#pragma endregion 

    private:
        T value[TLength];
        //std::array<T, TLength> value;
    };

#pragma region Public Constructors

    template <class T, ArrayLength TLength>
    Array<T, TLength>::Array(const std::array<T, TLength>& obj)
    {
        for (unsigned int i = 0; i < obj.size(); i++)
        {
            value[i] = obj[i];
        }
    }

#pragma endregion 

#pragma region Public Destructor

    template<class T, ArrayLength TLength>
    Array<T, TLength>::~Array()
    {
    }

#pragma endregion 

#pragma region Public Operators

    template<class T, ArrayLength TLength>
    T& Array<T, TLength>::operator[](const Int32& index) const
    {
        return const_cast<T&>(value[index]);
    }

#pragma endregion

#pragma region Public Conversion Operators

    template <class T, ArrayLength TLength>
    Array<T, TLength>::operator std::array<T, TLength>() const
    {
        return value;
    }

#pragma endregion 

}
