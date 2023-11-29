#include "ActionTree.h"
#include <iostream>

using namespace std;
ActionTree::ActionTree()
{
	string action0 = "Hammer Swing";
	string action1 = "Head Butt";
	string action2 = "Jab Punch";
	string action3 = "Uppercut Punch";
	Node* root = new Node(action0);
	Node* left = new Node(action1);
	Node* right = new Node(action2);
	Node* right2 = new Node(action3);

	root->SetParent(nullptr);
	root->SetLeft(left);
	root->SetRight(right);
	root->GetLeft()->SetParent(root);
	root->GetRight()->SetParent(root);
	root->GetRight()->SetRight(right2);

	_root = root;
	_current = root;
	_current->SetParent(nullptr);
	_size = 1;
	_maxSize = 20;
	_isFull = false;
	_damage = 14;
}

ActionTree::~ActionTree()
{
	delete _root;
}

void ActionTree::InsertNode(Node* node)
{
    if (_root == nullptr)
    {
        _root = node;
        _current = node;
        _size++;
        return;
    }
    
    Node* current = _root;
    while (true)
    {
        if (node->GetAction() < current->GetAction())
        {
            if (current->GetLeft() == nullptr)
            {
                current->SetLeft(node);
                node->SetParent(current);
                _size++;
                return;
            }
            else
            {
                current = current->GetLeft();
            }
        }
        else
        {
            if (current->GetRight() == nullptr)
            {
                current->SetRight(node);
                node->SetParent(current);
                _size++;
                return;
            }
            else
            {
                current = current->GetRight();
            }
        }
    }
}

void ActionTree::Delete(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    Node* parent = node->GetParent();
    Node* leftChild = node->GetLeft();
    Node* rightChild = node->GetRight();
    
    // If Node has no children
    if (leftChild == nullptr && rightChild == nullptr)
    {
        if (parent == nullptr)
        {
            _root = nullptr;
        }
        else if (parent->GetLeft() == node)
        {
            parent->SetLeft(nullptr);
        }
        else
        {
            parent->SetRight(nullptr);
        }
        
        delete node;
        _size--;
    }
    
    // If Node has one child
    else if (leftChild == nullptr || rightChild == nullptr)
    {
        Node* child = (leftChild != nullptr) ? leftChild : rightChild;
        
        if (parent == nullptr)
        {
            _root = child;
            child->SetParent(nullptr);
        }
        else if (parent->GetLeft() == node)
        {
            parent->SetLeft(child);
            child->SetParent(parent);
        }
        else
        {
            parent->SetRight(child);
            child->SetParent(parent);
        }
        
        delete node;
        _size--;
    }
    
    // If Node has two children
    else
    {
        Node* successor = GetSuccessor(node);
        Node* successorParent = successor->GetParent();
        Node* successorRightChild = successor->GetRight();
        
        if (successorParent->GetLeft() == successor)
        {
            successorParent->SetLeft(successorRightChild);
        }
        else
        {
            successorParent->SetRight(successorRightChild);
        }
        
        if (successorRightChild != nullptr)
        {
            successorRightChild->SetParent(successorParent);
        }
        
        node->SetAction(successor->GetAction());
        
        delete successor;
        _size--;
    }
}

Node* ActionTree::GetSuccessor(Node* node)
{
    Node* current = node->GetRight();
    
    while (current->GetLeft() != nullptr)
    {
        current = current->GetLeft();
    }
    
    return current;
}

void ActionTree::InOrder(Node* node) const
{
	if (node != nullptr)
	{
		InOrder(node->GetLeft());
		cout << "Attacking with: " << endl;
		node->Print();
		InOrder(node->GetRight());
	}
}

void ActionTree::InOrderTraverse() const
{
	InOrder(_root);
    cout << "Damage Dealt: " << _damage << endl;
}

void ActionTree::PreOrder(Node* node) const
{
    if (node != nullptr)
    {
        cout << "Attacking with: " << endl;
        node->Print();
        PreOrder(node->GetLeft());
        PreOrder(node->GetRight());
    }
}

void ActionTree::PreOrderTraverse() const
{
	PreOrder(_root);
    cout << "Damage Dealt: " << _damage << endl;
}

void ActionTree::PostOrder(Node* node) const
{
	if (node != nullptr)
	{
		PostOrder(node->GetLeft());
		PostOrder(node->GetRight());
		cout << "Attacking with: " << endl;
		node->Print();
	}
}

void ActionTree::PostOrderTraverse() const
{
	PostOrder(_root);
    cout << "Damage Dealt: " << _damage << endl;
}

Node* ActionTree::GetRoot() const
{
	return _root;
}

Node* ActionTree::GetCurrent() const
{
	return _current;
}

int ActionTree::GetSize() const
{
	return _size;
}

 int ActionTree::GetDamage() const
{
	return _damage;
}

void ActionTree::SetDamage(int damage)
{
	_damage = damage;
}

void ActionTree::SetCurrent(Node* current)
{
	_current = current;
}

Node::Node()
{
	_left = nullptr;
	_right = nullptr;
	_parent = nullptr;
	_action = "Wrestle Attack";
}

Node::Node(string& action)
{
	_left = nullptr;
	_right = nullptr;
	_parent = nullptr;
	_action = action;
}

Node::~Node()
{
	delete _left;
	delete _right;
}

string& Node::GetAction()
{
	return _action;
}

Node* Node::GetLeft() const
{
	return _left;
}

Node* Node::GetRight() const
{
	return _right;
}

Node* Node::GetParent() const
{
	return _parent;
}

void Node::SetAction(string& action)
{
	_action = action;
}

void Node::SetLeft(Node* left)
{
	_left = left;
}

void Node::SetRight(Node* right)
{
	_right = right;
}

void Node::SetParent(Node* parent)
{
	_parent = parent;
}

void Node::Print() const
{
	cout << "\t> " << _action << endl;
}