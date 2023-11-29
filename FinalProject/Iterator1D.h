#pragma once
/**
 * @file Iterator1D.h
 * @author Billy Ndegwah Micah
 *
 * Description: The Iterator1D is used in iterating through the 1D array passed to it.
 * It'll be used by the Character entity to access certain accessories in the array.
 *
 * Properties:
 * -----------
 * > _array: T* - the array to be iterated over
 * > _size: int - the size of the array
 * > _index: int - the index of the current element in the array
 *
 * Methods:
 * --------
 * > Iterator1D() - This is the default constructor for the Iterator1D class.
 * > Iterator1D(array: T*, size: int) - This is the overloaded constructor for the Iterator1D class.
 * > Iterator1D(iterator: Iterator1D&) - This is the copy constructor for the Iterator1D class.
 * > ~Iterator1D() - This is the destructor for the Iterator1D class.
 * > MoveNext() - This function facilitate forward traversal within the 1D array.
 * > MovePrevious() - This function facilitate backward traversal within the 1D array.
 * > Getters and setters for all properties
 * > GetCurrentItem() - This method is used to get the current item in the array
 * > begin() - This is the range-based for loop begin method for the Iterator1D class
 * > end() - This is the range-based for loop end method for the Iterator1D class
 * > operator[] - This operator is used to access the element at a particular index in the array
 * > operator* - Pointer operator for the Iterator1D class
 * > operator++ - The prefix increment operator for the Iterator1D class
 * > operator++(int) - The postfix increment operator for the Iterator1D class
 * > operator-- - The prefix decrement operator for the Iterator1D class
 * > operator--(int) - The prefix decrement operator for the Iterator1D class
 * > operator== - Comparator operator for the Iterator1D class
 * > operator!= - Negated comparator operator for the Iterator1D class
 * > operator= - Assignment operator for the Iterator1D class
 * > ReachedEnd() - This method is used to check if the iterator has reached the end of the array.
 * > AtBeginning() - This method is use to check if the iterator is at the beginning of the array.
*/
template <class T>
class Iterator1D
{
private:
	T* _array;
	int _size;
	int _index;

	/**
	 * @brief This function facilitate forward traversal within the 1D array.
	*/
	void MoveNext()
	{
		// increment the index and return the object at the new position
		++_index;
		if (_index >= _size)
		{
			// Reached the end of the array, so reset the index to the beginning
			_index = 0;
		}
	}

	/**
	 * @brief This function facilitate backward traversal within the 1D array.
	*/
	void MovePrevious()
	{
		// decrement the index and return the object at the new position
		--_index;
		if (_index < 0)
		{
			// Reached the beginning of the array, so reset the index to the end
			_index = _size - 1;
		}
	}


public:
	/**
	 * @brief This is the default constructor for the Iterator1D class.
	*/
	Iterator1D()
	{
		_array = nullptr;
		_size = 0;
		_index = 0;
	}

	/**
	 * @brief This is the overloaded constructor for the Iterator1D class.
	 * @param array - the array to be iterated over
	 * @param size - the size of the array
	*/
	Iterator1D(T* array, int size)
	{
		_array = array;
		_size = size;
		_index = 0;
	}

	/**
	 * @brief The copy constructor for the Iterator1D class.
	 * @param iterator - the iterator to be copied
	*/
	Iterator1D(const Iterator1D& iterator)
	{
		_array = iterator._array;
		_size = iterator._size;
		_index = iterator._index;
	}

	/**
	 * @brief The destructor for the Iterator1D class.
	*/
	~Iterator1D()
	{
		_array = nullptr;
		_size = 0;
		_index = 0;
	}

	/**
	 * @brief The Getter for the Iterator1D array field
	 * @return a pointer to the array
	*/
	T* GetArray() const
	{
		return _array;
	}

	/**
	 * @brief The Getter for the Iterator1D size field
	 * @return an integer representing the size of the array
	*/
	int GetSize() const
	{
		return _size;
	}

	/**
	 * @brief The Getter for the Iterator1D index field
	 * @return an integer representing the index of the current element in the array
	*/
	int GetIndex() const
	{
		return _index;
	}

	/**
	 * @brief Setter for the Iterator1D array field
	 * @param array - the array to be iterated over
	*/
	void SetArray(T* array)
	{
		_array = array;
	}

	/**
	 * @brief Setter for the Iterator1D size field
	 * @param size - The size of the array
	*/
	void SetSize(int size)
	{
		_size = size;
	}

	/**
	 * @brief Setter for the Iterator1D index field
	 * @param index - the index of the current element in the array
	*/
	void SetIndex(int index)
	{
		_index = index;
	}

	/**
	 * @brief This method is used to get the current item in the array
	 * @return a element T representing the current item in the array
	*/
	T& GetCurrentItem()
	{
		return _array[_index];
	}

	/**
	 * @brief The range-based for loop begin method for the Iterator1D class
	 * @return an iterator to the first element in the array
	*/
	Iterator1D begin()
	{
		_index = 0;
		return *this;
	}

	/**
	 * @brief The range-based for loop end method for the Iterator1D class
	 * @return an iterator to the last element in the array
	*/
	Iterator1D end()
	{
		_index = _size;
		return *this;
	}

	/**
	 * @brief This operator is used to access the element at a particular index in the array
	 * @param index - The index of the element to be accessed
	 * @return a reference to the element at the specified index
	*/
	T& operator[](int index) const
	{
		return _array[index];
	}

	/**
	 * @brief Pointer operator for the Iterator1D class
	 * @return the reference to the current element in the array
	*/
	const T& operator*() const
	{
		return _array[_index];
	}

	/**
	 * @brief The prefix increment operator for the Iterator1D class
	 * @return reference to the current element in the array which has been incremented
	*/
	Iterator1D& operator++()
	{
		// increment the index and return the object at the new position
		MoveNext();
		return *this;
	}

	/**
	 * @brief The postfix increment operator for the Iterator1D class
	 * @return previous element in the array
	*/
	Iterator1D operator++(int)
	{
		Iterator1D temp(*this); // copy the current object
		MoveNext(); // increment the index
		return temp;
	}

	/**
	 * @brief The prefix decrement operator for the Iterator1D class
	 * @return reference to the current element in the array which has been decremented
	*/
	Iterator1D& operator--()
	{
		// decrement the index and return the object at the new position
		MovePrevious();
		return *this;
	}

	/**
	 * @brief The prefix decrement operator for the Iterator1D class
	 * @param int - iterator to be decremented
	 * @return previous element in the array
	*/
	Iterator1D operator--(int)
	{
		Iterator1D temp(*this);
		MovePrevious();
		return temp;
	}

	/**
	 * @brief Comparator operator for the Iterator1D class
	 * @param rightHandSide - the item to compare the iterator to
	 * @return a boolean value representing whether the iterator is equal to the item
	*/
	bool operator==(const Iterator1D& rightHandSide) const
	{
		return _array == rightHandSide._array && _size == rightHandSide._size && _index == rightHandSide._index;
	}

	/**
	 * @brief Negated comparator operator for the Iterator1D class
	 * @param rightHandSide - the item to compare the iterator to
	 * @return a boolean value representing whether the iterator is not equal to the item
	*/
	bool operator!=(const Iterator1D& rightHandSide) const
	{
		return !(*this == rightHandSide);
	}

	/**
	 * @brief Assignment operator for the Iterator1D class
	 * @param rightHandSide - the iterator to be assigned to the current iterator
	 * @return reference to the current iterator
	*/
	Iterator1D& operator=(const Iterator1D& rightHandSide)
	{
		if (this != &rightHandSide)
		{
			_array = rightHandSide._array;
			_size = rightHandSide._size;
			_index = rightHandSide._index;
		}
		return *this;
	}

	/**
	 * @brief This method is used to check if the iterator has reached the end of the array.
	 * @return a boolean value representing whether the iterator has reached the end of the array
	*/
	bool ReachedEnd() const
	{
		return _index >= _size - 1;
	}

	/**
	 * @brief This method is use to check if the iterator is at the beginning of the array.
	 * @return a boolean value representing whether the iterator is at the beginning of the array
	*/
	bool AtBeginning() const
	{
		return _index <= 0;
	}

};
