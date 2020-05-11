//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_READ_FROM_FILE_H
#define TEMPFINAL_READ_FROM_FILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Binary_Search_Tree.h"

void
actor_in(std::ifstream &infile, std::vector<Node_Struct> &vector_housing,
         Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void
picture_in(std::ifstream &infile, std::vector<Node_Struct> &vector_housing,
           Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

#endif //TEMPFINAL_READ_FROM_FILE_H
