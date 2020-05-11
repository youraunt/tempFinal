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
    auto choice = 0;
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
    } while (choice > number_of_choices || choice < 0);
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

inline bool picture_search_sub_display() {
    std::cout
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

inline bool modify__menu_display() {
    std::cout
            << YELLOW
            << "Please select a way to search and press [Enter]." << std::endl
            << CLEAR << "Select which section you want to modify." << std::endl
            << "1. Year" << std::endl
            << "2. Award" << std::endl
            << "3. Winner" << std::endl
            << "4. Name" << std::endl
            << "5. Film" << std::endl
            << "0. Exit Program" << std::endl;
    return true;
}

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
