//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_NODE_H
#define TEMPFINAL_NODE_H
#include <iostream>
#include <string>
using namespace std;



struct Final
{
    //Update this to your data field
    string Award,Winner,Name,Film, Year;
    double Rating;
    int Nominations,Duration,Metacritic;
    string Genre1,Genre2,Release,Synopsis;
};


//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    string key; //This should be the datatype of your key...sorted field in tree
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
    Node<DATATYPE, KEYTYPE> * Left() { return left; };
    Node<DATATYPE, KEYTYPE> * Right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
};

#endif //TEMPFINAL_NODE_H
