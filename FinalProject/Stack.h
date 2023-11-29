#pragma once
#include "QueueNode.h"
#include <iostream>

/**
 * @file Stack.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file defins the Stack class which is a template Data Structure and
 * accepts different types which are contained in a QueueNode template class.
 *
 * Properties:
 * -----------
 * > _top: QueueNode<T>* - The node at the top of the stack
 * > _size: int - The size of the stack
 * > _maxsize: int - This is the expected maximum size of teh Stack data Structure
 *
 * Methods:
 * --------
 * > Stack() - This is the default constructor of the Stack class
 * > Stack(QueueNode<T>* top) - This is the overloaded constructor of the Stack that only
 * accepts the top node to the stack
 * > Stack(QueueNode<T>* top, int maxSize) - This is the overloaded constructor of the Stack
 * that takes in both the first node and the maximum size of the stack
 * > ~Stack() - This is the default destructor of the stack class
 * > Push() - This function adds items to the top of the stack
 * > Pop() - This function removes items from the top of the stack
 * > Peek() - This function returns the item at the top of the stack
 * > Purge() - This function removes all items from the stack
 * > Size() - This function return the size of the entire Stack
 */
template <class T>
class Stack
{
private:
	QueueNode<T>* _top;
	int _size;
	int _maxsize;

public:
	/**
	 * @brief This is the default constructor of the Stack class.
	*/
	Stack()
	{
		_top = new QueueNode<T>();
		_size = 0;
		_maxsize = 20;
	}

	/**
	 * @brief This is the overloaded constructor of the Stack class that accepts
	 * jus the top node
	 * @param top - This is the top Node of the Stack class.
	*/
	Stack(QueueNode<T>* top)
	{
		_top = top;
		_size = 1;
		_maxsize = 20;
	}

	/**
	 * @brief This is the overloaded constructor of the Stack class that accepts
	 * both the top Node and the maximum size of the Stack.
	 * @param top - This is the top Node of the class.
	 * @param maxSize - This is the maximum size of the Stack class.
	*/
	Stack(QueueNode<T>* top, int maxSize)
	{
		_top = top;
		_size = 1;
		_maxsize = maxSize;
	}

	/**
	 * @brief This is the default destructor of the Stack class.
	*/
	~Stack()
	{
		if (IsEmpty())
		{
			delete _top;
		}
		else
		{
			Purge();
		}
	}
	/**
	 * @brief This function is used to overload the * operator to return the stack
	 * @return a pointer to the stack
	*/
	const QueueNode<T>& operator*()
	{
		return *_top;
	}

	/**
	 * @brief This function is used to add items into the stack and updating the
	 * value of the top node to the most recently inserted node.
	 * @param item - This is the node to be added to the stack
	*/
	void Push(QueueNode<T>* item)
	{
		if (_size < _maxsize)
		{
			item->SetNext(_top);
			_top = item;
			_size++;
		}
		else
		{
			throw std::out_of_range("Stack is full");
		}
	}

	/**
	 * @brief This function removes the top-most node from the stack usign the
	 * Last In First Out (LIFO) rule.
	*/
	void Pop()
	{
		if (_size > 0)
		{
			QueueNode<T>* temp = _top;
			_top = _top->GetNext();
			delete temp;
			_size--;
		}
		else
		{
			throw std::out_of_range("Stack is empty");
		}
	}

	/**
	 * @brief This function returns the top-most node in the stack
	 * @return a pointer to a QueueNode of type T which is the top-most node in the stack
	*/
	QueueNode<T>* Peek()
	{
		if (_size > 0)
		{
			return _top;
		}
		throw std::out_of_range("Stack is empty");
	}

	/**
	 * @brief This function removes all content from the Stack making it empty
	*/
	void Purge()
	{
		QueueNode<T>* temp = _top;
		while (temp != new QueueNode<T>())
		{
			_top = _top->GetNext();
			delete temp;
			temp = _top;
		}
		_size = 0;
	}

	/**
	 * @brief This function is used to check the size of the stack 
	 * @return an integer representing the number of items in teh stack
	*/
	int Size() const
	{
		return _size;
	}

	/**
	 * @brief This function is used to check whether the Stack is empty or not
	 * @return a boolean value representing whether the stack is empty or not
	*/
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	 * @brief This function is used to check whether or not the stack is full
	 * @return a boolean value representing whether or not the stack is full
	*/
	bool IsFull() const
	{
		return _size == _maxsize;
	}


};