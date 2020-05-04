//
// Created by BK Allen on 5/2/20.
//
// I changed some initializers to auto
// I changed some of the names and naming style
// to match my my naming conventions
// I eliminated using namespace std
//
//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#ifndef TEMPFINAL_BINARY_SEARCH_TREE_HPP
#define TEMPFINAL_BINARY_SEARCH_TREE_HPP

#include "Binary_Search_Tree.h"

// Constructor
template<typename data_type, typename key_type>
binary_search_tree<data_type, key_type>::binary_search_tree() {
    root = nullptr;
}

// Destructor
template<typename data_type, typename key_type>
binary_search_tree<data_type, key_type>::~binary_search_tree() {
    if (root != nullptr)
        free_node(root);
}


template<typename data_type, typename key_type>
void binary_search_tree<data_type, key_type>::free_node(Node<data_type, key_type> *leaf) {
    if (root == nullptr) {
        return;
    }
    free_node(leaf->leaf_left());
    free_node(leaf->leaf_right());
    delete_node(leaf);

}

template<typename data_type, typename key_type>
void binary_search_tree<data_type, key_type>::add_node(key_type key, data_type &data) {
    if (_root() == nullptr) {
        auto *node_pointer = new Node<data_type, key_type>;
        node_pointer->setKey(key);
        node_pointer->setData(data);
        root = node_pointer;
        root->setParent(root);

    } else
        insert_node(key, root, data); //Recursive
}

template<typename data_type, typename key_type>
void binary_search_tree<data_type, key_type>::insert_node
        (key_type key, Node<data_type, key_type> *leaf, data_type &data) {
    if (root == nullptr) {
        auto *newNodePtr = new Node<data_type, key_type>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);
    } else {
        if (key < leaf->Key()) {
            if (leaf->leaf_left() != nullptr)
                insert_node(key, leaf->leaf_left(), data);
            else {
                auto *newNodePtr = new Node<data_type, key_type>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setLeft(newNodePtr);
            }
        } else if (key >= leaf->Key()) {
            if (leaf->leaf_right() != nullptr)
                insert_node(key, leaf->leaf_right(), data);
            else {
                auto *newNodePtr = new Node<data_type, key_type>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setRight(newNodePtr);
            }
        }
    }
}

template<typename data_type, typename key_type>
Node<data_type, key_type> *binary_search_tree<data_type, key_type>::find(key_type key) {
    return find_node(key, root);
}

// Find a node
template<typename data_type, typename key_type>
Node<data_type, key_type> *
binary_search_tree<data_type, key_type>::find_node(key_type key, Node<data_type, key_type> *node) {
    if (node == nullptr)
        return nullptr;
    else if (node->Key() == key)
        return node;
    else {
        if (key < node->Key()) {
            return find_node(key, node->leaf_left());
        } else if (key > node->Key()) {
            return find_node(key, node->leaf_right());
        }
    }
    return nullptr;
}

template<typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::in_order() {
    in_order(root);
}

template<typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::in_order(Node<DATATYPE, KEYTYPE> *node) {
    if (node == nullptr)
        return;
    in_order(node->leaf_left());
    to_console(cout, node->Data());
    in_order(node->leaf_right());
}

template<typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::to_console(ostream &out, const DATATYPE &d) {
    if (d.Synopsis == "")
        out
                << std::endl
                << d.Year << std::endl
                << d.Award << std::endl
                << d.Winner << std::endl
                << d.Name << std::endl
                << d.Film << std::endl;
    else {
        out
                << std::endl
                << d.Name << std::endl
                << d.Year << std::endl
                << d.Nominations << std::endl
                << d.Rating << std::endl
                << d.Duration << std::endl
                << d.Genre1 << std::endl
                << d.Genre2 << std::endl
                << d.Release << std::endl
                << d.Metacritic << std::endl
                << d.Synopsis
                << endl;
    }
}

template<typename data_type, typename key_type>
void binary_search_tree<data_type, key_type>::delete_node(key_type k) {
    initialize_root(delete_node(_root(), k));
}

//delete_node (Private)
template<typename data_type, typename key_type>
Node<data_type, key_type> *
binary_search_tree<data_type, key_type>
::delete_node(Node<data_type, key_type> *_root, key_type key) {

    /* Given a binary search tree and a key_type, this function deletes the key_type
    and returns the new root */

    // base case
    if (_root == nullptr) return _root;

    // If the key_type to be deleted is smaller than the _root's key_type,
    // then it lies in left subtree
    if (key < _root->Key())
        _root->setLeft(delete_node(_root->leaf_left(), key));

        // If the key_type to be deleted is greater than the root's key_type,
        // then it lies in right subtree
    else if (key > _root->Key())
        _root->setRight(delete_node(_root->leaf_right(), key));

        // if key_type is same as root's key_type, then This is the node
        // to be deleted
    else {
        // node with only one child or no child
        if (_root->leaf_left() == nullptr) {
            Node<data_type, key_type> *temp = _root->leaf_right();
            delete _root;
            return temp;
        } else if (_root->leaf_right() == nullptr) {
            Node<data_type, key_type> *temp = _root->leaf_left();
            delete _root;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<data_type, key_type> *temp = find_min(_root->leaf_right());

        // Copy the inorder successor's content to this node
        _root->setKey(temp->Key());
        _root->setData(temp->Data());

        // Delete the inorder successor
        _root->setRight(delete_node(_root->leaf_right(), temp->Key()));
    }
    return _root;
}


// Find the node with find_min key
// Traverse the left sub-binary_search_tree recursively
// till left sub-binary_search_tree is empty to get find_min
template<typename data, typename key>
Node<data, key> *binary_search_tree<data, key>::find_min(Node<data, key> *node) {
    Node<data, key> *current = node;

    /* loop down to find the leftmost leaf */
    while (current->leaf_left() != nullptr)
        current = current->leaf_left();

    return current;
}

// Find the node with find_max key
// Traverse the right sub-binary_search_tree recursively
// till right sub-binary_search_tree is empty to get find_max
template<typename data, typename key>
Node<data, key> *binary_search_tree<data, key>
::find_max(Node<data, key> *node) {
    auto _node = node;
    if (node == nullptr)
        _node = nullptr;
    else if (node->leaf_right())
        _node = find_max(node->leaf_right());
    else
        _node = node;

    return _node;
}

#endif //TEMPFINAL_BINARY_SEARCH_TREE_HPP
