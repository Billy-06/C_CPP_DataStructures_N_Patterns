#pragma once
#include "QueueNode.h"
#include <vector>
#include <cstdlib>
#include  <algorithm>
#include "Tile.h"

/**
 * @file UniDirectionalList.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the UniDirectionalList class which is
 * to be used as a single linked list through the program for different custom classes.
 *
 * Properties:
 * -----------
 * > _firstNode: QueueNode<T>* - pointer to the first node in the list
 * > _lastNode: QueueNode<T>* - pointer to the last node in the list
 * > _size: int - the number of nodes in the list
 *
 * Methods:
 * --------
 * > UniDirectionalList() - This is the default constructor of the UniDirectionalList class
 * > UniDirectionalList(QueueNode<T>* firstNode) - This is the overloaded constructor of the UniDirectionalList class.
 * > ~UniDirectionalList() - This is the destructor of the UniDirectionalList class.
 * > Append(QueueNode<T>* newNode) - This method appends a new node to the end of the list.
 * > Prepend(QueueNode<T>* newNode) - This method prepends a new node to the beginning of the list.
 * > Insert(QueueNode<T>* newNode, int index) - This method inserts a new node at a specified index in the list.
 * > Remove(int index) - This method removes a node at a specified index in the list.
 * > Pop() - This method removes the last node in the list.
 * > Shuffle() - This method shuffles the nodes in the list.
 * > GetMaxValue() - This method returns the maximum value in the list.
 * > GetMinValue() - This method returns the minimum value in the list.
 * > Size() - This method returns the size of the list.
 *
 */
template <class T>
class UniDirectionalList
{
private:
	QueueNode<T>* _firstNode;
	QueueNode<T>* _lastNode;
	int _size;

public:
	/**
	 * @brief This is the default constructor of the UniDirectionalList class.
	*/
	UniDirectionalList()
	{
		_firstNode = new QueueNode<T>();
		_lastNode = _firstNode;
		_size = 0;
	}

	/**
	 * @brief This is the overloaded constructor to the UniDirectionalList class.
	 * @param firstNode - the desired first node of the list.
	*/
	UniDirectionalList(QueueNode<T>* firstNode)
	{
		_firstNode = firstNode;
		_lastNode = _firstNode;
		_size = 1;
	}

	/**
	 * @brief This is the destructor of the UniDirectionalList class.
	*/
	~UniDirectionalList()
	{
		QueueNode<T>* currentNode = _firstNode;
		QueueNode<T>* nextNode = _firstNode->GetNext();
		while (nextNode != nullptr)
		{
			delete currentNode;
			currentNode = nextNode;
			nextNode = nextNode->GetNext();
		}
		delete currentNode;
	}

	/**
	 * @brief This function is used for dereferencing the list.
	 * @return a pointer to the first node in the list.
	*/
	const QueueNode<T>& operator*()
	{
		return *_firstNode;
	}

	/**
	 * @brief This function is used for adding the QueueNode to the end of the list.
	 * @param newNode - the node to be added to the end of the list.
	*/
	void Append(QueueNode<T>* newNode)
	{
		_lastNode->SetNext(newNode);
		_lastNode = newNode;
		_size++;
	}

	/**
	 * @brief This function is used for adding the QueueNode to the beginning of the list.
	 * @param newNode - the node to be added to the beginning of the list.
	*/
	void Prepend(QueueNode<T>* newNode)
	{
		QueueNode<T>* temp = _firstNode;
		newNode->SetNext(temp);
		_firstNode = newNode;
		_size++;
	}

	/**
	 * @brief This function is used for adding Nodes at specific positions in the list.
	 * @param newNode - the node to be added to the list.
	 * @param index - the position at which the node is to be added.
	*/
	void Insert(QueueNode<T>* newNode, int index)
	{
		if (index == 0)
		{
			Prepend(newNode);
			return;
		}
		if (index == _size)
		{
			Append(newNode);
			return;
		}
		QueueNode<T>* currentNode = _firstNode;
		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->GetNext();
		}
		QueueNode<T>* temp = currentNode->GetNext();
		currentNode->SetNext(newNode);
		newNode->SetNext(temp);
		_size++;
	}

	/**
	 * @brief This function is used for removing Nodes at specific positions in the list.
	 * @param index - The position from which the node is to be removed.
	*/
	void Remove(int index)
	{
		if (index == 0)
		{
			Pop();
			return;
		}
		if (index == _size - 1)
		{
			QueueNode<T>* currentNode = _firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				currentNode = currentNode->GetNext();
			}
			delete currentNode->GetNext();

			currentNode->SetNext(new QueueNode<T>());
			_lastNode = currentNode;
			_size--;
		}
		else
		{
			QueueNode<T>* currentNode = _firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				currentNode = currentNode->GetNext();
			}
			QueueNode<T>* temp = currentNode->GetNext();
			currentNode->SetNext(temp->GetNext());
			delete temp;

			_size--;
		}
	}

	/**
	 * @brief This function is used for removing the last node in the list.
	*/
	void Pop()
	{
		QueueNode<T>* temp = _firstNode;
		_firstNode = _firstNode->GetNext();
		delete temp;
	}

	/**
	 * @brief This function is used for shuffling the nodes in the list.
	*/
    void Shuffle() {
        std::vector<QueueNode<T>*> nodes;
        QueueNode<T>* currentNode = _firstNode;
        while (currentNode != nullptr) {
            nodes.push_back(currentNode);
            currentNode = currentNode->GetNext();
        }
        std::random_shuffle(nodes.begin(), nodes.end());
        _firstNode = nodes[0];
        _lastNode = nodes[nodes.size() - 1];
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->SetNext(nodes[i + 1]);
        }
        nodes[nodes.size() - 1]->SetNext(nullptr);
    }

	/**
	 * @brief Getter for getting the first node in the list.
	 * @return a pointer to the first node in the list.
	*/
	QueueNode<T>* GetFirstNode()
	{
		return _firstNode;
	}

	/**
	 * @brief Setter for the first node in the list.
	 * @param firstNode - the desired first node in the list.
	*/
	void SetFirstNode(QueueNode<T>* firstNode)
	{
		_firstNode = firstNode;
	}

	/**
	 * @brief Getter for getting the last node in the list.
	 * @return a pointer to the last node in the list.
	*/
	QueueNode<T>* GetLastNode()
	{
		return _lastNode;
	}

	/**
	 * @brief Setter for the last node in the list.
	 * @param lastNode - the desired last node in the list.
	*/
	void SetLastNode(QueueNode<T>* lastNode)
	{
		_lastNode = lastNode;
	}

	/**
	 * @brief Getter for getting the size of the list.
	 * @return an integer representing the size of the list.
	*/
	int GetSize() const
	{
		return _size;
	}

};