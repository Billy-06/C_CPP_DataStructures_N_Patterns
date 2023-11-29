#pragma once
#include "QueueNode.h"
#include "Tile.h"

/**
 * @file Queue.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file defines the Queue class which is to be used in creating the
 * 2D Map in the TileSpace class. The queue allows seamlessly linking of the previous row
 * to the respective tiles in the row below it. The queue can also be used with other types
 *
 * Properties:
 * -----------
 * > _first: QueueNode<T>*  - This is the first element in the queue.
 * > _last: QueueNode<T>* - This is the last element in the queue.
 * > _size: int - This is the number of elements in the queue.
 *
 * Methods:
 * --------
 * > Queue() - This is the default constructor for the Queue class.
 * > Queue(QueueNode<T>* first) - This is the overloaded constructor for the Queue class.
 * > Queue(QueueNode<T>* first, int maxsize) - This is the overloaded constructor for the Queue class that
 * takes in a max size of the queue.
 * > ~Queue() - This is the destructor to the Queue
 * > Peek() - This function returns the first element in the queue.
 * > Pop() - This function removes the first element from the queue.
 * > Push(QueueNode<T>* element) - This function adds an element to the queue.
 * > Purge() - This method removes all elements from the queue.
 * > IsEmpty() - This function returns a boolean value indicating whether the queue is empty or not.
 * > IsFull() - This function returns a boolean value indicating whether the queue is full or not.
 * > Size() - This function returns the number of elements in the queue.
 */
template <class T>
class Queue
{
private:
	QueueNode<T>* _first;
	QueueNode<T>* _last;
	int _size;
	int _maxsize;

public:
	/**
	 * @brief This is the default constructor for the Queue class.
	*/
	Queue()
	{
		Tile* sentinel = Sentinel;
		_first = new QueueNode<Tile>(sentinel);
		_last = _first;
		_size = 0;
		_maxsize = 50;
	}

	/**
	 * @brief This is the overloaded constructor for the Queue class.
	 * @param first - This is the first element in the queue.
	*/
	Queue(QueueNode<T>* first)
	{
		_first = first;
		_last = first;
		_size = 1;
		_maxsize = 50;
	}

	/**
	 * @brief This is the overloaded constructor for the Queue class, it accepts a
	 * maxsize against which to check if the queue is full.
	 * @param first - This is the first element in the queue.
	 * @param maxsize - This is the maximum size of the queue.
	*/
	Queue(QueueNode<T>* first, int maxsize)
	{
		_first = first;
		_last = _first;
		_size = 2;
		_maxsize = maxsize;
	}

	/**
	 * @brief This is the destructor to the Queue
	*/
	~Queue() = default;

	/**
	 * @brief This operator overloading allows the Queue to be used as a pointer.
	*/
	const Queue<T>& operator*()
	{
		return *this;
	}

	/**
	 * @brief This function returns the first element in the queue.
	 * @return the first element in the queue.
	*/
	QueueNode<T>* Peek()
	{
		return _first;
	}


	/**
	 * @brief This function returns the last element in the queue.
	 * @return the last element in the queue.
	*/
	QueueNode<T>* GetLast()
	{
		return _last;
	}

	/**
	 * @brief This function removes the first element from the queue.
	*/
	void Pop()
	{
		QueueNode<T>* temp = _first;
		_first = _first->GetNext();
		delete temp;
		--_size;
	}

	/**
	 * @brief This function adds an element to the queue.
	 * @param element - This is the element to be added to the queue.
	*/
	void Push(QueueNode<T>* element)
	{
		_last->SetNext(element);
		_last = element;
		++_size;
	}

	/**
	 * @brief This function returns a boolean value indicating whether the queue is empty or not.
	 * @return a boolean value indicating whether the queue is empty or not.
	*/
	bool IsEmpty() const
	{
		if (_first->_item == nullptr || _first->_item->GetPosition()->x == -1 || _size == 0)
		{
			return true;
		}

		return false;
	}


	/**
	 * @brief This function returns a boolean value indicating whether the queue is full or not.
	 * @return a boolean value indicating whether the queue is full or not.
	*/
	bool IsFull() const
	{
		if (_size == _maxsize)
		{
			return true;
		}

		return false;
	}

	/**
	 * @brief This function returns the number of elements in the queue.
	 * @return the number of elements in the queue.
	*/
	int Size() const
	{
		return _size;
	}

	/**
	 * @brief This method prints the entire queue.
	*/
	void PrintQueue() const
	{
		QueueNode<T>* temp = _first;
		while (temp != nullptr)
		{
			temp->PrintNode();
			temp = temp->GetNext();
		}
	}

	/**
	 * @brief This method removes all elements from the queue.
	*/
	void Purge()
	{
		QueueNode<T>* temp = _first;
		while (temp != nullptr)
		{
			_first = _first->GetNext();
			delete temp;
			temp = _first;
		}
		_size = 0;
	}
};
