//
// Created by BK Allen on 5/2/20.
//

#include "Read_From_File.h"
#include "Binary_Search_Tree.hpp"
using namespace std;
void actor_in(std::ifstream& inFile, Binary_Search_Tree<Node_Struct, string>& tree, vector<Node_Struct>& myVector){
    string s;
    Node_Struct tempData;
    getline(inFile,s);
    while(getline(inFile,s)){
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
void picture_in(std::ifstream& inFile, Binary_Search_Tree<Node_Struct, string>& picTree, vector<Node_Struct>& myVector){
    inFile.open("pictures.csv");
    string s;
    Node_Struct tempData;
    getline(inFile,s);
    cout << "Adding Nodes...\n";
    while(getline(inFile,s)){
        int size;
        string sub;
        {
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Name = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Year = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Nominations = atoi(sub.c_str());
            size = s.find(',');
            sub = s.substr(0, size);
            tempData.Rating = stof(sub.c_str());
            s = s.substr(size + 1);
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Duration = stof(sub.c_str());
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Genre1 = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Genre2 = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Release = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Meta_Critic = atoi(sub.c_str());
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Synopsis = sub;
            picTree.add_node(tempData.Name, tempData);
            myVector.push_back(tempData);
        }
    }
    inFile.close();
}
