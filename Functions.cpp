//
// Created by BK Allen on 5/2/20.
//
#include "Functions.h"
#include "Menus.h"
#include <string>

using namespace std;
/// @brief Searches for exact matches
/// @param user_input
/// @param to_search
/// @param tree_pointer
/// @param tree_housing
void precise_search(std::string &user_input, std::string &to_search, Node<Node_Struct, string> *tree_pointer,
                    Binary_Search_Tree<Node_Struct, string> &tree_housing) {
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
        if (to_string(tree_pointer->Data().Nominations) == (user_input)) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Rating") {
        if (to_string(tree_pointer->Data().Rating) == (user_input)) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Genre") {
        if (tree_pointer->Data().Genre1 == user_input || tree_pointer->Data().Genre2 == user_input) {
            tree_housing.display(std::cout, tree_pointer->Data());
        }
    } else if (to_search == "Release") {
        if (tree_pointer->Data().Release == user_input) {
            tree_housing.display(cout, tree_pointer->Data());
        }
    }
    precise_search(user_input, to_search, tree_pointer->leaf_right(), tree_housing);
}

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
            tree_housing.display(cout, tree_pointer->Data());
        }
    } else if (to_search == "Nominations") {
        if (to_string(tree_pointer->Data().Nominations).find(user_input) != std::string::npos) {
            tree_housing.display(cout, tree_pointer->Data());
        }
    } else if (to_search == "Rating") {
        if (to_string(tree_pointer->Data().Rating).find(user_input) != std::string::npos) {
            tree_housing.display(cout, tree_pointer->Data());
        }
    } else if (to_search == "Genre") {
        if (tree_pointer->Data().Genre1.find(user_input) != std::string::npos ||
            tree_pointer->Data().Genre2.find(user_input) != std::string::npos) {
            tree_housing.display(cout, tree_pointer->Data());
        }
    } else if (to_search == "Release") {
        if (tree_pointer->Data().Release.find(user_input) != std::string::npos) {
            tree_housing.display(cout, tree_pointer->Data());
        }
    }
    sub_string_search(user_input, to_search, tree_pointer->leaf_right(), tree_housing);

}

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
        std::cin.ignore();
        std::getline(std::cin, newRecord.Genre1);
        std::cout << "Secondary Genre:" << std::endl;
        std::getline(cin, newRecord.Genre2);
        std::cout << "Release:" << std::endl;
        std::getline(std::cin, newRecord.Release);
        std::cout << "Meta-critic:" << std::endl;
        std::cin >> newRecord.Meta_Critic;
        std::cout << "Synopsis:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, newRecord.Synopsis);
        tree_housing.add_node(newRecord.Name, newRecord);
    }
    tree_housing.display(std::cout, newRecord);
}

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

void modify_entry(
        std::string &user_input,
        Binary_Search_Tree<Node_Struct, string> &tree_housing) {
    auto choice = 0;
    Node_Struct changeRecord;
    Node<Node_Struct, string> *treePtr;
    string field;
    std::cout << "Enter an actor or actress to search for: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, field);
    treePtr = tree_housing.find(field);
    if (treePtr == nullptr) {
        std::cout << "No matches!" << std::endl;
    } else {
        if (user_input == "pictures.csv") {
            do {
                modify_menu_display();
                choice = get_menu_choice(8);
                changeRecord = treePtr->Data();
                switch (choice) {
                    case 1: {
                        cout << "Name: " << endl;
                        cin.ignore();
                        getline(cin, changeRecord.Name);
                        break;
                    }
                    case 2: {
                        cout << "Year: " << endl;
                        cin >> changeRecord.Year;
                        break;
                    }
                    case 3: {
                        cout << "Nominations: " << endl;
                        cin >> changeRecord.Nominations;
                        break;
                    }
                    case 4: {
                        cout << "Rating: " << endl;
                        cin >> changeRecord.Rating;
                        break;
                    }
                    case 5: {
                        cout << "Length: " << endl;
                        cin >> changeRecord.Duration;
                        break;
                    }
                    case 6: {
                        cout << "First Genre: " << endl;
                        cin >> changeRecord.Genre1;
                        break;
                    }
                    case 7: {
                        cout << "Secondary Genre: " << endl;
                        cin >> changeRecord.Genre2;
                        break;
                    }
                    case 8:
                        enter_program();
                    case 0:
                        exit_program();
                    default: {
                        std::cout << "Invalid Input!" << std::endl;
                        break;
                    }
                }
                treePtr->setData(changeRecord);
                std::cout << "New record added:" << std::endl;
                tree_housing.display(cout, changeRecord);
            } while (choice != 7);
        } else if (user_input == "actor-actress.csv" || user_input == "Nominations.csv") {
            int menu{};
            std::cout << "Record you want to change is in the database" << std::endl;
            do {
                std::cout << "Input 0 to change Year" << std::endl
                          << "input 1 to change Award" << std::endl
                          << "Input 2 to change winner" << std::endl
                          << "Input 3 to change name" << std::endl
                          << "Input 4 to change film" << std::endl
                          << "input -1 if you want to exit" << std::endl;
                cin >> menu;
                changeRecord = treePtr->Data();
                switch (menu) {
                    case 0: {
                        cout << "Input Year. For example: 2018" << endl;
                        cin >> changeRecord.Year;
                        break;
                    }
                    case 1: {
                        cout << "Input Award." << endl;
                        cin.ignore();
                        getline(cin, changeRecord.Award);
                        break;
                    }
                    case 2: {
                        cout << "Input winner. 0 or 1" << endl;
                        cin >> changeRecord.Winner;
                        break;
                    }
                    case 3: {
                        cout << "Input Name. For example: Birdman" << endl;
                        cin.ignore();
                        getline(cin, changeRecord.Name);
                        break;
                    }
                    case 4: {
                        cout << "Input film" << endl;
                        cin.ignore();
                        getline(cin, changeRecord.Film);
                        break;
                    }
                    default: {
                        break;
                    }
                }
                treePtr->setData(changeRecord);
                cout << "Your modified record is" << endl;
                tree_housing.display(cout, changeRecord);
            } while (menu != -1);
        } else {
            cout << "Sorry. File is not exist" << endl;
        }
    }
}

void merge(const std::string &to_merge, vector<Node_Struct> &vector_housing, int lhs, int middle,
           int rhs) {
    int i, j, k;
    int n1 = middle - lhs + 1;
    int n2 = rhs - middle;

    /* create temp vector*/
    vector<Node_Struct> first, second;

    /* Copy data to temp arrays first[] and second[] */
    for (i = 0; i < n1; i++)
        first.push_back(vector_housing[lhs + i]);
    for (j = 0; j < n2; j++)
        second.push_back(vector_housing[middle + j + 1]);

    /* Merge the temp arrays back into vector*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = lhs; // Initial index of merged subarray
    if (to_merge == "Film") {
        while (i < n1 && j < n2) {
            if (first[i].Film <= second[j].Film) {
                vector_housing[k] = first[i];
                i++;
            } else {
                vector_housing[k] = second[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Year") {
        while (i < n1 && j < n2) {
            if (first[i].Year <= second[j].Year) {
                vector_housing[k] = first[i];
                i++;
            } else {
                vector_housing[k] = second[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Rating") {
        while (i < n1 && j < n2) {
            if (first[i].Rating <= second[j].Rating) {
                vector_housing[k] = first[i];
                i++;
            } else {
                vector_housing[k] = second[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Nominations") {
        while (i < n1 && j < n2) {
            if (first[i].Nominations <= second[j].Nominations) {
                vector_housing[k] = first[i];
                i++;
            } else {
                vector_housing[k] = second[j];
                j++;
            }
            k++;
        }
    } else if (to_merge == "Genre1") {
        while (i < n1 && j < n2) {
            if (first[i].Rating <= second[j].Rating) {
                vector_housing[k] = first[i];
                i++;
            } else {
                vector_housing[k] = second[j];
                j++;
            }
            k++;
        }
    }
    /* Copy the remaining elements of first[], if there
       are any */
    while (i < n1) {
        vector_housing[k] = first[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of second[], if there
       are any */
    while (j < n2) {
        vector_housing[k] = second[j];
        j++;
        k++;
    }
    first.clear();
    second.clear();
}

void sort(const std::string &to_sort, vector<Node_Struct> &vector_housing, int lhs, int rhs) {
    //Merge sort
    if (lhs < rhs) {
        int m = lhs + (rhs - lhs) / 2;
        sort(to_sort, vector_housing, lhs, m);
        sort(to_sort, vector_housing, m + 1, rhs);
        merge(to_sort, vector_housing, lhs, m, rhs);
    }
}

void write_to_file(const std::string &user_input, Node<Node_Struct, string> *node,
                   Binary_Search_Tree<Node_Struct, string> &tree_housing) {
    if (node == nullptr)
        return;
    std::ofstream output("new_" + user_input, std::ios_base::trunc);
    to_file(output, node, tree_housing);
    output.close();
}

void to_file(std::ofstream &outfile, Node<Node_Struct, string> *node,
             Binary_Search_Tree<Node_Struct, string> &tree_housing) {
    if (node == nullptr) {
        return;
    }
    to_file(outfile, node->leaf_left(), tree_housing);
    tree_housing.display(outfile, node->Data());
    to_file(outfile, node->leaf_right(), tree_housing);
}

void vector_to_console(vector<Node_Struct> &vector_storage) {

    for (const auto &iterator : vector_storage) {
        (iterator.Genre2.empty() ?
         cout
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
         cout
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
