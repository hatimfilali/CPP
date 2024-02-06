#include "PergeMe.hpp"

PergeMe::PergeMe() {

}

PergeMe::PergeMe(const PergeMe &copy) {
    *this = copy;
}

PergeMe &PergeMe::operator=(const PergeMe &copy) {
    if (this != &copy) {
        this->myVector = copy.myVector;
        this->myDeque = copy.myDeque;
    }
    return *this;
}

PergeMe::~PergeMe() {

}

bool isNumber(std::string str) {
    std::string::iterator it = str.begin();
    while (it != str.end() && *it == ' ')
        it++;
    if (it == str.end())
        return false;
    while (it != str.end()) {
        if (!std::isdigit(*it))
            return false;
        it++;
    }
    return true;
}

/*--------------------------------------------------------Vector Sort functions-----------------------------------------------------------------------*/


//This is the insertion sort function when we change the places of the values to the correct places
void PergeMe::VectorInsertSort(std::vector<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while  (j >= left && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

// this is merge sort function that divides our chunks and get them back together in a sorted way
void PergeMe::VectorMerge(std::vector<int> &arr, int left, int middle, int right) {
    //we need the size of each size
    size_t chunkOneSize = middle - left + 1;
    size_t chunkTwoSize = right - middle;

    //we need to store the two chunks in two diffrent vectors
    std::vector<int> chunkOne(arr.begin() + left, arr.begin() + middle + 1);
    std::vector<int> chunkTwo(arr.begin() + middle + 1, arr.begin() + right + 1);
    size_t i = 0, j = 0, k = left;
    //this is when we need to check the order before store the values back to the official array
    while (i < chunkOneSize && j < chunkTwoSize) {
        if (chunkOne[i] <= chunkTwo[j])
            arr[k++] = chunkOne[i++];
        else
            arr[k++] = chunkTwo[j++];
    }
    while (i < chunkOneSize)
        arr[k++] = chunkOne[i++];
    while (j < chunkTwoSize)
        arr[k++] = chunkTwo[j++];
}

//This s the recursive function that do the merge-insert sort 
void PergeMe::VectorMergeSort(std::vector<int> &arr, int left, int right) {
    //if we have less than 6 elements we go to the isert sort function
    if ((left - right) <= 6)
        return VectorInsertSort(arr, left, right);
    //we devide our vector to two chunks and we will recursivlly do the same function to the both of the chunks
    int middle = left + (right - left) / 2;
    VectorMergeSort(arr, left, middle);
    VectorMergeSort(arr, middle + 1, right);
    //now we just need to merge the two chunks back together once more
    VectorMerge(arr, left, middle, right);
}

/*--------------------------------------------------------Deque Sort functions-----------------------------------------------------------------------*/

//ew do the same as we did in the vector 
void PergeMe::DequeInsertSort(std::deque<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void PergeMe::DequeMerge(std::deque<int> &arr, int left, int middle , int right) {
    size_t OneChunkSize = middle - left +  1;
    size_t TwoChunkSize = right - middle;

    std::deque<int> OneChunk(arr.begin() +  left, arr.begin() + middle + 1);
    std::deque<int> TwoChunk(arr.begin() + middle + 1, arr.begin() + right + 1);
    size_t i = 0, j = 0, k = left;

    while (i < OneChunkSize && j < TwoChunkSize) {

        if (OneChunk[i] <= TwoChunk[j])
            arr[k++] = OneChunk[i++];
        else
            arr[k++] = TwoChunk[j++];
    }
    while (i < OneChunkSize)
        arr[k++] = OneChunk[i++];
    while (j < TwoChunkSize)
        arr[k++] = TwoChunk[j++];
}

void PergeMe::DequeMergeSort(std::deque<int> &arr, int left, int right) {
    if ((left - right) <= 6)
        return DequeInsertSort(arr, left, right);
    int  middle = left + (right - left) / 2;
    DequeMergeSort(arr, left, middle);
    DequeMergeSort(arr, middle + 1, right);
    DequeMerge(arr, left, middle, right);
}

/*--------------------------------------------------------Sort function------------------------------------------------------------------------------*/

//the sorting function that sorts and count the time at once
clock_t PergeMe::sort(int type) {
    //we declare two clock_t params to catch the time
    clock_t start;
    clock_t end;
    start = clock();
    //our sort depends on the type if its 1 we need to sort the vector if 2 we need to sort the deque
    switch (type)
    {
    case 1:
        VectorMergeSort(myVector, 0, myVector.size() - 1);
        break;
    case 2:
        DequeMergeSort(myDeque, 0, myDeque.size() - 1);
        break;
    }
    end = clock();
    //we return the diffrence between befor the sort aand after which is the time needed to sort the vector or the deque
    return end - start;
}

//This the most important constructor that will do the hole work for us (it is the start of our implementaion so sit tight and pay attention...)
PergeMe::PergeMe(int arc, char **arv) {

    //first we have to fill the vector with the number (ofc we check if there's an non digital cahracter in the elements)
    for (int i = 1; i < arc; i++) {
        if (!isNumber(arv[i]))
            throw std::runtime_error("Error: invalide character.");
        myVector.push_back(atoi(arv[i]));
    }
    
    //now that we already filled the vector with the proper values we need to do the same to the deque which should be easy
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
        myDeque.push_back(*it);
    
    //now that we have all the vector and the deque filled we need to print thier elements before sorting them
    printer("Before");
    
    //now we sort the elements and we store the sorting time in the clock_t variable
    clock_t vecSortTime = sort(1);
    clock_t deqSortTime = sort(2);

    //just a little After sorting print to the elements
    printer("After");

    //now we print the last of the required stuff
    std::cout << "Time to process a range of " << myVector.size() << " elements with std::vector : " << vecSortTime << " us" << std::endl;
    std::cout << "Time to process a range of " << myDeque.size() << " elements with std::deque : " << deqSortTime << " us" << std::endl;
    
}

void PergeMe::printer(std::string message) {
    std::cout << message << "\t";
    for (std::vector<int>::iterator it = this->myVector.begin(); it != this->myVector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

