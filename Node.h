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



struct Final
{
    //Update this to your data field
    std::string Award,Winner,Name,Film, Year;
    double Rating;
    int Nominations,Duration,Metacritic;
    std::string Genre1,Genre2,Release,Synopsis;
};


//Binary Tree Node
template <typename data_type, typename KEYTYPE>
class Node {
private:
    std::string key; //This should be the datatype of your key...sorted field in tree
    data_type data;
    Node<data_type, KEYTYPE> * left;
    Node<data_type, KEYTYPE> * right;
    Node<data_type, KEYTYPE> * parent;
public:
    Node() {left=nullptr; right=nullptr; parent = nullptr;};
    void setKey(KEYTYPE aKey) { key = aKey; };
    void setData(data_type aData) { data = aData; }
    void setLeft(Node<data_type, KEYTYPE> * aLeft) { left = aLeft; };
    void setRight(Node<data_type, KEYTYPE> * aRight) { right = aRight; };
    void setParent(Node<data_type, KEYTYPE> * aParent) { parent = aParent; };
    KEYTYPE Key() { return key; };
    data_type Data() { return data; }
    Node<data_type, KEYTYPE> * leaf_left() { return left; };
    Node<data_type, KEYTYPE> * leaf_right() { return right; };
    Node<data_type, KEYTYPE> * Parent() { return parent; };
};

#endif //TEMPFINAL_NODE_H
