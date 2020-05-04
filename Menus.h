//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_MENUS_H
#define TEMPFINAL_MENUS_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Read_From_File.h"
#include "Functions.h"


void add_sub_menu(std::string user_input, binary_search_tree<Final, string> &tree_housing);

void change_sub_menu(std::string &user_input, binary_search_tree<Final, string> &tree_housing, unsigned int choice);

void delete_sub_menu(const std::string &user_input, binary_search_tree<Final, string> &tree, unsigned choice);

void sort_sub_menu(const std::string &user_input, vector<Final> &vector_housing,
                   binary_search_tree<Final, string> &tree_housing);

void pictures_sort_sub_menu(const std::string &user_input, vector<Final> &vector_housing,
                           binary_search_tree<Final, string> &tree_housing);

void menuSubSearch(Node<Final, string> *tree_pointer, std::string to_search, std::string user_input,
                   binary_search_tree<Final, string> &tree_housing);

void pictures_search_sub_menu(const std::string &user_input, Node<Final, string> *tree_pointer,
                              binary_search_tree<Final, string> &tree_housing);

void search_sub_menu(const std::string &user_input, Node<Final, std::string> *tree_pointer,
                     binary_search_tree<Final, std::string> &tree_housing);

void sub_menu(std::string user_input, vector<Final> &vector_housing, std::ifstream &infile,
              binary_search_tree<Final, std::string> &tree_housing, unsigned int choice);

void enter_program();

#endif //TEMPFINAL_MENUS_H
