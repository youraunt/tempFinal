//
// Created by BK Allen on 5/2/20.
//

#include "Menus.h"


void add_sub_menu(std::string user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    std::cout
            << BLUE_BOLD
            << "Current File: "
            << CLEAR
            << user_input << std::endl
            << "1. Add" << std::endl
            << "2. Main Menu" << std::endl;
    auto choice = get_menu_choice(2);
    if (choice == 1) {
        add_entry(user_input, tree_housing);
    } else if (choice == 2) { enter_program(); }
}

void
change_sub_menu(std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    std::cout
            << BLUE_BOLD
            << "Current File: "
            << CLEAR
            << user_input << std::endl
            << "1. Modify" << std::endl
            << "2. Main Menu" << std::endl;
    auto choice = get_menu_choice(2);
    if (choice == 1) {
        modify_entry(user_input, tree_housing);
    } else if (choice == 2) {
        enter_program();
    }

}

void
delete_sub_menu(const std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree) {
    std::cout << BLUE_BOLD << "Current File: " << CLEAR
              << user_input << std::endl
              << "1. Delete" << std::endl
              << "2. Main Menu" << std::endl;
    auto choice = get_menu_choice(2);
    if (choice == 1) {
        delete_entry(tree);
    } else if (choice == 2) {
        enter_program();
    }
}

void search_sub_menu_(Node<Node_Struct, std::string> *tree_pointer, std::string to_search, std::string user_input,
                      Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    precise_or_partial_menu();
    auto choice = get_menu_choice(3);
    switch (choice) {
        case 1:
            sub_string_search(user_input, to_search, tree_pointer, tree_housing);
            enter_program();
            break;
        case 2:
            precise_search(user_input, to_search, tree_pointer, tree_housing);
            enter_program();
            break;
        case 3:
            enter_program();
            break;
        case 0:
            exit_program();
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;
    }

}

void sort_sub_menu(const std::string &user_input, std::vector <Node_Struct> &vector_housing,
                   Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    std::cout << BLUE_BOLD << "Current File: " << CLEAR << user_input << std::endl;
    sort_menu_display();
    auto choice = get_menu_choice(4);
    switch (choice) {
        case 1:
            sort("Year", vector_housing, 0, vector_housing.size() - 1);
            vector_to_console(vector_housing);
            enter_program();
            break;
        case 2:
            sort("Film", vector_housing, 0, vector_housing.size() - 1);
            vector_to_console(vector_housing);
            enter_program();
            break;
        case 3:
            tree_housing.in_order();
            enter_program();
            break;
        case 4:
            enter_program();
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;
    }
}

void pictures_sort_sub_menu(const std::string &user_input, std::vector <Node_Struct> &vector_housing,
                            Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {

    std::cout << BLUE_BOLD << "Current File: " << CLEAR << user_input << std::endl;
    sort_pictures_sub_display();
    auto choice = get_menu_choice(7);
    switch (choice) {
        case 1:
            sort("Year", vector_housing, 0, vector_housing.size() - 1);
            vector_to_console(vector_housing);
            enter_program();
            break;
        case 2:
            tree_housing.in_order();
            enter_program();
            break;
        case 3:
            sort("Nominations", vector_housing, 0, vector_housing.size() - 1);
            vector_to_console(vector_housing);
            enter_program();
            break;
        case 4:
            sort("Rating", vector_housing, 0, vector_housing.size() - 1);
            vector_to_console(vector_housing);
            enter_program();
            break;
        case 5:
            sort("Genre1", vector_housing, 0, vector_housing.size() - 1);
            vector_to_console(vector_housing);
            enter_program();
            break;
        case 6:
            enter_program();
            break;
        case 0:
            exit_program();
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;
    }

}

void pictures_search_sub_menu(const std::string &user_input, Node<Node_Struct, std::string> *tree_pointer,
                              Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    std::string string_housing;
    std::cout << SEARCH_SUB_MENU_TITLE << BLUE_BOLD << "Current File: " << CLEAR << user_input << std::endl;
    picture_search_sub_display();
    auto choice = get_menu_choice(6);
    switch (choice) {
        case 1:
            std::cout << "Enter Year: " << std::endl
                      << GREEN << "> " << CLEAR;
            std::getline(std::cin.ignore(), string_housing);
            search_sub_menu_(tree_pointer, "Year", string_housing, tree_housing);
            break;
        case 2:
            std::cout << "Enter Name: " << std::endl
                      << GREEN << "> " << CLEAR;
            std::getline(std::cin.ignore(), string_housing);
            search_sub_menu_(tree_pointer, "Name", string_housing, tree_housing);
            enter_program();
            break;
        case 3:
            std::cout << "Enter Nomination: " << std::endl
                      << GREEN << "> " << CLEAR;
            getline(std::cin.ignore(), string_housing);
            search_sub_menu_(tree_pointer, "Nominations", string_housing, tree_housing);
            break;
        case 4:
            std::cout << "Enter Genre: " << std::endl
                      << GREEN << "> " << CLEAR;
            std::getline(std::cin.ignore(), string_housing);
            search_sub_menu_(tree_pointer, "Genre", string_housing, tree_housing);
            break;
        case 5:
            std::cout << "Enter Release Month: " << std::endl
                      << GREEN << "> " << CLEAR;
            std::getline(std::cin.ignore(), string_housing);
            search_sub_menu_(tree_pointer, "Release", string_housing, tree_housing);
            break;
        case 6:
            enter_program();
            break;
        case 0:
            exit_program();
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;
    }
}

void search_sub_menu(const std::string &user_input, Node<Node_Struct, std::string> *tree_pointer,
                     Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    std::string temporary_string_housing;
    search_sub_menu_display();
    auto choice = get_menu_choice(5);
    switch (choice) {
        case 1:
            std::cout << "Enter year:" << std::endl
                      << GREEN << "> " << CLEAR;
            getline(std::cin.ignore(), temporary_string_housing);
            search_sub_menu_(tree_pointer, "Year", temporary_string_housing, tree_housing);
            break;
        case 2:
            std::cout << "Enter Name:" << std::endl
                      << GREEN << "> " << CLEAR;
            getline(std::cin.ignore(), temporary_string_housing);
            search_sub_menu_(tree_pointer, "Name", temporary_string_housing, tree_housing);
            break;
        case 3:
            std::cout << "Enter Film:" << std::endl
                      << GREEN << "> " << CLEAR;
            getline(std::cin.ignore(), temporary_string_housing);
            search_sub_menu_(tree_pointer, "Film", temporary_string_housing, tree_housing);
            break;
        case 4:
            enter_program();
            break;
        case 0:
            exit_program();
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;
    }
}

void sub_menu(std::string user_input, std::vector <Node_Struct> &vector_housing, std::ifstream &infile,
              Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    auto tree_pointer = tree_housing._root();
    std::cout << BLUE_BOLD << "Current File: " << CLEAR << user_input << std::endl;
    sub_menu_display();
    auto choice = get_menu_choice(7);
    switch (choice) {
        case 1:
            if (user_input == "actor-actress.csv" || user_input == "Nominations.csv") {
                search_sub_menu(user_input, tree_pointer, tree_housing);
            } else if (user_input == "pictures.csv") {
                pictures_search_sub_menu(user_input, tree_pointer, tree_housing);
            }
            enter_program();
            break;
        case 2:
            add_sub_menu(user_input, tree_housing);
            enter_program();
            break;
        case 3:
            change_sub_menu(user_input, tree_housing);
            enter_program();
            break;
        case 4:
            delete_sub_menu(user_input, tree_housing);
            enter_program();
            break;
        case 5:
            write_to_file(user_input, tree_housing._root(), tree_housing);
            enter_program();
            break;
        case 6:
            if (user_input == "actor-actress.csv" || user_input == "Nominations.csv") {
                sort_sub_menu(user_input, vector_housing, tree_housing);
            } else if (user_input == "pictures.csv") {
                pictures_sort_sub_menu(user_input, vector_housing, tree_housing);
            }
            enter_program();
            break;
        case 7:
            enter_program();
            break;
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;

    }

}


void enter_program() {
    std::ifstream infile;
    std::string csv_file_name;
    std::vector<Node_Struct> storage_vector;
    auto *actor_actress_binary_search_tree = new Binary_Search_Tree<Node_Struct, std::string>;
    auto *picture_binary_search_tree = new Binary_Search_Tree<Node_Struct, std::string>;
    auto *nomination_binary_search_tree = new Binary_Search_Tree<Node_Struct, std::string>;
    main_menu_display();
    auto choice = get_menu_choice(4);
    switch (choice) {
        case 1:
            csv_file_name = R"(actor-actress.csv)";
            infile.open("actor-actress.csv", std::ios_base::in);
            actor_in(infile, storage_vector, *actor_actress_binary_search_tree);
            sub_menu(csv_file_name, storage_vector, infile, *actor_actress_binary_search_tree);
            infile.close();
            break;
        case 2:
            csv_file_name = R"(pictures.csv)";
            picture_in(infile, *picture_binary_search_tree, storage_vector);
            sub_menu(csv_file_name, storage_vector, infile, *picture_binary_search_tree);
            break;
        case 3:
            csv_file_name = R"(Nominations.csv)";
            infile.open("Nominations.csv", std::ios_base::in);
            actor_in(infile, storage_vector, *nomination_binary_search_tree);
            sub_menu(csv_file_name, storage_vector, infile, *nomination_binary_search_tree);
            break;
        case 0:
            exit_program();
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;
    }
    storage_vector.clear();
}