//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_BINARY_SEARCH_TREE_HPP
#define TEMPFINAL_BINARY_SEARCH_TREE_HPP
#include "Binary_Search_Tree.h"
// Constructor
template <typename DATATYPE, typename KEYTYPE>
binary_search_tree<DATATYPE, KEYTYPE>::binary_search_tree() {
    root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
binary_search_tree<DATATYPE, KEYTYPE>::~binary_search_tree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
    //Student must fill in
    //if the root is the leaf, delete that leaf
    // otherwise if the leaf is not null
    //recursive call of the leaf's left
    //recursive call of the leaf's right
    //now delete the leaf
    if(root == nullptr){
        return;
    }
    freeNode(leaf->Left());
    freeNode(leaf->Right());
    deleteNode(leaf);

}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
    if (Root() == nullptr)
    {
        auto * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);

    }
    else
        addNode(key, root, data); //Recursive
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
    //Student must fill in
    //Don't forget to set your key, Parent, then left or right
    //Based on the case you use you will addNode recursively to the left or right

    //First check if root is null
    //make a new node
    //set the key and data
    //set the root
    //Otherwise
    //Check to see if the key is < the leaf's key
    // if left is not null then
    //Add the node to the left (recursively)
    // Otherwise make a new node and attach it to the left

    //Check to see if the key >= leaf's key
    // if leaf's right is not null then
    //Add the node to the right (recursively)
    // Otherwise make new node and attach it to the right
    if(root == nullptr){
        auto * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);
    }
    else{
        if(key < leaf->Key()){
            if(leaf->Left() != nullptr)
                addNode(key,leaf->Left(),data);
            else {
                auto * newNodePtr = new Node<DATATYPE, KEYTYPE>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setLeft(newNodePtr);
            }
        }
        else if ( key >= leaf->Key()){
            if(leaf->Right() != nullptr)
                addNode(key,leaf->Right(),data);
            else{
                auto * newNodePtr = new Node<DATATYPE, KEYTYPE>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setRight(newNodePtr);
            }
        }
    }
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * binary_search_tree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
    return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * binary_search_tree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in
    // trap nullptr first in case we've hit the end unsuccessfully.
    // success base case
    //Greater than (Right), Less than (Left)
    if(node == nullptr)
        return nullptr;
    else if(node->Key() == key)
        return node;
    else{
        if(key < node->Key()){
            return findNode(key,node->Left());
        }
        else if (key > node->Key()){
            return findNode(key,node->Right());
        }
    }
    return nullptr;
}

template <typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::printInorder()
{
    printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in.  Use recursive algorithm.
    //Note that this prints using an Inorder, Depth-first search
    //but you may want to do something else when "visiting" the node....
    //like moving visited data to another datastructure
    //Don't forget your base case!
    if(node == nullptr)
        return;
    printInorder(node->Left());
    print(cout, node->Data());
    printInorder(node->Right());
}

template <typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
    if(data.Synopsis == "")
        out << data.Year << "," << data.Award << "," << data.Winner <<"," << data.Name << "," << data.Film << endl;
    else{
        out << data.Name << "," << data.Year << "," << data.Nominations <<"," << data.Rating << "," << data.Duration<<
            "," << data.Genre1 << "," << data.Genre2 << "," << data.Release << "," << data.Metacritic <<"," << data.Synopsis
            << endl;
    }
}

template <typename DATATYPE, typename KEYTYPE>
void binary_search_tree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
    setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * binary_search_tree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot, KEYTYPE value)
{

    /* Given a binary search tree and a key, this function deletes the key
    and returns the new root */

    // base case
    if (aRoot == nullptr) return aRoot;

    // If the key to be deleted is smaller than the aRoot's key,
    // then it lies in left subtree
    if (value < aRoot->Key())
        aRoot->setLeft(deleteNode(aRoot->Left(), value));

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (value > aRoot->Key())
        aRoot->setRight(deleteNode(aRoot->Right(), value));

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (aRoot->Left() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
            delete aRoot;
            return temp;
        }
        else if (aRoot->Right() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
            delete aRoot;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

        // Copy the inorder successor's content to this node
        aRoot->setKey(temp->Key());
        aRoot->setData(temp->Data());

        // Delete the inorder successor
        aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
    }
    return aRoot;
}


// Find the node with min key
// Traverse the left sub-binary_search_tree recursively
// till left sub-binary_search_tree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * binary_search_tree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * current = node;

    /* loop down to find the leftmost leaf */
    while (current->Left() != nullptr)
        current = current->Left();

    return current;
}

// Find the node with max key
// Traverse the right sub-binary_search_tree recursively
// till right sub-binary_search_tree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * binary_search_tree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * tempNode = node;
    if (node == nullptr)
        tempNode = nullptr;
    else if (node->Right())
        tempNode = max(node->Right());
    else
        tempNode = node;

    return tempNode;
}

#endif //TEMPFINAL_BINARY_SEARCH_TREE_HPP
