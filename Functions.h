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

#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;
/// @brief colors
#define CLEAR "\033[0m"
#define RED_BOLD "\033[1m\033[31m"
#define RED "\033[31m"
#define YELLOW_BOLD "\033[1m\033[33m"
#define YELLOW "\033[33m"
#define MAGENTA_BOLD "\033[1m\033[35m"
#define MAGENTA "\033[35m"
#define CYAN_BOLD "\033[1m\033[36m"
#define CYAN "\033[36m"
#define BLUE_BOLD "\033[1m\033[34m"
#define BLUE "\033[34m"
#define BLACK_BOLD "\033[1m\033[30m"
#define BLACK "\033[30m"
#define GREEN_BOLD "\033[1m\033[32m"
#define GREEN "\033[32m"
#define WHITE_BOLD "\033[1m\033[37m"


/// @brief Exits program successfully with message
[[noreturn]] inline void exit_program() {
    std::cout << "Exiting program!" << std::endl;
    /// @brief I used EXIT_SUCCESS here to unwind the stack
    exit(EXIT_SUCCESS);
}

[[noreturn]] inline void unknown_input() {
    std::cerr << "\nError?! Unknown input.\n" << std::endl;
    exit_program();
}

[[noreturn]] inline void fileNotFound() {
    std::cout << "File not found!" << std::endl
              << "Exiting Program!" << std::endl;
    /// @brief winds down stack
    exit(EXIT_FAILURE);
}

void add_entry(std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void delete_entry(Binary_Search_Tree<Node_Struct, std::string> &tree);

void modify_entry(std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void
sub_string_search(std::string &user_input, std::string &to_search, Node<Node_Struct, std::string> *tree_pointer,
                  Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void precise_search(std::string &user_input, std::string &to_search, Node<Node_Struct, std::string> *tree_pointer,
                    Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void sort(const std::string &to_sort,std:: vector<Node_Struct> &vector_housing, int lhs, int rhs);

void merger(const std::string &to_merge, std::vector<Node_Struct> &vector_housing, int lhs, int middle,
            int rhs);

void
write_to_file(const std::string &user_input, Node<Node_Struct, std::string> *node,
              Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void
to_file(std::ofstream &outfile, Node<Node_Struct, std::string> *node, Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void vector_to_console(std::vector<Node_Struct> &vector_storage);

#endif //TEMPFINAL_FUNCTIONS_H
