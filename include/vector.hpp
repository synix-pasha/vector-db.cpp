#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>

class collection{
    std :: vector<float> data;
    std :: unordered_map<std::string, uint64_t> maps;   // maps (id) -> offset
    std :: vector<bool> isdead;
    uint32_t dim;

    public:
    collection(int dim);
    bool insert_vector(std::string &id, std::vector<float> &vector);
    bool remove_vector(std::string &id);
    std::vector<float> get_vector(std::string &id);
};