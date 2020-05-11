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

/// @brief static const char array to display the menu header
static const char MAIN_MENU_TITLE[] =
        "\n\x1b[36m"
        "-----------------------------------\n"
        "|            Main Menu            |\n"
        "-----------------------------------\n"
        "\x1b[0m";

static const char SEARCH_SUB_MENU_TITLE[] =
        "\n\x1b[36m"
        "-----------------------------------\n"
        "|           Search Menu           |\n"
        "-----------------------------------\n"
        "\x1b[0m";

static const char MENU_TITLE[] =
        "\n\x1b[36m"
        "-----------------------------------\n"
        "|               Menu              |\n"
        "-----------------------------------\n"
        "\x1b[0m";

inline int get_menu_choice(int number_of_choices) {
    int choice = 0;
    do {
        std::cout << GREEN << "> " << CLEAR;
        std::cin >> choice;
        std::cin.ignore();
        if (choice < 0 || choice > number_of_choices) {
            std::cout << "\n" << RED_BOLD << choice << CLEAR
                      << " is not a valid menu choice."
                      << "\nPlease make a selection between 1 and "
                      << number_of_choices << std::endl
                      << "0 to exit." << std::endl;
        }
    } while (choice > number_of_choices);
    return choice;
}

// @brief Function for user facing menu
/// @return true unless specified false by user
inline bool search_sub_menu_display() {
    std::cout
            << SEARCH_SUB_MENU_TITLE
            << YELLOW
            << "Please select a way to search and press [Enter]." << std::endl
            << CLEAR
            << "1. Year" << std::endl
            << "2. Name" << std::endl
            << "3. Film" << std::endl
            << "4. Main Menu" << std::endl
            << "5. Exit Program" << std::endl;
    return true;
}

// @brief Function for user facing menu
/// @return true unless specified false by user
inline bool main_menu_display() {
    std::cout
            << MAIN_MENU_TITLE
            << YELLOW
            << "Please select a Sub-Menu and press [Enter]." << std::endl
            << CLEAR
            << "1. Actor & Actress" << std::endl
            << "2. Pictures" << std::endl
            << "3. Nominations" << std::endl
            << "0. Exit" << std::endl;
    return true;
}

inline bool sub_menu_display() {
    std::cout
            << MENU_TITLE
            << YELLOW
            << "Please select an option and press [Enter]." << std::endl
            << CLEAR
            << "1. Search" << std::endl
            << "2. Add" << std::endl
            << "3. Modify" << std::endl
            << "4. Delete" << std::endl
            << "5. Write to File" << std::endl
            << "6. Sort" << std::endl
            << "7. Main Menu" << std::endl
            << "0. Exit Program" << std::endl;
    return true;
}

inline bool precise_or_partial_menu() {
    std::cout
            << SEARCH_SUB_MENU_TITLE
            << YELLOW
            << "Please select a way to sort and press [Enter]." << std::endl
            << CLEAR
            << "1. Partial Search" << std::endl
            << "2. Precise Search" << std::endl
            << "3. Main Menu" << std::endl
            << "0. Exit Program" << std::endl;
    return true;
}

inline bool sort_menu_display() {
    std::cout
            << MENU_TITLE
            << YELLOW
            << "Please select a category to sort by and press [Enter]." << std::endl
            << CLEAR
            << "1. Year" << std::endl
            << "2. Film" << std::endl
            << "3. Name" << std::endl
            << "4. Main Menu" << std::endl
            << "0. Exit Program" << std::endl;
    return true;
}

inline bool modify_menu_display() {
    std::cout
            << MENU_TITLE
            << YELLOW
            << "Please select a way to modify and press [Enter]." << std::endl
            << CLEAR
            << "1. Name" << std::endl
            << "2. Year" << std::endl
            << "3. Nominations" << std::endl
            << "4. Rating" << std::endl
            << "5. Duration" << std::endl
            << "6. Primary Genre" << std::endl
            << "7. Secondary Genre" << std::endl
            << "8. Main Menu" << std::endl
            << "0. Exit Program" << std::endl;
    return true;
}

inline bool sort_pictures_sub_display() {
    std::cout
            << MENU_TITLE
            << YELLOW
            << "Please select a way to sort and press [Enter]." << std::endl
            << CLEAR
            << "1. Year" << std::endl
            << "2. Film" << std::endl
            << "3. Nominations" << std::endl
            << "4. Sort(rating)" << std::endl
            << "5. Sort(Genre1)" << std::endl
            << "6. Main Menu" << std::endl
            << "0. Exit Program" << std::endl;
    return true;

}

inline bool picture_search_sub_display(){
    std::cout
            << MENU_TITLE
            << YELLOW
            << "Please select a way to search and press [Enter]." << std::endl
            << CLEAR
            << "1. Year" << std::endl
            << "2. Film" << std::endl
            << "3. Nominations" << std::endl
            << "4. Genre" << std::endl
            << "5. Release" << std::endl
            << "6. Main Menu" << std::endl
            << "0. Exit Program" << std::endl;
    return true;
}


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

void add_entry(std::string &user_input, Binary_Search_Tree<Node_Struct, string> &tree_housing);

void delete_entry(Binary_Search_Tree<Node_Struct, string> &tree);

void modify_entry(std::string &user_input, Binary_Search_Tree<Node_Struct, string> &tree_housing);

void
sub_string_search(std::string &user_input, std::string &to_search, Node<Node_Struct, std::string> *tree_pointer,
                  Binary_Search_Tree<Node_Struct, std::string> &tree_housing);

void precise_search(std::string &user_input, std::string &to_search, Node<Node_Struct, string> *tree_pointer,
                    Binary_Search_Tree<Node_Struct, string> &tree_housing);

void sort(const std::string &to_sort, vector<Node_Struct> &vector_housing, int lhs, int rhs);

void merge(const std::string &to_merge, vector<Node_Struct> &vector_housing, int lhs, int middle,
           int rhs);

void
write_to_file(const std::string &user_input, Node<Node_Struct, string> *node,
              Binary_Search_Tree<Node_Struct, string> &tree_housing);

void
to_file(std::ofstream &outfile, Node<Node_Struct, string> *node, Binary_Search_Tree<Node_Struct, string> &tree_housing);

void vector_to_console(vector<Node_Struct> &vector_storage);

#endif //TEMPFINAL_FUNCTIONS_H
