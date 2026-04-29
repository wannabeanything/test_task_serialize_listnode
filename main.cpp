#include "ListNode.h"
#include <boost/archive/binary_oarchive.hpp>
#include <fstream>
#include <ios>
#include <iostream>
#include <memory>
#include <vector>


using namespace std::literals;

int main(){
    std::ifstream input("../inlet.in"s);
    if(!input.is_open() || input.eof())return 0;
    std::string line;
    std::vector<std::pair<std::unique_ptr<ListNode>, int>> nodes_initial_info;
    
    //Get first node
    std::getline(input, line);
    size_t semicolon_index = line.find(';');
    std::string data = line.substr(0,semicolon_index);
    int rand_index = std::stoi(line.substr(semicolon_index+1));
    std::unique_ptr<ListNode> first = std::make_unique<ListNode>();
    first->data = data;
    nodes_initial_info.push_back({std::move(first), rand_index});

    //Get the rest and set prev/next pointers
    while(std::getline(input, line)){
        size_t semicolon_index = line.find(';');
        data = line.substr(0,semicolon_index);
        rand_index = std::stoi(line.substr(semicolon_index+1));
        std::unique_ptr<ListNode> current = std::make_unique<ListNode>();
        current->data = data;
        ListNode* previous = nodes_initial_info.back().first.get();
        current->prev = previous;
        previous->next = current.get();
        nodes_initial_info.push_back({std::move(current), rand_index});
    }

    //assign random pointers
    for(auto& it: nodes_initial_info){
        ListNode* random_node = nodes_initial_info[it.second].first.get();
        it.first->rand = random_node;
    }

    //serialize into binary
    std::ofstream out{"outlet.out", std::ios_base::binary};
    boost::archive::binary_oarchive oa{out};
    oa << *nodes_initial_info[0].first;


    
}