//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_BINARY_SEARCH_TREE_H
#define TEMPFINAL_BINARY_SEARCH_TREE_H

#include <iostream>
#include "Node.h"

using namespace std;

// Binary Search Tree class
template<typename data_type, typename key_type>
class binary_search_tree {
private:
    Node<data_type, key_type> *root;

    Node<data_type, key_type> *find_node(key_type key, Node<data_type, key_type> *node);

    Node<data_type, key_type> *delete_node(Node<data_type, key_type> *_root, key_type key);

    void insert_node(key_type key, Node<data_type, key_type> *leaf, data_type &data);

    void free_node(Node<data_type, key_type> *leaf);

    void in_order(Node<data_type, key_type> *node);


public:
    binary_search_tree<data_type, key_type>();

    ~binary_search_tree<data_type, key_type>();

    Node<data_type, key_type> *find(key_type key);

    Node<data_type, key_type> *find_min(Node<data_type, key_type> *node);

    Node<data_type, key_type> *find_max(Node<data_type, key_type> *node);

    Node<data_type, key_type> *_root() { return root; }

    void initialize_root(Node<data_type, key_type> *this_root) { root = this_root; }

    void add_node(key_type key, data_type &data);

    void in_order();

    void to_console(ostream &out, const data_type &d);

    void delete_node(key_type k);


};

#endif //TEMPFINAL_BINARY_SEARCH_TREE_H
