#include"vector.hpp"
using namespace std;

collection :: collection(int dim): dim(dim){}

bool collection::insert_vector(string &id,vector<float> &inputVector){
    if(maps.count(id))
        return false; //todo
    if(inputVector.size()!=dim)
        return false; // todo
    
    maps[id]=data.size();
    isdead.push_back(false);
    for(int i = 0 ; i < inputVector.size() ; ++i)
        data.push_back(inputVector[i]);
    return true;
}

bool collection :: remove_vector(string &id){
    if(!maps.count(id))
        return false; //execption case

    uint32_t offset = maps[id];
    uint32_t index = offset/dim;
    isdead[index]=true;
    return true;
}

vector<float> collection :: get_vector(string &id){
    vector<float> returnVector(dim, 0.0);

    if(!maps.count(id))
        return returnVector; //todo

    uint64_t offset = maps[id];
    uint32_t index = offset/dim;

    if(isdead[index])
        return returnVector; //todo

    for(int i = 0 ; i < dim ; i++){
        returnVector[i] = data[offset + i];
    }
    return returnVector;
}