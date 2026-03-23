#ifndef HEAPS_HPP
#define HEAPS_HPP
/*
23/03 -> interval constructor + heapify
*/
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

    void heapifyUp(size_t i);
    void heapify(size_t i){
    
        size_t largest = i;
        size_t left = 2*i + 1;
        size_t right = 2*i + 2;

        largest = (left < size() && right < size() ) ? ((data[left] > data[right]) ?
        (data[left] > data[i] ? left : i) : (data[right] > data[i] ? right : i)) : 
        (left < size() ? (data[left] > data[i] ? left : i) : (right < size() ? (data[right]
        > data[i] ? right : i ) : i )); 
        
        if(largest != i){
            std::swap(data[i], data[largest]);
            heapify(largest);
        }

    };

    public:

    /*
    parent(i) = (i-1)/2;
    left(i) = 2*i + 1;
    right(i) = 2*i + 2;
    */

    binHeap() = default;

    template<typename It>
        binHeap(It begin, It end){
            data.assign(begin,end);
            for(int i = static_cast<int>(data.size()/2 - 1) ; i >= 0 ; --i ){
                heapify(i);
            }
    };

    void push(const T& value);
    void pop();

    const T& top() const;

    bool empty();
    size_t size() const{ return data.size();};

    T valueIn (size_t i) const{
        return data[i];
    } 
};

}
#endif