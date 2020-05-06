//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_BINARY_SEARCH_TREE_H
#define TEMPFINAL_BINARY_SEARCH_TREE_H

#include <iostream>
#include "Node.h"

using namespace std;

// Binary Search Tree class
template<typename DATATYPE, typename KEYTYPE>
class Binary_Search_Tree {
private:
    Node<DATATYPE, KEYTYPE> *root;

    Node<DATATYPE, KEYTYPE> *find_node(KEYTYPE key, Node<DATATYPE, KEYTYPE> *node);

    Node<DATATYPE, KEYTYPE> * remove_node(Node<DATATYPE, KEYTYPE> *_root, KEYTYPE key);

    void insert_node(KEYTYPE key, Node<DATATYPE, KEYTYPE> *leaf, DATATYPE &data);

    Node_Struct * make_empty(Node<DATATYPE, KEYTYPE> *leaf);

    void in_order(Node<DATATYPE, KEYTYPE> *node);


public:
    Binary_Search_Tree<DATATYPE, KEYTYPE>();

    ~Binary_Search_Tree<DATATYPE, KEYTYPE>();

    Node<DATATYPE, KEYTYPE> *find(KEYTYPE key);

    Node<DATATYPE, KEYTYPE> *find_min(Node<DATATYPE, KEYTYPE> *node);

    Node<DATATYPE, KEYTYPE> *find_max(Node<DATATYPE, KEYTYPE> *node);

    Node<DATATYPE, KEYTYPE> *_root() { return root; }

    void initialize_root(Node<DATATYPE, KEYTYPE> *this_root) { root = this_root; }

    void add_node(KEYTYPE key, DATATYPE &data);

    void in_order();

    void display(ostream &output, const DATATYPE &data);

    void remove(KEYTYPE key);


};

#endif //TEMPFINAL_BINARY_SEARCH_TREE_H
