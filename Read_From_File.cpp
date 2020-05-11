//
// Created by BK Allen on 5/2/20.
//

#include "Read_From_File.h"
#include "Binary_Search_Tree.hpp"

using namespace std;

void actor_in(std::ifstream &inFile, Binary_Search_Tree<Node_Struct, string> &tree, vector<Node_Struct> &myVector) {
//    static bool called = false;
//    if(called){
//        return;
//    }
//    called = true;
    string s;
    Node_Struct tempData;
    getline(inFile, s);
    while (getline(inFile, s)) {
        int size;
        string sub;
        {
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Year = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Award = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Winner = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            tempData.Name = sub;
            s = s.substr(size + 1);
            sub = s;
            tempData.Film = sub;
            tree.add_node(tempData.Name, tempData);
            myVector.push_back(tempData);
        }
    }
    inFile.close();
}

void picture_in(std::ifstream &infile, Binary_Search_Tree<Node_Struct, string> &tree_housing,
                vector<Node_Struct> &vector_housing) {
//    static bool called = false;
//    if(called){
//        return;
//    }
//    called = true;
    infile.open("pictures.csv");
    std::string string_housing;
    Node_Struct tempData;
    getline(infile, string_housing);
    while (getline(infile, string_housing)) {
        auto size = 0;
        std::string sub_string;
        {
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Name = sub_string;
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Year = sub_string;
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Nominations = atoi(sub_string.c_str());
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            tempData.Rating = stof(sub_string.c_str());
            string_housing = string_housing.substr(size + 1);
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Duration = stof(sub_string.c_str());
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Genre1 = sub_string;
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Genre2 = sub_string;
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Release = sub_string;
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Meta_Critic = atoi(sub_string.c_str());
            size = string_housing.find(',');
            sub_string = string_housing.substr(0, size);
            string_housing = string_housing.substr(size + 1);
            tempData.Synopsis = sub_string;
            tree_housing.add_node(tempData.Name, tempData);
            vector_housing.push_back(tempData);
        }
    }
    infile.close();
}
