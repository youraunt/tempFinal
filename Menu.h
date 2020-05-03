//
// Created by BK Allen on 5/2/20.
//

#ifndef TEMPFINAL_MENU_H
#define TEMPFINAL_MENU_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Read_From_File.h"
#include "Functions.h"

void main_menu();
//Main main_menu
void menuSub(std::ifstream& inFile, binary_search_tree<Final, string>& tree, vector<Final>& myVector, std::string fileName);
//Sub main contain add, search, delete, modify main_menu
void menuSearch1(binary_search_tree<Final, string>& tree, Node<Final,string>* TreePtr, const std::string& fileName);
// main_menu search for actor-actress.csv and Nominations.csv
void menuSearch2(binary_search_tree<Final, string>& tree, Node<Final,string>* TreePtr, const std::string& fileName);
// main_menu search for pictures.csv
void menuAdd(binary_search_tree<Final, string>& tree, std::string fileName);
// main_menu add new record
void menuModify(binary_search_tree<Final, string>& tree, std::string&fileName);
// main_menu modify existing record
void menuDelete(binary_search_tree<Final,string>& tree, const std::string& fileName);
// main_menu delete existing record
void menuSort1(binary_search_tree<Final,string>& tree, vector<Final>& myVector, const std::string& fileName);
// main_menu sort for actor-actress.csv and Nominations.csv
void menuSort2(binary_search_tree<Final,string>& tree, vector<Final>& myVector, std::string fileName);
// main_menu sort for pictures.csv
void menuSubSearch(binary_search_tree<Final, string>& tree, Node<Final, string>* treePtr, std::string searchField, std::string field);
// main_menu sub search which search contain and partial

#endif //TEMPFINAL_MENU_H
