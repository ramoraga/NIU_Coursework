//*******************************************************************
// 
//  bstree.h
//  CSCI 241 Assignment 11
//
//  Created by Reinaldo Moraga and z1864815
//
//*******************************************************************

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <stdexcept>
#include <queue>

using std::queue;
using std::cout;
using std::endl;

// Forward declaration of the bstree template class
template <class K, class V>
class bstree;

template <class K, class V>
struct node
{
	K key;
	V value;
	node<K, V>* left;
	node<K, V>* right;

	node(const K& key = K(), const V& value = V(), node<K, V>* left = nullptr, node<K, V>* right = nullptr)
	{
		this->key = key;
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

template <class K, class V>
class bstree
{
	private:
		node<K, V>* root;
		size_t t_size;
		size_t height(node<K, V>*) const;
		const K& min(node<K, V>*) const;
		const K& max(node<K, V>*) const;
		void preorder(node<K, V>*) const;
		void inorder(node<K, V>*) const;
		void postorder(node<K, V>*) const;
	public:
		bstree();
		~bstree();
		bstree(const bstree<K, V>&);
		bstree<K, V>& operator=(const bstree<K, V>&);
		void clear();
		size_t size() const;
		size_t height() const;
		bool empty() const;
		const K& min() const;
		const K& max() const;
		bool insert(const K&, const V&);
		bool remove(const K&);
		const node<K, V>* find(const K&) const;
		void preorder() const;
		void inorder() const;
		void postorder() const;
		void level_order() const;
		node<K, V>* clone(node<K, V>*) const;
		void destroy(node<K, V>*) const;
};

/**
 * This is the default constructor for the bstree class.
 *
 * Sets root to nullptr and t_size to 0.
 *
 * @note takes no arguments and returns nothing.
 ********************************************************************************/
template <class K, class V>
bstree<K, V>::bstree()
{
	root = nullptr;
	t_size = 0;
}

/**
 * This is the destructor for the bstree class.
 *
 * Calls the clear() function.
 *
 * @note takes no arguments and returns nothing. 
 ********************************************************************************/
template <class K, class V>
bstree<K, V>::~bstree()
{
	clear();
}

/**
 * This is the copy constructor for the bstree class.
 *
 * @param x The existing bstree object that is passed to be copied.
 *
 * @note Returns nothing.
 ********************************************************************************/
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x)
{
	t_size = x.t_size;

	root = clone(x.root);
}

/**
 * This is the copy assignment operator for the bstree class.
 *
 * @param x The existing bstree object that is passed to be assigned.
 *
 * @return The mylist object that called the function.
 ********************************************************************************/
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x)
{
	if (this != &x) {
		clear();
		t_size = x.t_size;
		root = clone(x.root);
	}

	return *this;
}

/**
 * This member function is used to clear a bstree object.
 *
 * Calls destroy() to clear the root and converts root to nullptr
 * and t_size to 0.
 *
 * @note Takes no arguments and returns nothing.
 * ********************************************************************************/
template <class K, class V>
void bstree<K, V>::clear()
{
	destroy(root);
	root = nullptr;
	t_size = 0;
}

/**
 * This member function is used to print the tree size of a bstree object.
 *
 * @return The tree size of a bstree object.
 *
 * @note Takes no arguments.
 ********************************************************************************/
template <class K, class V>
size_t bstree<K, V>::size() const
{
	return t_size;
}

/**
 * This member function is used to print the height of a bstree object.
 *
 * Calls a private recursive function.
 *
 * @return The height of a bstree object.
 *
 * @note Takes no arguments.
 ********************************************************************************/
template <class K, class V>
size_t bstree<K, V>::height() const
{
	return height(root);
}

/**
 * This member function is used to find the height of a bstree object.
 *
 * A private recursive function that looks for the height of a bstree object.
 *
 * @param p A pointer to a search tree
 *
 * @return The height of a bstree object.
 ********************************************************************************/
template <class K, class V>
size_t bstree<K, V>::height(node<K, V>* p) const
{
	if (p == nullptr) {
		return 0;
	} else {
		size_t l_height = height(p->left);
		size_t r_height = height(p->right);

		if (l_height > r_height) {
			return 1 + l_height;
		} else {
			return 1 + r_height;
		}
	}

	return 1;
}

/**
 * This member function is used to check if a tree is empty or not.
 *
 * Checks if the tree size is 0, if so, the tree is empty.
 *
 * @return True if the tree is empty, false if it's not.
 *
 * @note Takes no arguments.
 ********************************************************************************/
template <class K, class V>
bool bstree<K, V>::empty() const
{
	if (t_size == 0) {
		return true;
	} else {
		return false;
	}
}

/**
 * This member function is used to print the min value of a bstree object.
 *
 * Calls a private recursive function to find the min value.
 *
 * @return The min value of the bstree object.
 *
 * @note Takes no arguments.
 ********************************************************************************/
template <class K, class V>
const K& bstree<K, V>::min() const
{
	return min(root);
}

/**
 * This member function is used to find the min value of a bstree object.
 *
 * This is a private recursive function that is called by the public min() 
 * function and is used to find the min value.
 *
 * @param p A pointer to a search tree
 *
 * @return The min value of the bstree object.
 ********************************************************************************/
template <class K, class V>
const K& bstree<K, V>::min(node<K, V>* p) const
{
	if (p->left == nullptr) {
		return p->key;
	}
	return min(p->left);
}

/**
 * This member function is used to print the max value of a bstree object.
 *
 * Calls a private recursive function to find the max value.
 *
 * @return The max value of the bstree object.
 *
 * @note Takes no arguments.
 ********************************************************************************/
template <class K, class V>
const K& bstree<K, V>::max() const
{
	return max(root);
}

/**
 * This member function is used to find the max value of a bstree object.
 *
 * This is a private recursive function that is called by the public max() 
 * function and is used to find the max value.
 *
 * @param p A pointer to a search tree
 *
 * @return The max value of the bstree object.
 ********************************************************************************/
template <class K, class V>
const K& bstree<K, V>::max(node<K, V>* p) const
{
	if (p->right == nullptr) {
		return p->key;
	}
	return max(p->right);
}

/**
 * This member function is used to insert a value to a bstree object.
 *
 * @param key A key to insert
 * @param value A value to insert
 *
 * @return True for success or False for failure.
 ********************************************************************************/
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value)
{
	node<K, V>* p = root;
	node<K, V>* parent = nullptr;
	node<K, V>* new_node = new node<K, V>(key, value);

	while (p != nullptr && key != p->key) {
		parent = p;
		if (key < p->key) {
			p = p->left;
		} else {
			p = p->right;
		}
	}

	if (p != nullptr) {
		return false;
	}

	if (parent == nullptr) {
		root = new_node;
	} else {
		if (new_node->key < parent->key) {
			parent->left = new_node;
		} else {
			parent->right = new_node;
		}
	}

	t_size = t_size + 1;

	return true;
}

/**
 * This member function is used to remove a node from a bstree object.
 *
 * @param key A key to remove
 *
 * @return True for success or False for failure.
 ********************************************************************************/
template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
	node<K, V>* replace;
	node<K, V>* replace_parent;
	node<K, V>* p = root;
	node<K, V>* parent = nullptr;
	
	while (p != nullptr && key != p->key) {
		parent = p;
		if (key < p->key) {
			p = p->left;
		} else {
			p = p->right;
		}
	}

	if (p == nullptr) {
		return false;
	}

	if (p->left == nullptr) {
		replace = p->right;
	} else {
		if (p->right == nullptr) {
			replace = p->left;
		} else {
			replace_parent = p;
			replace = p->left;

			while (replace->right != nullptr) {
				replace_parent = replace;
				replace = replace->right;
			}

			if (replace_parent != p) {
				replace_parent->right = replace->left;
				replace->left = p->left;
			}

			replace->right = p->right;
		}
	}

	if (parent == nullptr) {
		root = replace;
	} else {
		if (p->key < parent->key) {
			parent->left = replace;
		} else {
			parent->right = replace;
		}
	}
	
	delete p;
	t_size = t_size - 1;

	return true;
}

/**
 * This member function is used to find a node of a bstree object.
 *
 * @param key A key to search for
 *
 * @return p A pointer to a node.
 ********************************************************************************/
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const
{
	node<K, V>* p = root;

	while (p != nullptr && key != p->key) {
		if (key < p->key) {
			p = p->left;
		} else {
			p = p->right;
		}
	}

	return p;
}

/**
 * This member function is used to call the private recursive preorder function.
 *
 * @note Returns nothing and takes no arguments.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::preorder() const
{	
	preorder(root);

}

/**
 * This member function is used to visit a node and traverse both of its subtrees.
 *
 * Goes through the node's left subtree and then the right. It then prints each
 * key and value when it visits a node.
 *
 * @param p A pointer to a search tree.
 *
 * @note Returns nothing.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::preorder(node<K, V>* p) const
{
	if (p != nullptr) {
		std::cout << p->key << ": " <<  p->value << std::endl;
		preorder(p->left);
		preorder(p->right);
	}
}

/**
 * This member function is used to call the private recursive inorder function.
 *
 * @note Returns nothing and takes no arguments.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::inorder() const
{
	inorder(root);
}

/**
 * This member function is used to traverse one subtree of a node, visit the
 * node, and then traverse its other subtree..
 *
 * Goes through the node's left subtree and then the right. It then prints each
 * key and value when it visits a node.
 *
 * @param p A pointer to a search tree.
 *
 * @note Returns nothing.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::inorder(node<K, V>* p) const
{
	if (p != nullptr) {
		inorder(p->left);
		std::cout << p->key << ": " << p->value << std::endl;		
		inorder(p->right);
	}
}

/**
 * This member function is used to call the private recursive postorder function.
 *
 * @note Returns nothing and takes no arguments.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::postorder() const
{
	postorder(root);
}

/**
 * This member function is used to traverse both subtrees of a node, then visit
 * the node.
 *
 * Goes through the node's left subtree first and then the right. It then prints
 * each key and value when it visits a node.
 *
 * @param p A pointer to a search tree.
 *
 * @note Returns nothing.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::postorder(node<K, V>* p) const
{
	if (p != nullptr) {
		postorder(p->left);
		postorder(p->right);
		std::cout << p->key << ": " << p->value << std::endl;
	}
}

/**
 * This member function is used to traverse all of the tree nodes on the first
 * level, then the next.
 *
 * It then prints each key and value when it visits a node.
 *
 * @note Returns nothing and takes no arguments.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::level_order() const
{
	node<K, V>* p;
	std::queue<node<K, V>*> q;

	if (root == nullptr) {
		return;
	}

	q.push(root);

	while (!q.empty()) {
		p = q.front();
		q.pop();	
		std::cout << p->key << ": " << p->value << std::endl;		

		if (p->left != nullptr) {
			q.push(p->left);
		}

		if (p->right != nullptr) {
			q.push(p->right);
		}
	}
}

/**
 * This member function is used to recursively copy the nodes of a bstree object.
 *
 * @param p A pointer to a search tree.
 *
 * @note Returns the copied node or nullptr.
 ********************************************************************************/
template <class K, class V>
node<K, V>* bstree<K, V>::clone(node<K, V>* p) const
{
	if (p != nullptr) {
		node<K, V> *new_node = new node<K, V>(p->key, p->value);
		//new_node->key = p->key;
		//new_node->value = p->value;

		new_node->left = clone(p->left);
		new_node->right = clone(p->right);

		return new_node;
	} else {
		return nullptr;
	}
}

/**
 * This member function is used to recursively delete the nodes of a bstree 
 * object.
 *
 * @param p A pointer to a search tree.
 *
 * @note Returns nothing.
 ********************************************************************************/
template <class K, class V>
void bstree<K, V>::destroy(node<K, V>* p) const
{
	if (p != nullptr) {
		destroy(p->left);
		destroy(p->right);

		delete p;
	}
}

#endif /* BSTREE_H */
