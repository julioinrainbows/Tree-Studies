#pragma once

#include <string>
#include <array>
#include <cstdlib>
#include <algorithm>
#include <cstddef>
#include <concepts>
#include <functional>
#include <span>
#include <ostream>
#include <unordered_map>
#include <iostream>

/*  
    [] < ALFABETO BASE
    [ROOT] < BLOCO DE MEMORIA DA TRIE
*/
namespace tr{

    using size_t = std::size_t;
    template <typename T, size_t N>
    class Trie {
        public:

        std::array<T,N> alphabet;
        using value_type = T;

        struct Node{
            std::array<Node*,N> children{};
            bool endOfWord{false};

            Node(){
                children.fill(nullptr);
            }

        };

        Trie(std::array<T, N> alp) : alphabet(std::move(alp)), root(new Node()), 
        indexMap(N)
        {
            for(size_t i = 0 ; i < alp.size(); ++i){
                indexMap[alp[i]] = i;
            }

        }

        size_t indexAt(const T& val){
            return indexMap.at(val);
        }

        void insert(std::span<const T> arr){

            Node* nPtr = root;

            for(const auto& val : arr){

                auto i = indexAt(val);
                if(nPtr->children[i] == nullptr)
                    nPtr->children[i] = new Node();

                nPtr = nPtr->children[i];
            }
            
            nPtr->endOfWord = true;
        }

        void insertR(Node* nP,std::span<const T> arr){
            
            if(arr.size() <= 0){
                nP->endOfWord = true;
                return;
            }
             
            auto i = indexAt(arr[0]);

            if(nP->children[i] == nullptr)
                nP->children[i] = new Node();
//https://en.cppreference.com/cpp/container/span/subspan 
//https://jaredmil.medium.com/c-20-std-span-explained-db82d7e9d4f8#:~:text=Subspans
            insertR(nP->children[i],arr.subspan(1)); // subspan(index,count) -> empty count == [1,endofrange]
        }

        void printAllWords(){
            std::string str;
            printAllWords(root, str);
        }
        /*
        a 
         n 
          d 
         a r
        r   e

            and(3) anda (4) andar(5) andre(6)

            a
            an
            and
            anda
            andar
            anda
            and
            andr
            andre
          */  
        private:

        void printAllWords(Node* nd, std::string& str){
            if(nd->endOfWord == true) 
                std::cout << str << '\n';

            for(size_t i = 0 ; i < N; ++i){
                if(nd->children[i] != nullptr){
                    str.push_back(alphabet[i]);

                    printAllWords(nd->children[i], str);

                    str.pop_back();
                }
            }
        }

        std::unordered_map<T,size_t> indexMap;
        Node* root; 
        size_t size;
    

    };

}