//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_BINARY_SEARCH_TREE_H
#define TEMPFINAL_BINARY_SEARCH_TREE_H
#include <iostream>
#include "Node.h"
using namespace std;
// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class binary_search_tree {
private:
    Node<DATATYPE, KEYTYPE> * root;
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
    void printInorder(Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);

public:
    binary_search_tree<DATATYPE, KEYTYPE>();
    ~binary_search_tree<DATATYPE, KEYTYPE>();
    Node<DATATYPE, KEYTYPE> * Root() { return root; }
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;}
    void addNode(KEYTYPE key, DATATYPE &data);
    Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
    void printInorder();
    void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key);
    Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);
};
#endif //TEMPFINAL_BINARY_SEARCH_TREE_H
