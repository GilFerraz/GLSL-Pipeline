#pragma once

#include "../../Interface.hpp"
#include "IEnumerable.hpp"

namespace System::Collections::Generic
{
    /**
     * \brief Defines methods to manipulate generic collections.
     * \tparam T The type of the elements in the collection.
     */
    template<typename T>
    interface ICollection : IEnumerable<>, IEnumerable<T>
    {

#pragma region Public Virtual Properties

        /**
         * \brief Gets the number of elements contained in the ICollection<T>.
         * \return The number of elements contained in the ICollection<T>.
         */
        virtual Int32 GetCount() = 0;

        /**
         * \brief Gets a value indicating whether the ICollection<T> is read-only.
         * \return true if the ICollection<T> is read-only; otherwise, false.
         * \remarks A collection that is read-only does not allow the addition or removal of elements after the collection is
         *          created. Note that read-only in this context does not indicate whether individual elements of the collection
         *          can be modified, since the ICollection<T> interface only supports addition and removal operations.
         *          For example, the IsReadOnly property of an array that is cast or converted to an ICollection<T> object returns
         *          true, even though individual array elements can be modified.
         */
        virtual bool GetIsReadOnly() = 0;

#pragma endregion

#pragma region Public Virtual Instance Methods

        /**
         * \brief Adds an item to the ICollection<T>.
         * \param item The object to add to the ICollection<T>.
         */
        virtual void Add(T item) = 0;

        /**
         * \brief Removes all items from the ICollection<T>.
         * \remarks Count must be set to 0, and references to other objects from elements of the collection must be released.
         */
        virtual void Clear() = 0;

        /**
         * \brief Determines whether the ICollection<T> contains a specific value.
         * \param item The object to locate in the ICollection<T>.
         * \return
         * \remarks Implementations can vary in how they determine equality of objects; for example, List<T> uses
         *          Comparer<T>.Default, whereas Dictionary<TKey, TValue> allows the user to specify the IComparer<T>
         *          implementation to use for comparing keys.
         */
        virtual bool Contains(T item) = 0;

        /**
         * \brief Copies the elements of the ICollection<T> to an Array, starting at a particular Array index.
         * \param array The one-dimensional Array that is the destination of the elements copied from ICollection<T>. The Array
         *              must have zero-based indexing.
         * \param arrayIndex The zero-based index in array at which copying begins.
         */
        virtual void CopyTo(T* array, int arrayIndex) = 0;

        /**
         * \brief Removes the first occurrence of a specific object from the ICollection<T>.
         * \param item The object to remove from the ICollection<T>.
         * \return true if item was successfully removed from the ICollection<T>; otherwise, false. This method also returns false
         *         if item is not found in the original ICollection<T>.
         * \remarks Implementations can vary in how they determine equality of objects; for example, List<T> uses
         *          Comparer<T>.Default, whereas, Dictionary<TKey, TValue> allows the user to specify the IComparer<T>
         *          implementation to use for comparing keys.\n
         *          In collections of contiguous elements, such as lists, the elements that follow the removed element move up to
         *          occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also
         *          updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such
         *          as a hash table.
         */
        virtual bool Remove(T item) = 0;

#pragma endregion

    };
}
