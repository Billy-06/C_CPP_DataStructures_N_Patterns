#pragma once
#include <string>
class Node;
/**
 * @file ActionTree.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file contains the declaration of the ActionTree class
 * which is a tree structure that holds the actions that are to be performed
 * by the character.
 *
 * Properties:
 * -----------
 * > _root: The root node of the tree
 * > _current: The current node of the tree
 * > _size: The number of nodes in the tree
 * > _maxSize: The maximum number of nodes in the tree
 * > _isFull: A boolean value that indicates whether the tree is full or not
 *
 * Methods:
 * --------
 * > ActionTree(): Constructor
 * > ~ActionTree(): Destructor
 * > Insert(): void - Inserts a new node into the tree
 * > Delete(): void - Deletes a node from the tree
 * > Traverse(): void - Traverses the tree
 * > GetRoot(): Node* - Returns the root node of the tree
 * > GetCurrent(): Node* - Returns the current node of the tree
 * > SetCurrent(): void - Sets the current node of the tree
 * > GetSize(): int - Returns the number of nodes in the tree
 * 
 */
class ActionTree
{
private:
	Node* _root;
	Node* _current;
	int _size;
	int _maxSize;
	bool _isFull;
	int _damage;
	

public:
	/**
	 * @brief This is the default constructor
	*/
	ActionTree();

	/**
	 * @brief This is the destructor
	*/
	~ActionTree();

	/**
	 * @brief This method inserts a new node into the tree
	 * @param node - the node to be inserted
	*/
	void InsertNode(Node* node);

	/**
	 * @brief This method deletes a node from the tree
	 * @param node - node to be deleted
	*/
	void Delete(Node* node);

	/**
	 * @brief This method performs recurring InOrder traversal of the tree
	 * @param node - the node to start traversing from
	*/
	void InOrder(Node* node) const;

	/**
	 * @brief This method uses the InOrder method to traverse the tree
	*/
	void InOrderTraverse() const;

	/**
	 * @brief This method performs recurring PreOrder traversal of the tree
	 * @param node - the node to start traversing from
	*/
	void PreOrder(Node* node) const;

	/**
	 * @brief This method uses the PreOrder method to traverse the tree
	*/
	void PreOrderTraverse() const;

	/**
	 * @brief This method performs recurring PostOrder traversal of the tree
	 * @param node - the node to start traversing from
	*/
	void PostOrder(Node* node) const;

	/**
	 * @brief This method uses the PostOrder method to traverse the tree
	*/
	void PostOrderTraverse() const;

	/**
	 * @brief Getter for the root node
	 * @return pointer to the root node
	*/
	Node* GetRoot() const;

	/**
	 * @brief Getter for the Current node
	 * @return pointer to the current node
	*/
	Node* GetCurrent() const;

	/**
	 * @brief Getter for the successor node
	 * @param node - the node from which to retrieve the successor node
	 * @return pointer to the successor node
	*/
	Node* GetSuccessor(Node* node);

	/**
	 * @brief Getter for the size of the tree
	 * @return an integer representing the size of the tree
	*/
	int GetSize() const;

	/**
	 * @brief Getter for the damage
	 * @return an integer representing the damage from attacks
	*/
	int GetDamage() const;

	/**
	 * @brief Setter for the damage value
	 * @param damage - the desired damage value
	*/
	void SetDamage(int damage);

	/**
	 * @brief Setter for the current node
	 * @param current - the desired current node
	*/
	void SetCurrent(Node* current);
};


/**
 * @file ActionTree.h
 * @author Billy Ndegwah Micah
 *
 * Description: This class represents a node in the ActionTree. It holds the action
 * along with the left, right and parent nodes which are all of type Node (or attack actions).
 *
 * Properties:
 * -----------
 * > _action: The action that is to be performed by the character
 * > _left: The left node of the current node
 * > _right: The right node of the current node
 * > _parent: The parent node of the current node
 * > None: A sentinel node that is used to indicate that a node is null
 *
 * Methods:
 * --------
 * > Node(): Default Constructor
 * > Node(std::string& action): Overloaded Constructor
 * > ~Node(): Destructor
 * > Getters and Setters for all the properties
 * > Print(): void - Prints the action
 *
 */
class Node
{

private:
	std::string _action;
	Node* _left = nullptr;
	Node* _right = nullptr;
	Node* _parent = nullptr;

public:
	/**
	 * @brief This is the default constructor
	*/
	Node();

	/**
	 * @brief This is the overloaded constructor
	 * @param action - the action to be performed
	*/
	Node(std::string& action);

	/**
	 * @brief This is the destructor
	*/
	~Node();

	/**
	 * @brief Getter for the action
	 * @return a string representing the action
	*/
	std::string& GetAction();

	/**
	 * @brief Getter for the left node
	 * @return a pointer to the left node
	*/
	Node* GetLeft() const;

	/**
	 * @brief Getter for the right node
	 * @return a pointer to the right node
	*/
	Node* GetRight() const;

	/**
	 * @brief Getter for the parent node
	 * @return a pointer to the parent node
	*/
	Node* GetParent() const;

	/**
	 * @brief Setter for the action
	 * @param action - the action to be performed
	*/
	void SetAction(std::string& action);

	/**
	 * @brief Setter for the left node
	 * @param left - the left node
	*/
	void SetLeft(Node* left);

	/**
	 * @brief Setter for the right node
	 * @param right - the right node
	*/
	void SetRight(Node* right);

	/**
	 * @brief Setter for the parent node
	 * @param parent - the parent node
	*/
	void SetParent(Node* parent);

	/**
	 * @brief This method is used to print the action
	*/
	void Print() const;
};
