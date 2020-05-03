//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_READ_FROM_FILE_H
#define TEMPFINAL_READ_FROM_FILE_H
#include <fstream>
#include <iostream>
#include <vector>
#include "Binary_Search_Tree.h"
void readFromFile1(std::ifstream& inFile, binary_search_tree<Final, string>& tree, vector<Final>& myVector);
void readFromFile2(std::ifstream& inFile, binary_search_tree<Final, string>& picTree, vector<Final>& myVector);
#endif //TEMPFINAL_READ_FROM_FILE_H
