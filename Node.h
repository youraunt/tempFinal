//
// Created by BK Allen on 5/2/20.
//
// I changed some initializers to auto
// I changed some of the names and naming style
// to match my naming conventions
// I eliminated using namespace std
//
//To be used in conjunction with BSTree.h and BSTree.hpp
//If you modify this, please add your name and list any changes that you made
#ifndef TEMPFINAL_NODE_H
#define TEMPFINAL_NODE_H
#include <iostream>



struct Node_Struct
{
    std::string Award;
    std::string Winner;
    std::string Name;
    std::string Film;
    std::string Year;
    double Rating;
    int Nominations;
    int Duration;
    int Meta_Critic;
    std::string Genre1,Genre2,Release,Synopsis;
};


//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    std::string key; //This should be the datatype of your key...sorted field in tree
    DATATYPE data;
    Node<DATATYPE, KEYTYPE> * left;
    Node<DATATYPE, KEYTYPE> * right;
    Node<DATATYPE, KEYTYPE> * parent;
public:
    Node() {left=nullptr; right=nullptr; parent = nullptr;};
    void setKey(KEYTYPE aKey) { key = aKey; };
    void setData(DATATYPE aData) { data = aData; }
    void setLeft(Node<DATATYPE, KEYTYPE> * aLeft) { left = aLeft; };
    void setRight(Node<DATATYPE, KEYTYPE> * aRight) { right = aRight; };
    void setParent(Node<DATATYPE, KEYTYPE> * aParent) { parent = aParent; };
    KEYTYPE Key() { return key; };
    DATATYPE Data() { return data; }
    Node<DATATYPE, KEYTYPE> * leaf_left() { return left; };
    Node<DATATYPE, KEYTYPE> * leaf_right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
};

#endif //TEMPFINAL_NODE_H
