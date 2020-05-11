//
// Created by BK Allen on 5/2/20.
//
#include "Functions.h"
#include "Menus.h"


/// @brief Searches for exact matches
/// @param user_input
/// @param to_search
/// @param tree_pointer
/// @param tree_housing
void precise_search(std::string &user_input, std::string &to_search, Node<Node_Struct, std::string> *tree_pointer,
                    Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    if (tree_pointer == nullptr) {
        return;
    }
    precise_search(user_input, to_search, tree_pointer->leaf_left(), tree_housing);
    if (to_search == "Name") {
        if (tree_pointer->Data().Name == user_input) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Film") {
        if (tree_pointer->Data().Film == user_input) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Year") {
        if (tree_pointer->Data().Year == user_input) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Nominations") {
        if (std::to_string(tree_pointer->Data().Nominations) == (user_input)) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Rating") {
        if (std::to_string(tree_pointer->Data().Rating) == (user_input)) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Genre") {
        if (tree_pointer->Data().Genre1 == user_input || tree_pointer->Data().Genre2 == user_input) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Release") {
        if (tree_pointer->Data().Release == user_input) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    }
    precise_search(user_input, to_search, tree_pointer->leaf_right(), tree_housing);
}

/// @brief
/// @param user_input
/// @param to_search
/// @param tree_pointer
/// @param tree_housing
void sub_string_search(std::string &user_input, std::string &to_search, Node<Node_Struct, std::string> *tree_pointer,
                       Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    if (tree_pointer == nullptr) {
        return;
    }
    sub_string_search(user_input, to_search, tree_pointer->leaf_left(), tree_housing);
    if (to_search == "Name") {
        if (tree_pointer->Data().Name.find(user_input) != std::string::npos) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Film") {
        if (tree_pointer->Data().Film.find(user_input) != std::string::npos) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Year") {
        if (tree_pointer->Data().Year.find(user_input) != std::string::npos) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Nominations") {
        if (std::to_string(tree_pointer->Data().Nominations).find(user_input) != std::string::npos) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Rating") {
        if (std::to_string(tree_pointer->Data().Rating).find(user_input) != std::string::npos) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Genre") {
        if (tree_pointer->Data().Genre1.find(user_input) != std::string::npos ||
            tree_pointer->Data().Genre2.find(user_input) != std::string::npos) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Release") {
        if (tree_pointer->Data().Release.find(user_input) != std::string::npos) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    }
    sub_string_search(user_input, to_search, tree_pointer->leaf_right(), tree_housing);

}
/// @brief
/// @param user_input
/// @param tree_housing
void add_entry(std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    Node_Struct newRecord;
    if (user_input != "pictures.csv") {
        std::cout << "Year: " << std::endl;
        std::cin >> newRecord.Year;
        std::cout << "Award: " << std::endl;
        std::getline(std::cin.ignore(), newRecord.Award);
        std::cout << "Winner: " << std::endl;
        std::cin >> newRecord.Winner;
        std::cout << "Name: " << std::endl;
        std::getline(std::cin.ignore(), newRecord.Name);
        std::cout << "Film: " << std::endl;
        std::getline(std::cin.ignore(), newRecord.Film);
        tree_housing.add_node(newRecord.Name, newRecord);
    } else {
        std::cout << "Name: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, newRecord.Name);
        std::cout << "Year: " << std::endl;
        std::getline(std::cin, newRecord.Year);
        std::cout << "Nominations: " << std::endl;
        std::cin >> newRecord.Nominations;
        std::cout << "Rating: " << std::endl;
        std::cin >> newRecord.Rating;
        std::cout << "Duration: " << std::endl;
        std::cin >> newRecord.Duration;
        std::cout << "Primary Genre: " << std::endl;
        std::getline(std::cin.ignore(), newRecord.Genre1);
        std::cout << "Secondary Genre:" << std::endl;
        std::getline(std::cin.ignore(), newRecord.Genre2);
        std::cout << "Release:" << std::endl;
        std::getline(std::cin.ignore(), newRecord.Release);
        std::cout << "Meta-critic:" << std::endl;
        std::cin >> newRecord.Meta_Critic;
        std::cout << "Synopsis:" << std::endl;
        std::getline(std::cin.ignore(), newRecord.Synopsis);
        tree_housing.add_node(newRecord.Name, newRecord);
    }
    tree_housing.display(std::cout, newRecord);
}

/// @brief
/// @param tree
void delete_entry(Binary_Search_Tree<Node_Struct, std::string> &tree) {
    Node_Struct record;
    std::cout << "Enter an actor or actress to search for: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, record.Name);
    if (tree.find(record.Name) != nullptr) {
        tree.remove(record.Name);
        std::cout << "I have deleted " << RED_BOLD << record.Name << CLEAR << " for you." << std::endl;
    } else if (tree.find(record.Name = nullptr)) {
        std::cout << "No matches!" << std::endl;
    }
}

/// @brief
/// @param user_input
/// @param tree_housing
void modify_entry(std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    auto choice = 0;
    std::string string_housing;
    Node_Struct alter_this;
    Node<Node_Struct, std::string> *tree_pointer;
    std::cout << "Enter an actor or actress to search for: " << std::endl;
    std::getline(std::cin.ignore(), string_housing);
    tree_pointer = tree_housing.find(string_housing);
    if (tree_pointer == nullptr) {
        std::cout << "No matches!" << std::endl;
    } else {
        if ("pictures.csv" == user_input) {
            modify_menu_display();
            choice = get_menu_choice(8);
            alter_this = tree_pointer->Data();
            switch (choice) {
                case 1:
                    std::cout << "Name: " << std::endl;
                    std::getline(std::cin.ignore(), alter_this.Name);
                    break;
                case 2:
                    std::cout << "Year: " << std::endl;
                    std::cin >> alter_this.Year;
                    break;
                case 3:
                    std::cout << "Nominations(integer): " << std::endl;
                    std::cin >> alter_this.Nominations;
                    break;
                case 4:
                    std::cout << "Rating(Decimal): " << std::endl;
                    std::cin >> alter_this.Rating;
                    break;
                case 5:
                    std::cout << "Length: " << std::endl;
                    std::cin >> alter_this.Duration;
                    break;
                case 6:
                    std::cout << "First Genre: " << std::endl;
                    std::cin >> alter_this.Genre1;
                    break;
                case 7:
                    std::cout << "Secondary Genre: " << std::endl;
                    std::cin >> alter_this.Genre2;
                    break;
                case 8:
                    enter_program();
                case 0:
                    exit_program();
                default:
                    std::cout << "Invalid Input!" << std::endl;
                    break;

            }
            tree_pointer->setData(alter_this);
            std::cout << "New record added:" << std::endl;
            tree_housing.display(std::cout, alter_this);

        } else if ("actor-actress.csv" == user_input || "Nominations.csv" == user_input) {
            auto menu_choice = 0;
            modify__menu_display();
            menu_choice = get_menu_choice(5);
            alter_this = tree_pointer->Data();
            switch (menu_choice) {
                case 1:
                    std::cout << "Year: " << std::endl;
                    std::cin >> alter_this.Year;
                    break;
                case 2:
                    std::cout << "Award: " << std::endl;
                    std::getline(std::cin.ignore(), alter_this.Award);
                    break;
                case 3:
                    std::cout << "Winner(binary): " << std::endl;
                    std::cin >> alter_this.Winner;
                    break;
                case 4:
                    std::cout << "Name: " << std::endl;
                    std::getline(std::cin.ignore(), alter_this.Name);
                    break;
                case 5:
                    std::cout << "Film:" << std::endl;
                    std::getline(std::cin.ignore(), alter_this.Film);
                    break;
                case 6:
                    exit_program();
                default:
                    break;
            }
            tree_pointer->setData(alter_this);
            std::cout << "Modified Entry: ";
            tree_housing.display(std::cout, alter_this);
        } else {
            std::cout << "No Matches!" << std::endl;
        }
    }
}
/// @brief
/// @param to_merge
/// @param vector_housing
/// @param lhs
/// @param middle
/// @param rhs
void merger(const std::string &to_merge, std::vector<Node_Struct> &vector_housing, int lhs, int middle,
            int rhs) {
    auto i = 0;
    auto j = 0;
    auto k = 0;
    auto x = middle - lhs + 1;
    auto y = rhs - middle;
    std::vector<Node_Struct> temp_vector_housing;
    std::vector<Node_Struct> temp_vector_housing_2;
    for (i = 0; i < x; i++)
        temp_vector_housing.push_back(vector_housing[lhs + i]);
    for (j = 0; j < y; j++)
        temp_vector_housing_2.push_back(vector_housing[middle + j + 1]);
    i = 0, j = 0, k = lhs;
    if (to_merge == "Film") {
        while (i < x && j < y) {
            if (temp_vector_housing[i].Film <= temp_vector_housing_2[j].Film) {
                vector_housing[k] = temp_vector_housing[i];
                i++;
            } else {
                vector_housing[k] = temp_vector_housing_2[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Year") {
        while (i < x && j < y) {
            if (temp_vector_housing[i].Year <= temp_vector_housing_2[j].Year) {
                vector_housing[k] = temp_vector_housing[i];
                i++;
            } else {
                vector_housing[k] = temp_vector_housing_2[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Rating") {
        while (i < x && j < y) {
            if (temp_vector_housing[i].Rating <= temp_vector_housing_2[j].Rating) {
                vector_housing[k] = temp_vector_housing[i];
                i++;
            } else {
                vector_housing[k] = temp_vector_housing_2[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Nominations") {
        while (i < x && j < y) {
            if (temp_vector_housing[i].Nominations <= temp_vector_housing_2[j].Nominations) {
                vector_housing[k] = temp_vector_housing[i];
                i++;
            } else {
                vector_housing[k] = temp_vector_housing_2[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Genre1") {
        while (i < x && j < y) {
            if (temp_vector_housing[i].Rating <= temp_vector_housing_2[j].Rating) {
                vector_housing[k] = temp_vector_housing[i];
                i++;
            } else {
                vector_housing[k] = temp_vector_housing_2[j];
                j++;
            }
            k++;
        }
    }
    while (i < x) {
        vector_housing[k] = temp_vector_housing[i];
        i++, k++;
    }
    while (j < y) {
        vector_housing[k] = temp_vector_housing_2[j];
        j++, k++;
    }
    temp_vector_housing.clear();
    temp_vector_housing_2.clear();
}
/// @brief
/// @param to_sort
/// @param vector_housing
/// @param lhs
/// @param rhs
void sort(const std::string &to_sort, std::vector<Node_Struct> &vector_housing, int lhs, int rhs) {
    if (lhs < rhs) {
        auto m = lhs + (rhs - lhs) / 2;
        sort(to_sort, vector_housing, lhs, m);
        sort(to_sort, vector_housing, m + 1, rhs);
        merger(to_sort, vector_housing, lhs, m, rhs);
    } else { return; }
}
/// @brief
/// @param user_input
/// @param node
/// @param tree_housing
void write_to_file(const std::string &user_input, Node<Node_Struct, std::string> *node,
                   Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    if (node == nullptr) { return; }
    std::ofstream output("new_" + user_input);
    to_file(output, node, tree_housing);
    output.close();
}
/// @brief
/// @param outfile
/// @param node
/// @param tree_housing
void to_file(std::ofstream &outfile, Node<Node_Struct, std::string> *node,
             Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    if (node == nullptr) { return; }
    to_file(outfile, node->leaf_left(), tree_housing);
    tree_housing.display(outfile, node->Data());
    to_file(outfile, node->leaf_right(), tree_housing);
}
/// @brief
/// @param vector_storage
void vector_to_console(std::vector<Node_Struct> &vector_storage) {
    for (const auto &iterator : vector_storage) {
        (iterator.Genre2.empty() ?
         std::cout
                 << GREEN_BOLD << "\nYear: " << CLEAR
                 << iterator.Year << std::endl
                 << GREEN_BOLD << "Award: " << CLEAR
                 << iterator.Award << std::endl
                 << GREEN_BOLD << "Winner: " << CLEAR
                 << iterator.Winner << std::endl
                 << GREEN_BOLD << "Name: " << CLEAR
                 << iterator.Name << std::endl
                 << GREEN_BOLD << "Film: " << CLEAR
                 << iterator.Film << std::endl
                                 :
         std::cout
                 << GREEN_BOLD << "\nName:" << CLEAR
                 << iterator.Name << std::endl
                 << GREEN_BOLD << "Year: " << CLEAR
                 << iterator.Year << std::endl
                 << GREEN_BOLD << "Nomination: " << CLEAR
                 << iterator.Nominations << std::endl
                 << GREEN_BOLD << "Rating: " << CLEAR
                 << iterator.Rating << std::endl
                 << GREEN_BOLD << "Duration: " << CLEAR
                 << iterator.Duration << std::endl
                 << GREEN_BOLD << "Genre 1: " << CLEAR
                 << iterator.Genre1 << std::endl
                 << GREEN_BOLD << "Genre 2: " << CLEAR
                 << iterator.Genre2 << std::endl
                 << GREEN_BOLD << "Release: " << CLEAR
                 << iterator.Release << std::endl
                 << GREEN_BOLD << "Meta-Critic: " << CLEAR
                 << iterator.Meta_Critic << std::endl
                 << GREEN_BOLD << "Synopsis: " << CLEAR
                 << iterator.Synopsis << std::endl
        );
    }

}
