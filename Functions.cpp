//
// Created by BK Allen on 5/2/20.
//
#include "Functions.h"
#include <string>

using namespace std;

void exactSearchRecord(binary_search_tree<Final, string> &tree, Node<Final, string> *TreePtr, std::string &searchField,
                       std::string &field) {
    //Travel entire tree and find if record is match whichever user input


    if (TreePtr == nullptr) {
        return;
    }
    exactSearchRecord(tree, TreePtr->Left(), searchField, field);
    if (searchField == "Name") {
        if (TreePtr->Data().Name == field) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Film") {
        if (TreePtr->Data().Film == field) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Year") {
        if (TreePtr->Data().Year == field) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Nominations") {
        if (to_string(TreePtr->Data().Nominations) == (field)) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Rating") {
        if (to_string(TreePtr->Data().Rating) == (field)) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "genre") {
        if (TreePtr->Data().Genre1 == field || TreePtr->Data().Genre2 == field) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Release") {
        if (TreePtr->Data().Release == field) {
            tree.print(cout, TreePtr->Data());
        }
    }
    exactSearchRecord(tree, TreePtr->Right(), searchField, field);
}

void
partialSearchRecord(binary_search_tree<Final, string> &tree, Node<Final, string> *TreePtr, std::string &searchField,
                    std::string &field) {
    //Travel entire tree and find if record is partial match whichever user input
    if (TreePtr == nullptr) {
        return;
    }
    partialSearchRecord(tree, TreePtr->Left(), searchField, field);
    if (searchField == "Name") {
        if (TreePtr->Data().Name.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Film") {
        if (TreePtr->Data().Film.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Year") {
        if (TreePtr->Data().Year.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Nominations") {
        if (to_string(TreePtr->Data().Nominations).find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Rating") {
        if (to_string(TreePtr->Data().Rating).find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "genre") {
        if (TreePtr->Data().Genre1.find(field) != std::string::npos ||
            TreePtr->Data().Genre2.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    } else if (searchField == "Release") {
        if (TreePtr->Data().Release.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    }
    partialSearchRecord(tree, TreePtr->Right(), searchField, field);

}

void addNewRecord(binary_search_tree<Final, string> &tree, std::string &fileName) {
    Final newRecord;
    if (fileName != "pictures.csv") {
        cout << "Please input your new record as the following" << endl;
        cout << "Year,Award,Winner,Name,Film" << endl;
        cout << "Year:" << endl;
        cin >> newRecord.Year;
        cout << "Award:" << endl;
        cin.ignore();
        getline(cin, newRecord.Award);
        cout << "Winner:" << endl;
        cin >> newRecord.Winner;
        cout << "Name:" << endl;
        cin.ignore();
        getline(cin, newRecord.Name);
        cout << "Film" << endl;
        getline(cin, newRecord.Film);
        tree.addNode(newRecord.Name, newRecord);
    } else {
        cout << "Please input your new record as the following" << endl;
        cout << "name,year,Nominations,Rating,Duration,Genre1,Genre2,Release,Metacritic,Synopsis" << endl;
        cout << "name:" << endl;
        cin.ignore();
        getline(cin, newRecord.Name);
        cout << "year:" << endl;
        getline(cin, newRecord.Year);
        cout << "Nominations:" << endl;
        cin >> newRecord.Nominations;
        cout << "Rating:" << endl;
        cin >> newRecord.Rating;
        cout << "Duration:" << endl;
        cin >> newRecord.Duration;
        cout << "Genre1:" << endl;
        cin.ignore();
        getline(cin, newRecord.Genre1);
        cout << "Genre2:" << endl;
        getline(cin, newRecord.Genre2);
        cout << "Release:" << endl;
        getline(cin, newRecord.Release);
        cout << "Metacritic:" << endl;
        cin >> newRecord.Metacritic;
        cout << "Synopsis:" << endl;
        cin.ignore();
        getline(cin, newRecord.Synopsis);
        tree.addNode(newRecord.Name, newRecord);
    }
    cout << "Successful add:" << endl;
    tree.print(cout, newRecord);
}

void deleteRecord(binary_search_tree<Final, string> &tree) {
    //Travel the tree to find match record that user want to delete
    cout << "Please input name of actor you want to delete:" << endl;
    Final record;
    cin.ignore();
    getline(cin, record.Name);
    if (tree.findNode(record.Name) != nullptr) {
        tree.deleteNode(record.Name);
    } else {
        cout << "Record is already deleted or not in database" << endl;
    }
}

void modifyRecord(binary_search_tree<Final, string> &tree, std::string &fileName) {
    //Travel the tree and find match record and modify it
    Final changeRecord;
    Node<Final, string> *treePtr;
    string field;
    cout << "Please input name of record you want to modify. Please input name of actor or actress first:" << endl;
    cin.ignore();
    getline(cin, field);
    treePtr = tree.findNode(field);
    if (treePtr == nullptr) {
        cout << "Record is not exist in database. You can't modify it" << endl;
    } else {
        if (fileName == "pictures.csv") {
            int menu;
            do {
                std::cout
                        << "How would you want to change it" << std::endl
                        << "Input 0 to change name" << std::endl
                        << "input 1 to change year" << std::endl
                        << "input 2 to change Nominations" << std::endl
                        << "input 3 to change Rating" << std::endl
                        << "input 4 to change Duration" << std::endl
                        << "input 5 to change Genre1" << std::endl
                        << "input 6 to change Genre2" << std::endl
                        << "input -1 if you want to exit" << std::endl;
                std::cin >> menu;
                changeRecord = treePtr->Data();
                switch (menu) {
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
                        break;
                    }
                }
                treePtr->setData(changeRecord);
                cout << "Your modified record is" << endl;
                tree.print(cout, changeRecord);
            } while (menu != -1);
        } else if (fileName == "actor-actress.csv" || fileName == "Nominations.csv") {
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
                tree.print(cout, changeRecord);
            } while (menu != -1);
        } else {
            cout << "Sorry. File is not exist" << endl;
        }
    }
}

void mergeF(vector<Final> &myVector, int l, int m, int r, const std::string &mergeField) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp vector*/
    vector<Final> L, R;

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L.push_back(myVector[l + i]);
    for (j = 0; j < n2; j++)
        R.push_back(myVector[m + 1 + j]);

    /* Merge the temp arrays back into vector*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    if (mergeField == "Film") {
        while (i < n1 && j < n2) {
            if (L[i].Film <= R[j].Film) {
                myVector[k] = L[i];
                i++;
            } else {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    } else if (mergeField == "Year") {
        while (i < n1 && j < n2) {
            if (L[i].Year <= R[j].Year) {
                myVector[k] = L[i];
                i++;
            } else {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    } else if (mergeField == "Rating") {
        while (i < n1 && j < n2) {
            if (L[i].Rating <= R[j].Rating) {
                myVector[k] = L[i];
                i++;
            } else {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    } else if (mergeField == "Nominations") {
        while (i < n1 && j < n2) {
            if (L[i].Nominations <= R[j].Nominations) {
                myVector[k] = L[i];
                i++;
            } else {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    } else if (mergeField == "Genre1") {
        while (i < n1 && j < n2) {
            if (L[i].Rating <= R[j].Rating) {
                myVector[k] = L[i];
                i++;
            } else {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        myVector[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        myVector[k] = R[j];
        j++;
        k++;
    }
    L.clear();
    R.clear();
}

void sortF(vector<Final> &myVector, int l, int r, std::string sortField) {
    //Merge sort
    if (l < r) {
        int m = l + (r - l) / 2;
        sortF(myVector, l, m, sortField);
        sortF(myVector, m + 1, r, sortField);
        mergeF(myVector, l, m, r, sortField);
    }
}

void printOutFile(binary_search_tree<Final, string> &tree, Node<Final, string> *node, std::string fileName) {
    if (node == nullptr)
        return;
    ofstream updateFile;
    if (fileName == "actor-actress.csv" || fileName == "Nominations.csv") {
        string name;
        name = "updated" + fileName;
        updateFile.open(name);
    } else if (fileName == "pictures.csv") {
        string name;
        name = "updated" + fileName;
        updateFile.open(name);
    }

    printRecursive(tree, node, updateFile);

    cout << "Successfully print out" << endl;
    updateFile.close();
}

void printRecursive(binary_search_tree<Final, string> &tree, Node<Final, string> *node, std::ofstream &updateFile) {
    if (node == nullptr)
        return;
    printRecursive(tree, node->Left(), updateFile);
    tree.print(updateFile, node->Data());
    printRecursive(tree, node->Right(), updateFile);
}

void printOutVector(vector<Final> &myVector) {
    for (const auto &iterator : myVector) {
        (iterator.Synopsis.empty() ?
         cout
                 << iterator.Year << ","
                 << iterator.Award << ","
                 << iterator.Winner << ","
                 << iterator.Name << ","
                 << iterator.Film :
         cout
                 << iterator.Name << ","
                 << iterator.Year << ","
                 << iterator.Nominations << ","
                 << iterator.Rating << ","
                 << iterator.Duration << ","
                 << iterator.Genre1 << ","
                 << iterator.Genre2 << ","
                 << iterator.Release << ","
                 << iterator.Metacritic << ","
                 << iterator.Synopsis)
                << endl;
    }
}
