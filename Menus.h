//
// Created by BK Allen on 5/2/20.
// See implementation file for comments.
//

#ifndef TEMPFINAL_MENUS_H
#define TEMPFINAL_MENUS_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Read_From_File.h"
#include "Functions.h"


void add_sub_menu(std::string user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void change_sub_menu(std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void delete_sub_menu(const std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree);

void sort_sub_menu(const std::string &user_input, std::vector<Node_Struct> &vector_housing,
                   Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void pictures_sort_sub_menu(const std::string &user_input, std::vector<Node_Struct> &vector_housing,
                            Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void search_sub_menu_(Node<Node_Struct, std::string> *tree_pointer, std::string to_search, std::string user_input,
                      Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void pictures_search_sub_menu(const std::string &user_input, Node<Node_Struct, std::string> *tree_pointer,
                              Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void search_sub_menu(const std::string &user_input, Node<Node_Struct, std::string> *tree_pointer,
                     Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void sub_menu(std::string user_input, std::vector<Node_Struct> &vector_housing, std::ifstream &infile,
              Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void enter_program();

#endif //TEMPFINAL_MENUS_H
