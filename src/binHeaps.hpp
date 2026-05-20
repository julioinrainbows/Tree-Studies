z#ifndef HEAPS_HPP
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
    int heapSize{0};
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
        heapSize = end - begin;
        for(int i = static_cast<int>(data.size()/2 - 1) ; i >= 0 ; --i ){
            heapify(i);
        }
    };

    void push(const T& value);

    void pop();

    const T& top() const;

    bool empty();

    size_t size() const{ return this->heapSize;};

    T valueIn (size_t i) const{
        return data[i];
    } 

    void heapsort(){
        /*
            Crio uma Heap a partir de um vetor -> Troco o ultimo nó com o primeiro,
             excluo o ultimo nó, chamo heapify a partir do primeiro, e repito o processo
             ate que não tenham mais nós.
        */
        int n = this->heapSize;
        for(int i = n; i > 1; --i){
            std::swap(data[0],data[i]);
            this->heapSize--;
            heapify(0);
        }
    }
};

}
#endif