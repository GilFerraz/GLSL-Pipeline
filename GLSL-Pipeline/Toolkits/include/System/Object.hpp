#pragma once

#include "DLL.hpp"
//#define object Object

namespace System
{
    class String;

    /**
     * \brief Supports all classes in the .NET Framework class hierarchy and provides low-level services to derived classes. 
     *        This is the ultimate base class of all classes in the .NET Framework; it is the root of the type hierarchy.
     */
    class DLLExport Object
    {
    public:

        Object();
        virtual ~Object();

#pragma region Public Static Methods

        /**
        * \brief
        * \param objA
        * \param objB
        * \return
        */
        static bool Equals(Object objA, Object objB);

#pragma endregion 

#pragma region Public Virtual Methods

        /**
         * \brief Determines whether the specified object is equal to the current object.
         * \param obj The object to compare with the current object.
         * \return true if the specified object is equal to the current object; otherwise, false.
         */
        virtual bool Equals(Object obj);

        /**
         * \brief Returns a string that represents the current object.
         * \return A string that represents the current object.
         */
        virtual String ToString() const;

#pragma endregion 

        bool operator==(const Object& obj);

        operator String() const;
    };
}
