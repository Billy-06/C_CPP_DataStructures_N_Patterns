#pragma once
#include "QueueNode.h"
#include <iostream>
/**
 * @file BidirectionalList.h
 * @author Billy Ndegwah Micah
 *
 * Description: This is a bidirectional list class that inherits from the QueueNode class.
 * This object represent a double linked list that can be used to store custom template classes.
 *
 * Properties:
 * -----------
 * > _firstNode: DoubleQueueNode<T>* - pointer to the first node in the list
 * > _lastNode: DoubleQueueNode<T>* - pointer to the last node in the list
 * > _size: int - the number of nodes in the list
 *
 * Methods:
 * --------
 * > BidirectionalList() - This is the default constructor of the BidirectionalList class.
 * > BidirectionalList(DoubleQueueNode<T>* newNode) - This is the overloaded constructor of the BidirectionalList class.
 * > ~BidirectionalList() - This is the destructor of the BidirectionalList class.
 * > Append(DoubleQueueNode<T>* newNode) - This method appends a new node to the end of the list.
 * > Prepend(DoubleQueueNode<T>* newNode) - This method prepends a new node to the beginning of the list.
 * > Insert(DoubleQueueNode<T>* newNode, int index) - This method inserts a new node at a specified index in the list.
 * > Remove(int index) - This method removes a node at a specified index in the list.
 * > Pop() - This method removes the last node in the list.
 * > Shuffle() - This method shuffles the nodes in the list.
 * > GetMaxValue() - Getter method for the maximum value in the list.
 * > GetMinValue() - Getter method for the minimum value in the list.
 * > Size() - Getter method for the size of the list.
 */
template <class T>
class BidirectionalList
{
private:
	DoubleQueueNode<T>* _firstNode;
	DoubleQueueNode<T>* _lastNode;
	int _size;

public:
	/**
	 * @brief This is the default constructor of the BidirectionalList class.
	*/
	BidirectionalList()
	{
		_firstNode = new DoubleQueueNode<T>();
		_lastNode = _firstNode;
		_size = 0;
	}
	/**
	 * @brief This is the overloaded constructor of the BidirectionalList class.
	 * @param newNode - pointer to the first node in the list
	*/
	BidirectionalList(DoubleQueueNode<T>* newNode)
	{
		_firstNode = newNode;
		_lastNode = _firstNode;
		_size = 1;
	}
	/**
	 * @brief This is the destructor of the BidirectionalList class.
	*/
	~BidirectionalList()
	{
		DoubleQueueNode<T>* currentNode = _firstNode;
		while (currentNode != DoubleQueueNode<T>::NIL)
		{
			DoubleQueueNode<T>* nextNode = currentNode->GetNext();
			delete currentNode;
			currentNode = nextNode;
		}
	}

	/**
	 * @brief This method overloads the dereference operator.
	 * @return a pointer to the first node in the list
	*/
	const DoubleQueueNode<T>& operator*()
	{
		return *_firstNode;

	}

	/**
	 * @brief This method appends a new node to the end of the list.
	 * @param newNode - pointer to the new node to be appended
	*/
	void Append(DoubleQueueNode<T>* newNode)
	{
		if (_firstNode == new DoubleQueueNode<T>())
		{
			_firstNode = newNode;
		}
		else
		{
			_lastNode->SetNext(newNode);
			_lastNode = newNode;
		}
	}
	/**
	 * @brief This method prepends a new node to the beginning of the list.
	 * @param newNode - pointer to the new node to be prepended
	*/
	void Prepend(DoubleQueueNode<T>* newNode)
	{
		if (_firstNode == new DoubleQueueNode<T>())
		{
			_firstNode = newNode;
		}
		else
		{
			newNode->SetNext(_firstNode);
			_firstNode = newNode;
		}
	}
	/**
	 * @brief This method inserts a new node at a specified index in the list.
	 * @param newNode - pointer to the new node to be inserted
	 * @param index - the index at which the new node is to be inserted
	*/
	void Insert(DoubleQueueNode<T>* newNode, int index)
	{
		if (index == 0)
		{
			Prepend(newNode);
		}
		else if (index == _size)
		{
			Append(newNode);
		}
		else
		{
			DoubleQueueNode<T>* currentNode = _firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				currentNode = currentNode->GetNext();
			}
			newNode->SetNext(currentNode->GetNext());
			currentNode->SetNext(newNode);

		}
	}
	/**
	 * @brief This method removes a node at a specified index in the list.
	 * @param index - the index at which the node is to be removed
	*/
	void Remove(int index)
	{
		if (index == 0)
		{
			DoubleQueueNode<T>* tempNode = _firstNode;
			_firstNode = _firstNode->GetNext();

			delete tempNode;
		}
		else
		{
			DoubleQueueNode<T>* currentNode = _firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				currentNode = currentNode->GetNext();
			}
			DoubleQueueNode<T>* tempNode = currentNode->GetNext();
			currentNode->SetNext(tempNode->GetNext());

			delete tempNode;
		}
	}
	/**
	 * @brief This method removes the last node in the list.
	*/
	void Pop()
	{
		DoubleQueueNode<T>* currentNode = _firstNode;
		while (currentNode->GetNext() != _lastNode)
		{
			currentNode = currentNode->GetNext();
		}
		DoubleQueueNode<T>* tempNode = _lastNode;
		_lastNode = currentNode;
		_lastNode->SetNext(new DoubleQueueNode<T>());

		delete tempNode;
	}
	/**
	 * @brief This method shuffles the nodes in the list.
	*/
	void Shuffle()
	{
		DoubleQueueNode<T>* currentNode = _firstNode;
		DoubleQueueNode<T>* nextNode = currentNode->GetNext();
		DoubleQueueNode<T>* tempNode = new DoubleQueueNode<T>();
		for (int i = 0; i < _size; i++)
		{
			int randomIndex = rand() % _size;
			for (int j = 0; j < randomIndex; j++)
			{
				currentNode = currentNode->GetNext();
			}
			tempNode->SetValue(currentNode->GetValue());
			currentNode->SetValue(nextNode->GetValue());
			nextNode->SetValue(tempNode->GetValue());
			currentNode = _firstNode;
			nextNode = currentNode->GetNext();
		}
		delete tempNode;
	}

	/**
	 * @brief Getter method for the first node in the list.
	 * @return pointer to the first node in the list
	*/
	DoubleQueueNode<T>* GetFirstNode()
	{
		return _firstNode;
	}
	/**
	 * @brief Getter method for the last node in the list.
	 * @return pointer to the last node in the list
	*/
	DoubleQueueNode<T>* GetLastNode()
	{
		return _lastNode;
	}
	/**
	 * @brief Getter method for the size of the list.
	 * @return an integer representing the size of the list
	*/
	int GetSize() const
	{
		return _size;
	}
};