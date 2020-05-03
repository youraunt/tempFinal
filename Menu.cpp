//
// Created by BK Allen on 5/2/20.
//

#include "Menu.h"

//using namespace std;
void menuSearch1(binary_search_tree<Final, string> &tree, Node<Final, string> *TreePtr, const std::string &fileName) {
    int choice;
    std::string field;
    do {
        std::cout
                << "Welcome to search in " << fileName << std::endl
                << "Input 1 to do search by year" << std::endl
                << "Input 2 to do search by name" << std::endl
                << "Input 3 to do search by film" << std::endl
                << "Input 4 to go back to search" << std::endl;
        choice = std::getchar();
        switch (choice) {
            case '1':
                cout << "Doing search by year" << endl;
                cin.ignore();
                getline(cin, field);
                menuSubSearch(tree, TreePtr, "Year", field);
                cout << "Please input year you want to search:" << endl;
                break;
            case '2':
                cout << "Doing search by name" << endl;
                cin.ignore();
                getline(cin, field);
                menuSubSearch(tree, TreePtr, "Name", field);
                break;
            case '3':
                cout << "Doing search by film" << endl;
                cin.ignore();
                getline(cin, field);
                menuSubSearch(tree, TreePtr, "Film", field);
                break;
            default:
                break;

        }

    } while (choice != 0);
}

void
menuSub(std::ifstream &inFile, binary_search_tree<Final, string> &tree, vector<Final> &myVector, std::string fileName) {
    int choice;
    Node<Final, string> *myTreePtr = tree.Root();
    cout << "Input 1 to search a record in " << fileName << endl;
    cout << "Input 2 to add a record in " << fileName << endl;
    cout << "Input 3 to modify a record in " << fileName << endl;
    cout << "Input 4 to delete a record in " << fileName << endl;
    cout << "Input 5 to print out updated of " << fileName << endl;
    cout << "Input 6 to do sort in " << fileName << endl;
    cout << "Input 0 to go back to main" << endl;
    choice = std::getchar();
    do {
        switch (choice) {
            case 1:
                if (fileName == "actor-actress.csv" || fileName == "Nominations.csv") {
                    menuSearch1(tree, myTreePtr, fileName);
                } else if (fileName == "pictures.csv") {
                    menuSearch2(tree, myTreePtr, fileName);
                }
                cout << "Successful search in " << fileName << endl;
                break;
            case 2:
                menuAdd(tree, fileName);
                cout << "Successful add in " << fileName << endl;
                break;
            case 3:
                menuModify(tree, fileName);
                cout << "Successful modify in " << fileName << endl;
                break;
            case 4:
                menuDelete(tree, fileName);
                cout << "Successful delete in " << fileName << endl;
                break;
            case 5:
                cout << "Print out file..." << endl;
                printOutFile(tree, tree.Root(), fileName);
                break;
            case 6:
                cout << "Welcome to sort..." << endl;
                if (fileName == "actor-actress.csv" || fileName == "Nominations.csv") {
                    menuSort1(tree, myVector, fileName);
                } else if (fileName == "pictures.csv") {
                    menuSort2(tree, myVector, fileName);
                }
                break;
            default:
                break;

        }

    } while (choice != 0);
}

void menuAdd(binary_search_tree<Final, string> &tree, std::string fileName) {
    unsigned int choice{};
    do {
        std::cout
                << "Input 1 to add new record in "
                << fileName << std::endl
                << "Input 0 to go back to main" << std::endl;
        std::cin >> choice;
        if (choice == 1) {
            cout << "add new record in "
                 << fileName << endl;
            addNewRecord(tree, fileName);
        } else if (choice == 2) { break; }
    } while (choice != 2);
}

void menuModify(binary_search_tree<Final, string> &tree, std::string &fileName) {
    unsigned int choice{};
    do {
        std::cout
                << "Input 1 to modify a record in "
                << fileName << std::endl
                << "Input 0 to go back to main" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            cout << "Modify..." << fileName << endl;
            modifyRecord(tree, fileName);
        } else if (choice == 2) { break; }
    } while (choice != 2);
}

void menuDelete(binary_search_tree<Final, string> &tree, const std::string &fileName) {
    char submenu;
    std::cout << "Welcome to delete" << std::endl;
    std::cout << "Input 1 to delete a record in " << fileName << std::endl;
    std::cout << "Input 0 to go back to main" << std::endl;
    std::cin >> submenu;
    while (submenu != '0') {
        switch (submenu) {
            case '1': {
                deleteRecord(tree);
                std::cout << "Successful delete in " << fileName << std::endl;
                break;
            }
            default: {
                break;
            }
        }
        std::cout << "Input 1 to delete a record in " << fileName << std::endl;
        std::cout << "Input 0 to go back to main" << std::endl;
        std::cin >> submenu;
    }
}

void menuSubSearch(binary_search_tree<Final, string> &tree, Node<Final, string> *treePtr, std::string searchField,
                   std::string field) {
    char submenu;

    std::cout << "Input 1 to do exact search" << std::endl;
    std::cout << "Input 2 to do partial search" << std::endl;
    std::cout << "Input 0 to go back to main" << std::endl;
    std::cin >> submenu;
    while (submenu != '0') {
        switch (submenu) {
            case '1': {
                exactSearchRecord(tree, treePtr, searchField, field);
                break;
            }
            case '2': {
                partialSearchRecord(tree, treePtr, searchField, field);
                break;
            }
            default: {
                break;
            }
        }
        std::cout << "Input 1 to do exact search" << std::endl;
        std::cout << "Input 2 to do partial search" << std::endl;
        std::cout << "Input 0 to go back to main" << std::endl;
        std::cin >> submenu;
    }
}

void menuSort1(binary_search_tree<Final, string> &tree, vector<Final> &myVector, const std::string &fileName) {
    char choice;
    std::cout
            << "Input 1 to do sort by year" << std::endl
            << "Input 2 to do sort by film" << std::endl
            << "Input 3 to do sort by name" << std::endl
            << "Input 0 to go back to main" << std::endl;
    std::cin >> choice;
    do {
        switch (choice) {
            case '1':
                sortF(myVector, 0, myVector.size() - 1, "Year");
                printOutVector(myVector);
                break;
            case '2':
                sortF(myVector, 0, myVector.size() - 1, "Film");
                printOutVector(myVector);
                break;
            case '3':
                tree.printInorder();
            default:
                break;
        }
    } while (choice != '0');
}

void menuSort2(binary_search_tree<Final, string> &tree, vector<Final> &myVector, std::string fileName) {
    char choice;
    do {
        std::cout
                << "Input 1 to do sort by year" << std::endl
                << "Input 2 to do sort by film" << std::endl
                << "Input 3 to do sort by Nominations" << std::endl
                << "Input 4 to do sort by Rating" << std::endl
                << "Input 5 to do sort by Genre1" << std::endl
                << "Input 0 to go back to main" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                sortF(myVector, 0, myVector.size() - 1, "Year");
                printOutVector(myVector);
                break;
            case 2:
                tree.printInorder();
                break;
            case 3:
                sortF(myVector, 0, myVector.size() - 1, "Nominations");
                printOutVector(myVector);
                break;
            case 4:
                sortF(myVector, 0, myVector.size() - 1, "Rating");
                printOutVector(myVector);
                break;
            case 5:
                sortF(myVector, 0, myVector.size() - 1, "Genre1");
                printOutVector(myVector);
                break;
            default:
                break;

        }

    } while (choice != 0);
}

void menuSearch2(binary_search_tree<Final, string> &tree, Node<Final, string> *TreePtr, const std::string &fileName) {
    int choice{};
    string field;
    do {
        cout << "Welcome to search in " << fileName << endl;
        cout << "1. Year" << endl;
        cout << "2. Film" << endl;
        cout << "3. Nominations" << endl;
        cout << "4. Genre" << endl;
        cout << "5. Release" << endl;
        cout << "6. Search" << endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree, TreePtr, "Year", field);
                std::cout << "Please input year you want to search:" << std::endl;
                break;
            case 2:
                std::cout << "Doing search by film" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree, TreePtr, "Name", field);
                break;
            case 3:
                std::cout << "Doing search by Nominations" << std::endl;
                std::cin.ignore();
                getline(std::cin, field);
                menuSubSearch(tree, TreePtr, "Nominations", field);
                std::cout << "Please input year you want to search:" << std::endl;
                break;
            case 4:
                std::cout << "Doing search by genre" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree, TreePtr, "genre", field);
                break;
            case 5:
                std::cout << "Doing search by Release" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, field);
                menuSubSearch(tree, TreePtr, "Release", field);
                break;
            default:
                break;

        }
    } while (choice != '0');
}

void main_menu() {
    int choice;
    std::ifstream infile;
    std::string file;
    std::vector<Final> final_vector;
    auto *actor_bst = new binary_search_tree<Final, std::string>;
    auto *picture_bst = new binary_search_tree<Final, std::string>;
    auto *nomination_bst = new binary_search_tree<Final, std::string>;
    do {
        std::cout
                << "Please select a Sub-Menu and press [Enter]" << std::endl
                << "1. Actor & Actress" << std::endl
                << "2. Pictures" << std::endl
                << "3. Nominations" << std::endl
                << "4. Exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case '1':
                file = R"(actor-actress.csv)";
                cout << "Welcome to actor-actress database" << endl;
                //Go to actor database
                infile.open("actor-actress.csv");
                readFromFile1(infile, *actor_bst, final_vector);
                menuSub(infile, *actor_bst, final_vector, file);
                break;
            case 2:
                file = R"(pictures.csv)";
                cout << "Welcome to pictures database" << endl;
                readFromFile2(infile, *picture_bst, final_vector);
                menuSub(infile, *picture_bst, final_vector, file);
                break;
            case 3:
                file = R"(Nominations.csv)";
                cout << "Welcome to Nominations database" << endl;
                infile.open("Nominations.csv");
                readFromFile1(infile, *nomination_bst, final_vector);
                menuSub(infile, *nomination_bst, final_vector, file);
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                std::cout << "Invalid Entry" << std::endl;
                break;
        }
        final_vector.clear();
    } while (true);

}