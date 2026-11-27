#pragma once
// #include <cassert>
#include <vector>
#include <iterator>
#include <cstddef> // size_t
#include <functional> // less , greater

namespace hp{
template<typename T, typename Compare = std::less<T>>
class binHeap{
    std::vector<T> data;
    Compare cmp;
    int heapSize{0};
    void heapifyUp(size_t i);
    void heapify(size_t i){

        size_t largest = i;
        size_t left = 2*i + 1;
        size_t right = 2*i + 2;

        if (left < size() && data[left] > data[largest])
            largest = left;


        if (right < size() && data[right] > data[largest])
            largest = right;


        if(largest != i){
            std::swap(data[i], data[largest]);
            heapify(largest);
        }

    };

    public:

    binHeap() = default;

    template<typename It>
    binHeap(It begin, It end){
        data.assign(begin,end);
        heapSize = end - begin;
        for(int i = static_cast<int>(data.size()/2 - 1) ; i >= 0 ; --i ){
            heapify(i);
        }
    };

    void push(const T& value);

    void pop();

    const T& top() const;

    bool empty();

    size_t size() const {
        return this->heapSize;
    }

    T valueIn (size_t i) const{
        return data[i];
    }

    void heapsort(){
        int n = this->heapSize;
        for(int i = n-1 ; i > 0; --i){
            std::swap(data[0],data[i]);
            this->heapSize--;
            heapify(0);
        }
        this->heapSize = n;
    }
};

}
