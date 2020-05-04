//
// Created by BK Allen on 5/2/20.
//

#include "Menus.h"


void add_sub_menu(std::string user_input, binary_search_tree<Final, string> &tree_housing) {
    int choice = 0;
    do {
        std::cout
                << BLUE_BOLD
                << "Current File: "
                << CLEAR
                << user_input << std::endl
                << "1. Add" << std::endl
                << "2. Main Menu" << std::endl
                << GREEN
                << "> "
                << CLEAR;
        std::cin >> choice;
        if (choice == 1) {
            add_entry(user_input, tree_housing);
        } else if (choice == 2) { enter_program(); }
    } while (choice != 2);
}

void
change_sub_menu(std::string &user_input, binary_search_tree<Final, string> &tree_housing, unsigned int choice = 0) {
    do {
        std::cout
                << BLUE_BOLD
                << "Current File: "
                << CLEAR
                << user_input << std::endl
                << "1. Modify" << std::endl
                << "2. Main Menu" << std::endl
                << GREEN
                << "> "
                << CLEAR;
        std::cin >> choice;
        if (choice == 1) {
            modify_entry(user_input, tree_housing, 0);
        } else if (choice == 2) { break; }
    } while (choice != 2);
}

void delete_sub_menu(const std::string &user_input, binary_search_tree<Final, string> &tree, unsigned choice = 0) {
    do {
        std::cout
                << BLUE_BOLD
                << "Current File: "
                << CLEAR
                << user_input << std::endl
                << "1. Delete" << std::endl
                << "2. Main Menu" << std::endl
                << GREEN
                << "> "
                << CLEAR;
        std::cin >> choice;
        if (choice == 1) {
            delete_entry(tree);
        } else if (choice == 2) {
            enter_program();
            break;
        }
    } while (choice != 2);
}

void menuSubSearch(Node<Final, string> *tree_pointer, std::string to_search, std::string user_input,
                   binary_search_tree<Final, string> &tree_housing) {
    auto choice = 0;
    do {
        std::cout
                << SEARCH_SUB_MENU_TITLE
                << BLUE_BOLD
                << "Current File: "
                << CLEAR
                << to_search << std::endl
                << "1. to do exact search" << std::endl
                << "2. to do partial search" << std::endl
                << "3. Main Menu" << std::endl
                << GREEN
                << "> "
                << CLEAR;
        std::cin >> choice;
        switch (choice) {
            case 1:
                exactSearchRecord(user_input, to_search, tree_pointer, tree_housing);
                enter_program();
                break;
            case 2:
                partialSearchRecord(user_input, to_search, tree_pointer, tree_housing);
                enter_program();
                break;
            case 3:
                enter_program();
                break;
            default:
                std::cout << "Invalid Entry" << std::endl;
                break;
        }
    } while (choice != 3);

}

void sort_sub_menu(const std::string &user_input, vector<Final> &vector_housing,
                   binary_search_tree<Final, string> &tree_housing) {
    auto choice = 0;
    std::cout
            << BLUE_BOLD
            << "Current File: "
            << CLEAR
            << user_input << std::endl
            << YELLOW
            << "Please select a way to sort and press [Enter]." << std::endl
            << CLEAR
            << "1. Year" << std::endl
            << "2. Film" << std::endl
            << "3. Name" << std::endl
            << "4. Main Menu" << std::endl
            << GREEN
            << "> "
            << CLEAR;
    std::cin >> choice;
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

void pictures_sort_sub_menu(const std::string &user_input, vector<Final> &vector_housing,
                            binary_search_tree<Final, string> &tree_housing) {
    auto choice = 0;
    do {
        std::cout
                << BLUE_BOLD
                << "Current File: "
                << CLEAR
                << user_input << std::endl
                << "1. Year" << std::endl
                << "2. Film" << std::endl
                << "3. Nominations" << std::endl
                << "4. Sort(rating)" << std::endl
                << "5. Sort(Genre1)" << std::endl
                << "6. Main Menu" << std::endl
                << GREEN
                << "> "
                << CLEAR;
        std::cin >> choice;
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
            default:
                std::cout << "Invalid Entry" << std::endl;
                break;
        }
    } while (choice != 6);
}

void pictures_search_sub_menu(const std::string &user_input, Node<Final, string> *tree_pointer,
                              binary_search_tree<Final, string> &tree_housing) {
    auto choice = 0;
    std::string field;
    std::cout
            << SEARCH_SUB_MENU_TITLE
            << BLUE_BOLD
            << "Current File: "
            << CLEAR
            << user_input << std::endl
            << "1. Year" << endl
            << "2. Film" << endl
            << "3. Nominations" << endl
            << "4. Genre" << endl
            << "5. Release" << endl
            << "6. Main Menu" << endl
            << GREEN
            << "> "
            << CLEAR;
    std::cin >> choice;
    do {
        switch (choice) {
            case 1:
                //std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree_pointer, "Year", field, tree_housing);
                std::cout << "Please input year you want to search:" << std::endl;
                break;
            case 2:
                std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree_pointer, "Name", field, tree_housing);
                enter_program();
                break;
            case 3:
                std::cout << "Please input year you want to search:" << std::endl;
                std::cin.ignore();
                getline(std::cin, field);
                menuSubSearch(tree_pointer, "Nominations", field, tree_housing);
                break;
            case 4:
                std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree_pointer, "Genre", field, tree_housing);
                break;
            case 5:
                std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree_pointer, "Release", field, tree_housing);
                break;
            case 6:
                enter_program();
                break;
            default:
                std::cout << "Invalid Entry" << std::endl;
                break;
        }
    } while (choice != 6);
}

void search_sub_menu(const std::string &user_input, Node<Final, std::string> *tree_pointer,
                     binary_search_tree<Final, std::string> &tree_housing) {
    auto choice = 0;
    std::string temporary_string_housing;
    std::cout
            << SEARCH_SUB_MENU_TITLE
            << "1. Year" << std::endl
            << "2. Name" << std::endl
            << "3. Film" << std::endl
            << "4. Main Menu" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Enter year:" << std::endl
                      << GREEN
                      << "> "
                      << CLEAR;
            cin.ignore();
            getline(cin, temporary_string_housing);
            menuSubSearch(tree_pointer, "Year", temporary_string_housing, tree_housing);
            break;
        case 2:
            std::cout << "Enter Name:" << std::endl
                      << GREEN
                      << "> "
                      << CLEAR;
            cin.ignore();
            getline(cin, temporary_string_housing);
            menuSubSearch(tree_pointer, "Name", temporary_string_housing, tree_housing);
            break;
        case 3:
            std::cout << "Enter Film:" << std::endl
                      << GREEN
                      << "> "
                      << CLEAR;
            cin.ignore();
            getline(cin, temporary_string_housing);
            menuSubSearch(tree_pointer, "Film", temporary_string_housing, tree_housing);
            break;
        case 4:
            enter_program();
            break;
        default:
            std::cout << "Invalid Entry" << std::endl;
            break;
    }
}

void sub_menu(std::string user_input, vector<Final> &vector_housing, std::ifstream &infile,
              binary_search_tree<Final, std::string> &tree_housing, unsigned int choice = 0) {
    auto tree_pointer = tree_housing._root();
    do {
        std::cout
                << BLUE_BOLD
                << "Current File: "
                << CLEAR
                << user_input << std::endl
                << "Please select a Sub-Menu and press [Enter]" << std::endl
                << "1. Search" << std::endl
                << "2. Add" << std::endl
                << "3. Modify" << std::endl
                << "4. Delete" << std::endl
                << "5. Write to File" << std::endl
                << "6 Sort" << std::endl
                << "7. Main Menu" << std::endl
                << GREEN
                << "> "
                << CLEAR;
        std::cin >> choice;
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
                change_sub_menu(user_input, tree_housing, 0);
                enter_program();
                break;
            case 4:
                delete_sub_menu(user_input, tree_housing, 0);
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

    } while (choice != 7);
}


void enter_program(void) {
    auto choice = 0;
    std::ifstream infile;
    std::string csv_file_name;
    std::vector<Final> storage_vector;
    auto *actor_actress_binary_search_tree = new binary_search_tree<Final, std::string>;
    auto *picture_binary_search_tree = new binary_search_tree<Final, std::string>;
    auto *nomination_binary_search_tree = new binary_search_tree<Final, std::string>;

    do {
        std::cout
                << MAIN_MENU_TITLE
                << YELLOW
                << "Please select a Sub-Menu and press [Enter]." << std::endl
                << CLEAR
                << "1. Actor & Actress" << std::endl
                << "2. Pictures" << std::endl
                << "3. Nominations" << std::endl
                << "4. Exit" << std::endl
                << GREEN
                << "> "
                << CLEAR;
        std::cin >> choice;
        switch (choice) {
            case 1:
                csv_file_name = R"(actor-actress.csv)";
                infile.open("actor-actress.csv", std::ios_base::in);
                actor_in(infile, *actor_actress_binary_search_tree, storage_vector);
                sub_menu(csv_file_name, storage_vector, infile, *actor_actress_binary_search_tree, 0);
                break;
            case 2:
                csv_file_name = R"(pictures.csv)";
                picture_in(infile, *picture_binary_search_tree, storage_vector);
                sub_menu(csv_file_name, storage_vector, infile, *picture_binary_search_tree, 0);
                break;
            case 3:
                csv_file_name = R"(Nominations.csv)";
                infile.open("Nominations.csv", std::ios_base::in);
                actor_in(infile, *nomination_binary_search_tree, storage_vector);
                sub_menu(csv_file_name, storage_vector, infile, *nomination_binary_search_tree, 0);
                break;
            case 4:
                exit_program();
            default:
                std::cout << "Invalid Entry" << std::endl;
                break;
        }
    } while (choice != 4);
    storage_vector.clear();

}