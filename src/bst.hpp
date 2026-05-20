#include <functional>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

#pragma once;

namespace bst{
    
    template<typename T, typename cmp = std::less<T>>
    class bst{

        using value_type = T;
        using std::size_t = size_t;

        struct Node{
            T value;

            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;
            
            explicit Node() = default;
            explicit Node(T&& v) = default;
            explicit Node(Node&& n) : value(std::move(n.value));
        }

        private:
        std::unique_ptr<Node> root = nullptr;

        size_t size = 0; 

        public:
        
        bst() = default;

        bst(const bst&) = delete;

        bst(const bst&&) noexcept = delete;

        bst(bst&) = default;

        // Iterator Range Constructor
        template<typename It>
        bst(It first, It last){
            //
        }

        // Initializer list constructor
        bst(std::initializer_list<T> initializer){
            this->size() = initializer.size();

        }


        bst(bst)
        
        Node* find(int key) const{
            findI(root,key);
        }


        void insert( int key){
            Node* N = root;
            Node* r = nullptr;
            while(N != nullptr){
                r = N;
                if(N->value == key) 
                    return;
                else if(N->value > key)
                    N = N->left;
                else
                    N = N->right;
            }

            Node* p = new Node;

            p->left = p->right = nullptr;
            p->value = key;
            
            if(r->value > key)
                r->left = p; 
            else
                r->right = p
        }

        private:
        Node* findI(Node* N, int key) const{
            if(N == nullptr)
                return nullptr;

            else if(N->value == key)
                return N;

            else if(N->value > key)
                return findI(N->left,key);
    
            else
                return findI(N->right,key);
        }

        Node* findIIt(Node* N, int key) const{
            while(N != nullptr){
                if(N->value == key)
                    return N;
                else if(N->value > key)
                    N = N->left;
                else    
                    N = N->right;
            }
            return nullptr;
        }
    }







}
