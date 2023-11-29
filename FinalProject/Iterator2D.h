#pragma once
#include "Tile.h"
/**
 * @file Iterator2D.h
 * @author Billy Ndegwah Micah
 * @brief This is an iterator designed to iterate over the 2D array passed to it. It'll
 * be used in helping the player access tools an item in a like manner as an inventory.
 *
 * Properties:
 * -----------
 * > _array: T** - This is the 2D array to be iterated over.
 * > _rows: int - This is the number of rows in the 2D array.
 * > _cols: int - This is the number of columns in the 2D array.
 * > _i: int - This is the current row in the 2D array.
 * > _j: int - This is the current column in the 2D array.
 *
 * Methods:
 * --------
 * > Iterator2D() - This is the default constructor for the 2D array iterator.
 * > Iterator2D(T** array, int rows, int cols) - This is the overloaded constructor for the 2D array
 * iterator.
 * > Iterator2D(const Iterator2D& other) - Copy constructor for the 2D array iterator.
 * > ~Iterator2D() - The destructor for the 2D Iterator, to free up memory.
 *
 * > MoveNext() - This function facilitate forward traversal within the 2D array.
 * > MovePrevious() - This function facilitate backward traversal within the 2D array.
 * > StartPoint() - This function resets the iterator to the start of the 2D array.
 * > EndPoint() - This function resets the iterator to the end of the 2D array.
 * > begin() - This is the range-based begin iterator overload for the 2D array iterator.
 * > end() - This is the range-based end iterator overload for the 2D array iterator.
 * > Getters and Setters - These are the getters and setters for the 2D array iterator's properties.
 * > GetCurrentRow() - This method returns the current row in the 2D array.
 * > GetCurrentColumn() - The method returns the current column in the 2D array.
 * > GetCurrentItem() - This method returns the current item in the 2D array.
 * > SetCurrentItem(T* item) - This method sets the current item in the 2D array.
 * > MoveTo(int i, int j) - This method allows the iterator to move to a specific position in the array.
 * > operator*() - The operator overload for the 2D array Iterator's pointer operator.
 * > operator++() - The operator overload for the 2D array Iterator's post-increment operator.
 * > operator++(int) - The operator overload for the 2D array Iterator's pre-increment operator.
 * > operator+=(int n) - The operator overload for the 2D array Iterator's addition operator.
 * > operator--() - The operator overload for the 2D array Iterator's post-decrement operator.
 * > operator--(int) - The operator overload for the 2D array Iterator's pre-decrement operator.
 * > operator-=(int n) - The operator overload for the 2D array Iterator's subtraction operator.
 * > operator==(const Iterator2D& other) - The operator overload for the 2D array Iterator's comparator
 * operator.
 * > operator!=(const Iterator2D& other) - The operator overload for the 2D array Iterator's negation
 * comparator operator.
 * > ReachedEnd() - This method is used to check if the iterator has reached the end of the array.
 * > AtBeginning() - This method is use to check if the iterator is at the beginning of the array.
*/
template <class T>
class Iterator2D
{
private:
	T** _array;
	int _rows;
	int _cols;
	int _i = 0, _j = 0;

	/**
	 * @brief This function facilitate forward traversal within the 2D array.
	*/
	void MoveNext()
	{
		if (_i < _rows && _j <= _cols)
		{
			if (_j == _cols)
			{
				// if at the end of the row, go to the next row
				_j = 0;
				++_i;

				if (_i == _rows)
				{
					// if at the end of the array, go to the beginning of the array
					_i = 0;
					_j = 0;
				}
			}
			else
			{
				// increment the current iterator
				++_j;
			}
		}
	}

	/**
	 * @brief This function facilitate backward traversal within the 2D array.
	*/
	void MovePrevious()
	{
		// decrement the current iterator
		if (_j > 0 || _i > 0)
		{
			--_j;
		}
		else if (_j <= 0 || _i <= 0)
		{
			// if at the beginning of the row, go to the previous row
			_j = _cols - 1;
			--_i;
			if (_i < 0)
			{
				// if at the beginning of the array, go to the end of the array
				_i = _rows - 1;
				_j = _cols - 1;
			}
		}
	}

	/**
	 * @brief This function resets the iterator to the start of the 2D array.
	 * It is used inside the begin function.
	*/
	void StartPoint()
	{
		// move the current iterator to the beginning of the array
		_i = 0;
		_j = 0;
	}

	/**
	 * @brief This function resets the iterator to the end of the 2D array.
	 * It is used inside the end function.
	*/
	void EndPoint()
	{
		// move the current iterator to the end of the array
		_i = _rows - 1;
		_j = _cols - 1;
	}

public:
	int Size;

	/**
	 * @brief This is the default constructor for the 2D array iterator.
	*/
	Iterator2D() : _array(nullptr), _rows(0), _cols(0)
	{
		Size = 0;
	}

	/**
	 * @brief This is the overloaded constructor for the 2D array iterator.
	 * @param array - This is the 2D array to be iterated over.
	 * @param rows - This is the number of rows in the 2D array.
	 * @param cols - This is the number of columns in the 2D array.
	*/
	Iterator2D(T** array, int rows, int cols) :
		_array(array), _rows(rows), _cols(cols)
	{
		Size = rows * cols;
	}

	/**
	 * @brief Copy constructor for the 2D array iterator.
	 * @param other - This is the 2D array iterator to be copied.
	 * @return a copy of the 2D array iterator.
	*/
	Iterator2D(const Iterator2D& other)
	{
		// copy the other iterator
		_array = other._array;
		_rows = other._rows;
		_cols = other._cols;
		_i = other._i;
		_j = other._j;
		Size = other.Size;
	}

	/**
	 * @brief The destructor for the 2D Iterator, to free up memory.
	*/
	~Iterator2D() = default;
	//{
		// delete the array
		// delete[] _array;
	//}

	/**
	 * @brief The range-based begin iterator overload for the 2D array iterator.
	 * @return an iterator pointing to the first item in the 2D array.
	*/
	Iterator2D begin()
	{
		StartPoint();
		return *this;
	}

	/**
	 * @brief The range-based end iterator overload for the 2D array iterator.
	 * @return an iterator pointing to the last item in the 2D array.
	*/
	Iterator2D end()
	{
		EndPoint();
		return *this;
	}

	/**
	 * @brief The getter for the 2D array.
	 * @return a pointer to the 2D array's first item.
	*/
	T** GetArray() const
	{
		return _array;
	}

	/**
	 * @brief The setter for the 2D array.
	 * @param array - This is the 2D array to be iterated over.
	*/
	void SetArray(T** array)
	{
		_array = array;
	}

	/**
	 * @brief The getter for the number of rows in the 2D array.
	 * @return an integer representing the number of rows in the 2D array.
	*/
	int GetRows() const
	{
		return _rows;
	}

	/**
	 * @brief The setter for the number of rows in the 2D array.
	 * @param rows - an integer representing the number of rows in the 2D array.
	*/
	void SetRows(int rows)
	{
		_rows = rows;
	}


	/**
	 * @brief The getter for the number of columns in the 2D array.
	 * @return an integer representing the number of columns in the 2D array.
	*/
	int GetCols() const
	{
		return _cols;
	}


	/**
	 * @brief Setter for the number of columns in the 2D array.
	 * @param cols - an integer representing the number of columns in the 2D array.
	*/
	void SetCols(int cols)
	{
		_cols = cols;
	}

	/**
	 * @brief This method returns the current row in the 2D array.
	 * @return an integer representing the current row in the 2D array.
	*/
	int GetCurrentRow() const
	{
		return _i;
	}

	/**
	 * @brief The method returns the current column in the 2D array.
	 * @return an integer representing the current column in the 2D array.
	*/
	int GetCurrentColumn() const
	{
		return _j;
	}

	/**
	 * @brief This method returns the current item in the 2D array.
	 * @return a element T representing the current item in the 2D array.
	*/
	T GetCurrentItem() const
	{
		// _array[_i][_j].PrintTile();
		// Tile* item =  new Tile(_i, _j);
		// return *item;
		return _array[_i][_j];
	}

	/**
	 * @brief This method sets the current item in the 2D array.
	 * @param item - a string representing the current item in the 2D array.
	*/
	void SetCurrentItem(T* item) const
	{
		_array[_i][_j] = item;
	}

	/**
	 * @brief This method allows the iterator to move to a specific position in the array.
	 * @param i - the row to move to.
	 * @param j - the column to move to.
	*/
	void MoveTo(int i, int j)
	{
		// move the current iterator to the specified position
		_i = i;
		_j = j;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's pointer operator.
	*/
	int operator*() const
	{
		return **_array;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's post-increment operator.
	*/
	Iterator2D& operator++()
	{
		// increment the current iterator and return it
		MoveNext();
		return *this;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's pre-increment operator.
	*/
	Iterator2D operator++(int)
	{
		// create a copy of the current iterator
		Iterator2D<T> temp(*this);
		// increment the current iterator
		MoveNext();

		// return the old value
		return temp;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's addition operator.
	*/
	Iterator2D& operator+=(int n)
	{
		// increment the current iterator by n and return it
		for (int i = 0; i < n; i++)
		{
			MoveNext();
		}
		return *this;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's post-decrement operator.
	*/
	Iterator2D& operator--()
	{
		// decrement the current iterator and return it
		MovePrevious();
		return *this;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's pre-decrement operator.
	*/
	Iterator2D operator--(int)
	{
		// create a copy of the current iterator
		Iterator2D temp(*this);
		// decrement the current iterator
		MovePrevious();
		// return the old value
		return temp;
	}

	/** 
	 * @brief The operator overload for the 2D array Iterator's subtraction operator.
	*/
	Iterator2D& operator-=(int n)
	{
		// decrement the current iterator by n and return it
		for (int i = n; i > 0; i--)
		{
			MovePrevious();
		}
		return *this;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's comparator operator.
	*/
	bool operator==(const Iterator2D& other) const
	{
		// return true if the current iterator is equal to the other iterator
		return _array == other._array && _rows == other._rows && _cols == other._cols;
	}

	/**
	 * @brief The operator overload for the 2D array Iterator's negation comparator operator.
	*/
	bool operator!=(const Iterator2D& other) const
	{
		// return true if the current iterator is not equal to the other iterator
		return _array != other._array || _rows != other._rows || _cols != other._cols;
	}

	/**
	 * @brief This method is used to check if the iterator has reached the end of the array.
	 * @return a boolean value representing whether the iterator has reached the end of the array
	*/
	bool ReachedEnd() const
	{
		// return true if the current iterator is at the end of the array
		return _i == _rows - 1 && _j == _cols - 1;
	}

	/**
	 * @brief This method is use to check if the iterator is at the beginning of the array.
	 * @return a boolean value representing whether the iterator is at the beginning of the array
	*/
	bool AtBeginning() const
	{
		// return true if the current iterator is at the beginning of the array
		return _i == 0 && _j == 0;
	}

};
