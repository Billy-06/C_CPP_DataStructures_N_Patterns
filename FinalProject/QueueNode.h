#pragma once
#include "Tile.h"
/**
 * @file Queue.h
 * @author Billy Ndegwah Micah
 *
 * Custom Type to contain the Tile and its position in the 2D array.
 *
 * QueueNode is a custom type that contains a Tile and its position in the 2D array.
 *
 * Properties:
 * -----------
 * > _next: QueueNode* - pointer to the next node in the list
 * > _item: T* - pointer to the item in the node
 *
 * Methods:
 * -------
 * > QueueNode() - This is the default constructor of the QueueNode class.
 * > QueueNode(T* item)- This is the overloaded constructor of the QueueNode class that takes a pointer to an item.
 * > ~QueueNode() - This is the destructor of the QueueNode class.
 * > GetNext() const - This method returns the pointer to the next node in the list.
 * > SetNext(QueueNode* next) - This method sets the pointer to the next node in the list.
 * > GetItem() const - This method returns the pointer to the item in the node.
 * > SetItem(T* item) - This method sets the pointer to the item in the node.
 */
template <class T>
class QueueNode
{
public:
	typedef QueueNode<T> Sentinel;
	static Sentinel* NIL;

protected:
	T* _item;
	Sentinel* _next;

public:

	typedef QueueNode<T> Sentinel;

	/**
	 * @brief This is the default constructor of the QueueNode class.
	*/
	QueueNode()
	{
		_item = new T();
		_next = NIL;
	}


	/**
	 * @brief This is the overloaded constructor of the QueueNode class that takes a pointer to an item.
	 * @param item - the pointer to the item in the node.
	*/
	QueueNode(T* item) {
		_item = item;

		_next = NIL;
	}

	/**
	 * @brief This is the copy constructor of the QueueNode class.
	 * @param other - the reference to the QueueNode to be copied.
	*/
	QueueNode(const QueueNode& other)
	{
		_item = other._item;
		_next = other._next;
	}

	/**
	 * @brief This is the destructor of the QueueNode class.
	*/
	virtual ~QueueNode()
	{
		delete _item;
	}

	/**
	 * @brief This is the dereference operator overload for the QueueNode class.
	 * @return a reference to the item in the node.
	*/
	const QueueNode<T>& operator*()
	{
		return *this;
	}

	/**
	 * @brief Getter for the next node in the list.
	 * @return a pointer to the next node in the list.
	*/
	virtual QueueNode* GetNext() const
	{
		return _next;
	}

	/**
	 * @brief Setter for the next node in the list.
	 * @param next - the desired next node in the list.
	*/
	virtual void SetNext(QueueNode* next)
	{
		_next = next;
	}

	/**
	 * @brief This is the comparator operator overload for the QueueNode class.
	 * @param other - the reference to the QueueNode to be compared.
	 * @return a boolean value indicating whether the two nodes are equal.
	*/
	bool operator==(QueueNode<T>& other) const
	{
		return _item == other._item;
	}

	/**
	 * @brief This is the negation comparator operator overload for the QueueNode class.
	 * @param other - the reference to the QueueNode to be compared.
	 * @return a boolean value indicating whether the two nodes are not equal.
	*/
	bool operator!=(QueueNode<T>& other) const
	{
		return _item != other._item;
	}


	/**
	 * @brief Getter for the item contained in the node.
	 * @return a pointer to the item in the node.
	*/
	T* GetItem() const
	{
		return _item;
	}

	/**
	 * @brief Setter for the item contained in the node.
	 * @param item - the desired item in the node.
	*/
	void SetItem(T* item)
	{
		_item = item;
	}

};

/**
 * This class implements a DoubleNode node to be used as a template for double linked list
 * where the node contains a pointer to an custom object. It inherits from the
 * QueueNode class.
 *
 * Properties:
 * -----------
 * > _prev: DoubleQueueNode<T>* - pointer to the previous node in the list
 * > _next: DoubleQueueNode<T>* - pointer to the next node in the list
 * > _item: T* - pointer to the item in the node
 *
 * Methods:
 * --------
 * > DoubleQueueNode() - This is the default constructor of the DoubleQueue class.
 * > DoubleQueueNode(T* item) - This is the overloaded constructor of the DoubleQueue class that takes a pointer to an item.
 * > ~DoubleQueueNode() - This is the destructor of the DoubleQueue class.
 * > GetPrev() const: DoubleQueueNode* - This method returns the pointer to the previous node in the list.
 * > SetPrev(DoubleQueueNode* prev): void - This method sets the pointer to the previous node in the list.
 * > GetNext() const: DoubleQueueNode* - This method returns the pointer to the next node in the list.
 * > SetNext(DoubleQueueNode* next): void - This method sets the pointer to the next node in the list.
 * > GetItem() const: T* - This method returns the pointer to the item in the node.
 * > SetItem(T* item): void - This method sets the pointer to the item in the node.
 */
template <class T>
class DoubleQueueNode : public QueueNode<T>
{
public:
	typedef DoubleQueueNode<T> Sentinel;
	static Sentinel* NIL;

protected:
	Sentinel* _prev;
	Sentinel* _next;

public:
	/**
	 * @brief This is the default constructor of the DoubleQueueNode class.
	*/
	DoubleQueueNode()
	{
		this->_item = nullptr;

		this->_next = NIL;
		this->_prev = NIL;
	}

	/**
	 * @brief This is the overloaded constructor of the DoubleQueueNode class that takes a pointer to an item.
	 * @param item - the pointer to the item in the node.
	*/
	DoubleQueueNode(T* item)
	{
		this->_item = item;
		this->_next = NIL;
		this->_prev = NIL;
	}

	/**
	 * @brief This is the copy constructor of the DoubleQueueNode class.
	 * @param other - the reference to the DoubleQueueNode to be copied.
	*/
	DoubleQueueNode(const DoubleQueueNode& other)
	{
		this->_item = other._item;
		this->_next = other._next;
		this->_prev = other._prev;
	}

	/**
	 * @brief This is the destructor of the DoubleQueueNode class.
	*/
	~DoubleQueueNode() override
	{
		delete this->_item;
	}

	/**
	 * @brief Getter for the previous node in the list.
	 * @return - a reference to the item in the node.
	*/
	DoubleQueueNode<T>* GetPrev() const
	{
		return this->_prev;
	}

	/**
	 * @brief Setter for the previous node in the list.
	 * @param prev - the desired previous node in the list.
	*/
	void SetPrev(DoubleQueueNode<T>* prev)
	{
		this->_prev = prev;
	}

	/**
	 * @brief This is the comparator operator overload for the DoubleQueueNode class.
	 * @param other - the reference to the DoubleQueueNode to be compared.
	 * @return a boolean value indicating whether the two nodes are equal.
	*/
	bool operator==(DoubleQueueNode<T>& other) const
	{
		return this->_item == other._item;
	}

	/**
	 * @brief This is the negation comparator operator overload for the DoubleQueueNode class.
	 * @param other - the reference to the DoubleQueueNode to be compared.
	 * @return a boolean value indicating whether the two nodes are not equal.
	*/
	bool operator!=(DoubleQueueNode<T>& other) const
	{
		return this->_item != other._item;
	}

	/**
	 * @brief Getter for the next node in the list.
	 * @return a pointer to the next node in the list.
	*/
	DoubleQueueNode<T>* GetNext() const override
	{
		return this->_next;
	}

	/**
	 * @brief Setter for the next node in the list.
	 * @param next - the desired next node in the list.
	*/
	void SetNext(DoubleQueueNode<T>* next)
	{
		this->_next = next;
	}

};

template <class T>
typename QueueNode<T>::Sentinel* QueueNode<T>::NIL = new QueueNode<T>::Sentinel();

template <class T>
typename DoubleQueueNode<T>::Sentinel* DoubleQueueNode<T>::NIL = new DoubleQueueNode<T>::Sentinel();