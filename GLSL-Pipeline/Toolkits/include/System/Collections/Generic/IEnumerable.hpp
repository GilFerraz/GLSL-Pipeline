#pragma once

#include "../../Interface.hpp"

namespace System::Collections::Generic
{
    template<typename T = Object>
    interface IEnumerator;

    /**
     * \brief Exposes the enumerator, which supports a simple iteration over a collection of a specified type.
     * \tparam T The type of objects to enumerate.
     * \remarks IEnumerable<T> is the base interface for collections in the System.Collections.Generic namespace such as List<T>,
     *          Dictionary<TKey, TValue>, and Stack<T> and other generic collections such as ObservableCollection<T> and 
     *          ConcurrentStack<T>. Collections that implement IEnumerable<T> can be enumerated by using the foreach statement. For
     *          the non-generic version of this interface, see System.Collections.IEnumerable.\n
     *          For the non-generic version of this interface, see System.Collections.IEnumerable.\n
     *          IEnumerable<T> contains a single method that you must implement when implementing this interface; GetEnumerator,
     *          which returns an IEnumerator<T> object. The returned IEnumerator<T> provides the ability to iterate through the 
     *          collection by exposing a Current property.
     */
    template<typename T = Object>
    interface IEnumerable
    {
    protected:
        ~IEnumerable() = default;
    public:
        virtual IEnumerator<T> GetEnumerator() = 0;
    };
}
