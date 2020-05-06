//
// Created by BK Allen on 5/2/20.
//
#include "Functions.h"
#include <string>

using namespace std;

void exactSearchRecord(std::string &user_input, std::string &to_search, Node<Node_Struct, string> *tree_pointer,
                       Binary_Search_Tree<Node_Struct, string> &tree_housing) {
    //Travel entire tree and find if record is match whichever user input
    if (tree_pointer == nullptr) {
        return;
    }
    exactSearchRecord(user_input, to_search, tree_pointer->leaf_left(), tree_housing);
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
    exactSearchRecord(user_input, to_search, tree_pointer->leaf_right(), tree_housing);
}

void partialSearchRecord(std::string &user_input, std::string &to_search, Node<Node_Struct, std::string> *tree_pointer,
                         Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    //Travel entire tree and find if record is partial match whichever user input
    if (tree_pointer == nullptr) {
        return;
    }
    partialSearchRecord(user_input, to_search, tree_pointer->leaf_left(), tree_housing);
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
    partialSearchRecord(user_input, to_search, tree_pointer->leaf_right(), tree_housing);

}

void add_entry(std::string &user_input, Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
    Node_Struct newRecord;
    if (user_input != "pictures.csv") {
        std::cout << "\nYear: ";
        cin >> newRecord.Year;
        cout << "\nAward: ";
        cin.ignore();
        getline(cin, newRecord.Award);
        cout << "\nWinner:" << endl;
        cin >> newRecord.Winner;
        cout << "\nName:" << endl;
        cin.ignore();
        getline(cin, newRecord.Name);
        cout << "\nFilm" << endl;
        getline(cin, newRecord.Film);
        tree_housing.add_node(newRecord.Name, newRecord);
    } else {
        cout << "\nName:" << endl;
        cin.ignore();
        getline(cin, newRecord.Name);
        cout << "\nYear:" << endl;
        getline(cin, newRecord.Year);
        cout << "\nNominations:" << endl;
        cin >> newRecord.Nominations;
        cout << "\nRating:" << endl;
        cin >> newRecord.Rating;
        cout << "\nDuration:" << endl;
        cin >> newRecord.Duration;
        cout << "\nGenre1:" << endl;
        cin.ignore();
        getline(cin, newRecord.Genre1);
        cout << "\nGenre2:" << endl;
        getline(cin, newRecord.Genre2);
        cout << "\nRelease:" << endl;
        getline(cin, newRecord.Release);
        cout << "\nMeta-critic:" << endl;
        cin >> newRecord.Meta_Critic;
        cout << "Synopsis:" << endl;
        cin.ignore();
        getline(cin, newRecord.Synopsis);
        tree_housing.add_node(newRecord.Name, newRecord);
    }
    cout << "Successful add:" << endl;
    tree_housing.display(cout, newRecord);
}

void delete_entry(Binary_Search_Tree<Node_Struct, std::string> &tree) {
    //Travel the tree to find match record that user want to delete
    cout << "Please input name of actor you want to delete:" << endl;
    Node_Struct record;
    cin.ignore();
    getline(cin, record.Name);
    if (tree.find(record.Name) != nullptr) {
        tree.remove(record.Name);
    } else {
        cout << "Record is already deleted or not in database" << endl;
    }
}

void modify_entry(
        std::string &user_input,
        Binary_Search_Tree<Node_Struct, string> &tree_housing,
        int choice = 0) {
    //Travel the tree and find match record and modify it
    Node_Struct changeRecord;
    Node<Node_Struct, string> *treePtr;
    string field;
    cout << "Please input name of record you want to modify. Please input name of actor or actress first:" << endl;
    cin.ignore();
    getline(cin, field);
    treePtr = tree_housing.find(field);
    if (treePtr == nullptr) {
        cout << "Record is not exist in database. You can't modify it" << endl;
    } else {
        if (user_input == "pictures.csv") {
            do {
                std::cout
                        << "How would you want to change it" << std::endl
                        << "1. to change year" << std::endl
                        << "2. to change Nominations" << std::endl
                        << "3. to change Rating" << std::endl
                        << "4. to change Duration" << std::endl
                        << "5. to change Genre1" << std::endl
                        << "input 6 to change Genre2" << std::endl
                        << "input -1 if you want to exit" << std::endl;
                std::cin >> choice;
                changeRecord = treePtr->Data();
                switch (choice) {
                    case 0: {
                        cout << "Input Name. For example: Birdman" << endl;
                        cin.ignore();
                        getline(cin, changeRecord.Name);
                        break;
                    }
                    case 1: {
                        cout << "Input Year. For example: 2018" << endl;
                        cin >> changeRecord.Year;
                        break;
                    }
                    case 2: {
                        cout << "Input Nominations. Must be an integer" << endl;
                        cin >> changeRecord.Nominations;
                        break;
                    }
                    case 3: {
                        cout << "Input Rating. Must be a real number" << endl;
                        cin >> changeRecord.Rating;
                        break;
                    }
                    case 4: {
                        cout << "Input Duration.Must be a real number" << endl;
                        cin >> changeRecord.Duration;
                        break;
                    }
                    case 5: {
                        cout << "Input Genre1. For example: Comedy" << endl;
                        cin >> changeRecord.Genre1;
                        break;
                    }
                    case 6: {
                        cout << "Input Genre2. For example: Drama" << endl;
                        cin >> changeRecord.Genre2;
                        break;
                    }
                    default: {
                        std::cout << "Invalid Input!" << std::endl;
                        break;
                    }
                }
                treePtr->setData(changeRecord);
                cout << "Your modified record is" << endl;
                tree_housing.display(cout, changeRecord);
            } while (choice != 7);
        } else if (user_input == "actor-actress.csv" || user_input == "Nominations.csv") {
            int menu;
            cout << "Record you want to change is in the database" << endl;
            do {
                cout << "How would you want to change it" << endl;
                cout << "Input 0 to change Year" << endl;
                cout << "input 1 to change Award" << endl;
                cout << "Input 2 to change winner" << endl;
                cout << "Input 3 to change name" << endl;
                cout << "Input 4 to change film" << endl;
                cout << "input -1 if you want to exit" << endl;
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
    std::ofstream output("new_" + user_input, std::ios_base::out);
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
