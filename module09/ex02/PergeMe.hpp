#ifndef PERGEME_HPP
#define PERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>

class PergeMe {
private:
    std::vector<int> myVector;
    std::deque<int> myDeque;

public:
    PergeMe();
    PergeMe(int arc, char **arv);
    PergeMe(const PergeMe &copy);
    PergeMe &operator=(const PergeMe &copy);
    ~PergeMe();


    void VectorMergeSort(std::vector<int> &arr, int left, int right);
    void VectorMerge(std::vector<int> &arr, int left, int middle, int right);
    void VectorInsertSort(std::vector<int> &arr, int left, int right);


    void DequeMergeSort(std::deque<int> &arr, int left, int right);
    void DequeMerge(std::deque<int> &arr, int left, int middle, int right);
    void DequeInsertSort(std::deque<int> &arr, int left, int right);


    void printer(std::string message);
    clock_t sort(int type);
};

template<typename T>
bool isSorted(T min, T max) {
    for (T i = min; i != max; i++)
    {
        if (*i < *(i + 1)) {
            std::cout << "Error: " << *i << " is higher than " << *(i + 1) << std::endl;
            return false;
        }
    }
    return true;
}

#endif