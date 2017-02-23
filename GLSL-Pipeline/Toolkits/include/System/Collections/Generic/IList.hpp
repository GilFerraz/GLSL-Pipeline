#pragma once

#include "../../Interface.hpp"
#include "ICollection.hpp"
#include "IEnumerable.hpp"

namespace System 
{
    struct Int32;
}

namespace System::Collections::Generic
{
    /**
     * \brief Represents a collection of objects that can be individually accessed by index.
     * \tparam T The type of elements in the list. 
     */
    template <typename T>
    interface IList : ICollection<T>, IEnumerable<>, IEnumerable<T>
    {
    public:

#pragma region Public Virtual Instance Methods

        /**
        * \brief Determines the index of a specific item in the IList<T>.
        * \param item The object to locate in the IList<T>.
        * \return The index of item if found in the list; otherwise, -1.
        */
        virtual Int32 IndexOf(T item) = 0;

        /**
        * \brief Inserts an item to the IList<T> at the specified index.
        * \param index The zero-based index at which item should be inserted.
        * \param item The object to insert into the IList<T>.
        */
        virtual void Insert(Int32 index, T item) = 0;

        /**
        * \brief Removes the IList<T> item at the specified index.
        * \param index The zero-based index of the item to remove.
        */
        virtual void RemoveAt(Int32 index) = 0;

#pragma endregion

#pragma region Public Virtual Operators

        /**
         * \brief Gets or sets the element at the specified index.
         * \param index The zero-based index of the element to get or set.
         * \return The element at the specified index.
         */
        virtual T operator[](const Int32& index) = 0;

#pragma endregion

    };
}
