//
// Created by BK Allen on 5/2/20.
//

#include "Read_From_File.h"
#include "Binary_Search_Tree.hpp"


void actor_in(std::ifstream &infile, std::vector<Node_Struct> &vector_housing,
              Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
//    static bool called = false;
//    if(called){
//        return;
//    }
//    called = true;
    Node_Struct node_struct;
    std::string string_housing{};
    getline(infile, string_housing);
    while (getline(infile, string_housing)) {
        auto temp_size = 0;
        std::string sub_string;
        {
            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Year = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Award = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Winner = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            node_struct.Name = sub_string;

            string_housing = string_housing.substr(temp_size + 1);

            sub_string = string_housing;

            node_struct.Film = sub_string;

            tree_housing.add_node(node_struct.Name, node_struct);
            vector_housing.push_back(node_struct);
        }
    }
    infile.close();
}

void picture_in(std::ifstream &infile, std::vector<Node_Struct> &vector_housing,
                Binary_Search_Tree<Node_Struct, std::string> &tree_housing) {
//    static bool called = false;
//    if(called){
//        return;
//    }
//    called = true;
    Node_Struct node_struct;
    std::string string_housing{};
    infile.open(R"(pictures.csv)");
    getline(infile, string_housing);
    while (getline(infile, string_housing)) {
        auto temp_size = 0;
        std::string sub_string;
        {
            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Name = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Year = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Nominations = atoi(sub_string.c_str());

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            node_struct.Rating = std::stof(sub_string);

            string_housing = string_housing.substr(temp_size + 1);

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Duration = std::stof(sub_string);

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Genre1 = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Genre2 = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Release = sub_string;

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Meta_Critic = atoi(sub_string.c_str());

            temp_size = string_housing.find(',');

            sub_string = string_housing.substr(0, temp_size);

            string_housing = string_housing.substr(temp_size + 1);

            node_struct.Synopsis = sub_string;

            tree_housing.add_node(node_struct.Name, node_struct);
            vector_housing.push_back(node_struct);
        }
    }
    infile.close();
}
