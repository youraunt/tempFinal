//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_FUNCTIONS_H
#define TEMPFINAL_FUNCTIONS_H

#include<iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Binary_Search_Tree.hpp"

void addNewRecord(binary_search_tree<Final, string> &tree, std::string &fileName);

void deleteRecord(binary_search_tree<Final, string> &tree);

void modifyRecord(binary_search_tree<Final, string> &tree, std::string &fileName);

void
partialSearchRecord(binary_search_tree<Final, string> &tree, Node<Final, string> *TreePtr, std::string &searchField,
                    std::string &field);

void exactSearchRecord(binary_search_tree<Final, string> &tree, Node<Final, string> *TreePtr, std::string &searchField,
                       std::string &field);

void sortF(vector<Final> &myVector, int l, int r, std::string sortField);

void mergeF(vector<Final> &myVector, int l, int m, int r, const std::string& mergeField);

void printOutFile(binary_search_tree<Final, string> &tree, Node<Final, string> *node, std::string fileName);

void printRecursive(binary_search_tree<Final, string> &tree, Node<Final, string> *node, std::ofstream &updateFile);

void printOutVector(vector<Final> &myVector);

#endif //TEMPFINAL_FUNCTIONS_H
