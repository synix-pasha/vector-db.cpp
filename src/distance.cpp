#include "distance.hpp"
#include <cassert>
#include <cmath>

//Euclidean distance = sqrt(sum over(i) (|A(i) - B(i)|^2))
float Euclidean_distance(std::vector<float> &vec1, std::vector<float> &vec2){
    assert(vec1.size()==vec2.size());

    float distance = 0.0;
    for(std::size_t i = 0 ; i < vec1.size() ; i++){
        distance += (vec1[i]-vec2[i])*(vec1[i]-vec2[i]);
    }

    return std::sqrt(distance);
}

// magnitude = sqrt(sum over(i) (|A(i)|^2))
float magnitude_(std::vector<float> &vec){
    float magnitude = 0.0;
    for(std::size_t i = 0 ; i < vec.size() ; i++){
        magnitude += (vec[i]*vec[i]);
    }

    return std::sqrt(magnitude);
}

// cosing similartiy = (A dot B) / (|A|*|B|)
float cosine_similarity(std::vector<float> &vec1, std::vector<float> &vec2){
    assert(vec1.size()==vec2.size());

    float dotProduct = dot_product(vec1,vec2);
    float magnitudeVec1 = magnitude_(vec1);
    float magnitudeVec2 = magnitude_(vec2);

    if(magnitudeVec1 == 0 || magnitudeVec2 == 0)
        return NAN;

    float cosineSimilarity = dotProduct / (magnitudeVec1 * magnitudeVec2);
    return cosineSimilarity;
}

// dot product = sum over(i) (|A(ij) * B(ij)|)
float dot_product(std::vector<float> &vec1, std::vector<float> &vec2){
    assert(vec1.size()==vec2.size());

    float dotProduct = 0.0;
    for(std::size_t i = 0 ; i < vec1.size() ; i++){
        dotProduct += (vec1[i]*vec2[i]);
    }

    return dotProduct;
}

//optimised distance (L2) = sum over(i) (|A(i) - B(i)|^2)
float optimised_distance(std::vector<float> &vec1, std::vector<float> &vec2){
    assert(vec1.size()==vec2.size());

    float distance = 0.0;
    for(std::size_t i = 0 ; i < vec1.size() ; i++){
        distance += (vec1[i]-vec2[i])*(vec1[i]-vec2[i]);
    }

    return distance;
}