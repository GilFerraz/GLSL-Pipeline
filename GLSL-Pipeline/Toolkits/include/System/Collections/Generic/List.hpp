#pragma once

#include "../../Property.hpp"
#include "../../String.hpp"

#include <vector>
#include <iterator>

#include "IList.hpp"

namespace System::Collections::Generic
{
    /**
     * \brief Represents a strongly typed list of objects that can be accessed by index.
     *        Provides methods to search, sort, and manipulate lists.
     * \tparam T The type of elements in the list.
     */
    template<typename T>
    class List : public Object
    {
    public:

#pragma region Public Constructors

        /**
         * \brief Initializes a new instance of the List<T> class that is empty and has the default initial capacity.
         */
        List();

        /**
         * \brief Initializes a new instance of the List<T> class that is empty and has the specified initial capacity.
         * \param capacity The number of elements that the new list can initially store.
         */
        explicit List(Int32 capacity);

        List(std::vector<T> vector);

#pragma endregion 

#pragma region Public Destructor

        ~List()
        {
        }

#pragma endregion 

#pragma region Public Properties

        Property(Int32, Capacity);
        Get(Capacity)
        {
            return vector.capacity();
        }
        Set(Capacity)
        {
            vector.reserve(Capacity);
            return vector;
        }

        ReadonlyProperty(Int32, Count);
        Get(Count)
        {
            return vector.size();
        }

#pragma endregion 

        //List(IEnumerable<T> collection);
        //T this[int index]{ get; set; }

#pragma region Public Instance Methods

        void Add(T item);

        //void AddRange(IEnumerable<T> collection);
        //ReadOnlyCollection<T> AsReadOnly();
        //int BinarySearch(int index, int count, T item, IComparer<T> comparer);
        //int BinarySearch(T item);
        //int BinarySearch(T item, IComparer<T> comparer);

        void Clear();

        /**
         * \brief Determines whether an element is in the List<T>.
         * \param item The object to locate in the List<T>.
         * \return Returns true if item is found in the List<T>; otherwise, returns false.
         */
        bool Contains(T item);

        //List<TOutput> ConvertAll<TOutput>(Converter<T, TOutput> converter);
        //void CopyTo(int index, T[] array, int arrayIndex, int count);
        //void CopyTo(T[] array);
        //void CopyTo(T[] array, int arrayIndex);
        //bool Exists(Predicate<T> match);
        //T Find(Predicate<T> match);
        //List<T> FindAll(Predicate<T> match);
        //int FindIndex(int startIndex, int count, Predicate<T> match);
        //int FindIndex(int startIndex, Predicate<T> match);
        //int FindIndex(Predicate<T> match);
        //T FindLast(Predicate<T> match);
        //int FindLastIndex(int startIndex, int count, Predicate<T> match);
        //int FindLastIndex(int startIndex, Predicate<T> match);
        //int FindLastIndex(Predicate<T> match);
        //void ForEach(Action<T> action);
        //List<T>.Enumerator GetEnumerator();
        //List<T> GetRange(int index, int count);

        /**
         * \brief Searches for the specified object and returns the zero-based index of the first occurrence within the entire 
         *        List<T>.
         * \param item The object to locate in the List<T>.
         * \return The zero-based index of the first occurrence of item within the entire List<T>, if found; otherwise, –1.
         */
        Int32 IndexOf(T item);
        
        /**
         * \brief Searches for the specified object and returns the zero-based index of the first occurrence within the range of
         *        elements in the List<T> that extends from the specified index to the last element.
         * \param item The object to locate in the List<T>.
         * \param index The zero-based starting index of the search. 0 (zero) is valid in an empty list.
         * \return The zero-based index of the first occurrence of item within the range of elements in the List<T> that extends 
         *         from index to the last element, if found; otherwise, –1.
         */
        Int32 IndexOf(T item, Int32 index);

        //int IndexOf(T item, int index, int count);
        //void Insert(int index, T item);
        //void InsertRange(int index, IEnumerable<T> collection);

        /**
         * \brief Searches for the specified object and returns the zero-based index of the last occurrence within the entire 
         *        List<T>.
         * \param item The object to locate in the List<T>.
         * \return The zero-based index of the last occurrence of item within the entire the List<T>, if found; otherwise, –1.
         */
        Int32 LastIndexOf(T item);
        
        //int LastIndexOf(T item, int index);
        //int LastIndexOf(T item, int index, int count);
        
        /**
         * \brief Removes the first occurrence of a specific object from the List<T>.
         * \param item The object to remove from the List<T>. The value can be null for reference types.
         * \return true if item is successfully removed; otherwise, false. 
         *         This method also returns false if item was not found in the List<T>.
         */
        bool Remove(T item);
        
        //int RemoveAll(Predicate<T> match);

        /**
         * \brief Removes the element at the specified index of the List<T>. 
         * \param index The zero-based index of the element to remove.
         */
        void RemoveAt(Int32 index);

        /**
         * \brief Removes a range of elements from the List<T>.
         * \param index The zero-based starting index of the range of elements to remove.
         * \param count The number of elements to remove.
         */
        void RemoveRange(Int32 index, Int32 count);

        /**
         * \brief Reverses the order of the elements in the entire List<T>.
         */
        void Reverse();

        /**
         * \brief Reverses the order of the elements in the specified range.
         * \param index The zero-based starting index of the range to reverse.
         * \param count The number of elements in the range to reverse.
         */
        void Reverse(Int32 index, Int32 count);

        //void Sort();
        //void Sort(Comparison<T> comparison);
        //void Sort(IComparer<T> comparer);
        //void Sort(int index, int count, IComparer<T> comparer);
        //T[] ToArray();

        /**
         * \brief Sets the capacity to the actual number of elements in the List<T>, 
         *        if that number is less than a threshold value.
         */
        void TrimExcess();

        //bool TrueForAll(Predicate<T> match);

#pragma endregion 

#pragma region Public Overrided Methods

        String ToString() const override;

#pragma endregion 

#pragma region Public Operators

        /**
         * \brief Gets or sets the element at the specified index.
         * \param index The zero-based index of the element to get or set.
         * \return Returns the element at the specified index.
         */
        T operator[](const Int32& index);
#pragma endregion 

    private:
        std::vector<T> vector;
    };

#pragma region Public Constructors

    template <typename T>
    List<T>::List()
    {
        vector = std::vector<T>();
    }

    template <typename T>
    List<T>::List(Int32 capacity)
    {
        List();
        vector.reserve(capacity);
    }

    template <typename T>
    List<T>::List(std::vector<T> vector)
    {
        this->vector = vector;
    }

#pragma endregion 

#pragma region Public Instance Methods

    template <typename T>
    void List<T>::Add(T item)
    {
        vector.push_back(item);
    }

    template <typename T>
    void List<T>::Clear()
    {
        vector.clear();
    }

    template <typename T>
    bool List<T>::Contains(T item)
    {
        if (std::find(vector.begin(), vector.end(), item) != vector.end()) 
        {
            return true;
        }
        return false;
    }

    template <typename T>
    Int32 List<T>::IndexOf(T item)
    {
        return IndexOf(item, 0);
    }

    template <typename T>
    Int32 List<T>::IndexOf(T item, Int32 index)
    {
        int i = 0;
        typename std::vector<T>::iterator iterator;

        for (iterator = vector.begin() + index; iterator < vector.end(); iterator++, i++)
        {
            if (vector[i] == item)
            {
                return i;
            }
        }
        return -1;
    }

    template <typename T>
    Int32 List<T>::LastIndexOf(T item)
    {
        int i = 0;
        int lastIndex = -1;
        typename std::vector<T>::iterator iterator;

        for (iterator = vector.begin(); iterator < vector.end(); iterator++, i++)
        {
            if (vector[i] == item)
            {
                lastIndex = i;
            }
        }
        return lastIndex;
    }

    template <typename T>
    bool List<T>::Remove(T item)
    {
        Int32 index = IndexOf(item);
        if (index != -1)
        {
            RemoveAt(index);
            return true;
        }
        return false;
    }

    template <typename T>
    void List<T>::RemoveAt(Int32 index)
    {
        vector.erase(vector.begin() + index);
    }

    template <typename T>
    void List<T>::RemoveRange(Int32 index, Int32 count)
    {
        vector.erase(vector.begin() + index, vector.begin() + count);
    }

    template <typename T>
    void List<T>::Reverse()
    {
        Reverse(0, Count);
    }

    template <typename T>
    void List<T>::Reverse(Int32 index, Int32 count)
    {
        std::reverse(vector.begin() + index, vector.begin() + count);
    }

    template <typename T>
    void List<T>::TrimExcess()
    {
        vector.shrink_to_fit();
    }

    template <typename T>
    String List<T>::ToString() const
    {
        return "List<T>";
    }

#pragma endregion 

#pragma region Public Operators

    template <typename T>
    T List<T>::operator[](const Int32& index)
    {
        return vector[index];
    }

#pragma endregion 
}
