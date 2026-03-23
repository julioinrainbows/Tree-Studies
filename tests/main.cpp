#include "../src/binHeaps.hpp"
#include <string>
#include <iostream>
using namespace hp;
int main(){
    std::vector<int> vec = { 0 ,6 ,8 ,9 ,0 ,2 ,3 ,4 ,6};
    std::vector<char> charVec = {'a','b','c','d','e','f'};
    binHeap<decltype(charVec)::value_type> myHeap(charVec.begin(), charVec.end());

    for(auto it = 0; it < myHeap.size(); ++it )
    {
        std::cout << myHeap.valueIn(it) << " ";
    }
    std::cout << "\n";
}