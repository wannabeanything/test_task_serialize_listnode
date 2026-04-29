#pragma once
#include <string>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

struct ListNode{
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr;
    std::string data;
};


template<class Archive>
void serialize(Archive& ar, ListNode& node, [[maybe_unused]] const unsigned int version){
    ar & node.next;
    ar & node.prev;
    ar & node.data;
    ar & node.rand;
}