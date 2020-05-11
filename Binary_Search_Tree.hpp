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
template<typename DATATYPE, typename KEYTYPE>
Binary_Search_Tree<DATATYPE, KEYTYPE>::Binary_Search_Tree() {
    root = nullptr;
}

// Destructor
template<typename DATATYPE, typename KEYTYPE>
Binary_Search_Tree<DATATYPE, KEYTYPE>::~Binary_Search_Tree() {
    if (root != nullptr) make_empty(root);
}

/// @brief
/// @tparam DATATYPE
/// @tparam KEYTYPE
/// @param leaf
/// @return
/// @changed return type
template<typename DATATYPE, typename KEYTYPE>
Node_Struct *Binary_Search_Tree<DATATYPE, KEYTYPE>::make_empty(Node<DATATYPE, KEYTYPE> *leaf) {
    if (root == nullptr) { return nullptr; }
    make_empty(leaf->leaf_left());
    make_empty(leaf->leaf_right());
    remove(leaf);
    return nullptr;
}

template<typename DATATYPE, typename KEYTYPE>
void Binary_Search_Tree<DATATYPE, KEYTYPE>::add_node(KEYTYPE key, DATATYPE &data) {
    if (_root() == nullptr) {
        auto *node_pointer = new Node<DATATYPE, KEYTYPE>;
        node_pointer->setKey(key);
        node_pointer->setData(data);
        root = node_pointer;
        root->setParent(root);
    } else
        insert_node(key, root, data); //Recursive
}

template<typename DATATYPE, typename KEYTYPE>
void Binary_Search_Tree<DATATYPE, KEYTYPE>::insert_node
        (KEYTYPE key, Node<DATATYPE, KEYTYPE> *leaf, DATATYPE &data) {
    if (root == nullptr) {
        auto *newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);
    } else {
        if (key < leaf->Key()) {
            if (leaf->leaf_left() != nullptr)
                insert_node(key, leaf->leaf_left(), data);
            else {
                auto *newNodePtr = new Node<DATATYPE, KEYTYPE>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setLeft(newNodePtr);
            }
        } else if (key >= leaf->Key()) {
            if (leaf->leaf_right() != nullptr)
                insert_node(key, leaf->leaf_right(), data);
            else {
                auto *newNodePtr = new Node<DATATYPE, KEYTYPE>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setRight(newNodePtr);
            }
        }
    }
}

template<typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> *Binary_Search_Tree<DATATYPE, KEYTYPE>::find(KEYTYPE key) {
    return find_node(key, root);
}

// Find a node
template<typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> *
Binary_Search_Tree<DATATYPE, KEYTYPE>::find_node(KEYTYPE key, Node<DATATYPE, KEYTYPE> *node) {
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
void Binary_Search_Tree<DATATYPE, KEYTYPE>::in_order() {
    in_order(root);
}

template<typename DATATYPE, typename KEYTYPE>
void Binary_Search_Tree<DATATYPE, KEYTYPE>::in_order(Node<DATATYPE, KEYTYPE> *node) {
    if (node == nullptr)
        return;
    in_order(node->leaf_left());
    display(std::cout, node->Data());
    in_order(node->leaf_right());
}

template<typename DATATYPE, typename KEYTYPE>
void Binary_Search_Tree<DATATYPE, KEYTYPE>::display(std::ostream &output, const DATATYPE &data) {
    if (data.Synopsis == "")
        output
                << std::endl
                << data.Year << std::endl
                << data.Award << std::endl
                << data.Winner << std::endl
                << data.Name << std::endl
                << data.Film << std::endl;
    else {
        output
                << std::endl
                << data.Name << std::endl
                << data.Year << std::endl
                << data.Nominations << std::endl
                << data.Rating << std::endl
                << data.Duration << std::endl
                << data.Genre1 << std::endl
                << data.Genre2 << std::endl
                << data.Release << std::endl
                << data.Meta_Critic << std::endl
                << data.Synopsis << std::endl;
    }
}

template<typename DATATYPE, typename KEYTYPE>
void Binary_Search_Tree<DATATYPE, KEYTYPE>::remove(KEYTYPE key) {
    initialize_root(remove_node(_root(), key));
}

//remove (Private)
template<typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> *
Binary_Search_Tree<DATATYPE, KEYTYPE>
::remove_node(Node<DATATYPE, KEYTYPE> *_root, KEYTYPE key) {

    /* Given a binary search tree and a KEYTYPE, this function deletes the KEYTYPE
    and returns the new root */

    // base case
    if (_root == nullptr) return _root;

    // If the KEYTYPE to be deleted is smaller than the _root's KEYTYPE,
    // then it lies in left subtree
    if (key < _root->Key())
        _root->setLeft(remove_node(_root->leaf_left(), key));

        // If the KEYTYPE to be deleted is greater than the root's KEYTYPE,
        // then it lies in right subtree
    else if (key > _root->Key())
        _root->setRight(remove_node(_root->leaf_right(), key));

        // if KEYTYPE is same as root's KEYTYPE, then This is the node
        // to be deleted
    else {
        // node with only one child or no child
        if (_root->leaf_left() == nullptr) {
            Node<DATATYPE, KEYTYPE> *temp = _root->leaf_right();
            delete _root;
            return temp;
        } else if (_root->leaf_right() == nullptr) {
            Node<DATATYPE, KEYTYPE> *temp = _root->leaf_left();
            delete _root;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<DATATYPE, KEYTYPE> *temp = find_min(_root->leaf_right());

        // Copy the inorder successor's content to this node
        _root->setKey(temp->Key());
        _root->setData(temp->Data());

        // Delete the inorder successor
        _root->setRight(remove_node(_root->leaf_right(), temp->Key()));
    }
    return _root;
}


// Find the node with find_min key
// Traverse the left sub-Binary_Search_Tree recursively
// till left sub-Binary_Search_Tree is empty to get find_min
template<typename data, typename key>
Node<data, key> *Binary_Search_Tree<data, key>::find_min(Node<data, key> *node) {
    Node<data, key> *current = node;

    /* loop down to find the leftmost leaf */
    while (current->leaf_left() != nullptr)
        current = current->leaf_left();

    return current;
}

// Find the node with find_max key
// Traverse the right sub-Binary_Search_Tree recursively
// till right sub-Binary_Search_Tree is empty to get find_max
template<typename data, typename key>
Node<data, key> *Binary_Search_Tree<data, key>
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
