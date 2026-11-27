#pragma once
#include <functional>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <utility>
#include <initializer_list>


namespace bst{

    template<typename T, typename cmp = std::less<T>>
    class bst{

        using value_type = T;

        struct Node{
            T value;

            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;

            // Constructs a node by moving the given value.
            explicit Node(T&& v) : value(std::move(v)){};

            // Constructs a node by copying the given value.
            explicit Node(const T& v) : value(v){};
        };

        public:

        // Constructs an empty binary search tree.
        bst() = default;

        // Disables copy construction to prevent shallow copying of the tree.
        bst(const bst&) = delete;

        // Disables copy assignment to prevent shallow copying of the tree.
        bst& operator=(const bst&) = delete;

        // Enables move construction to transfer ownership of the tree.
        bst(bst&&) noexcept = default;

        // Enables move assignment to transfer ownership of the tree.
        bst& operator=(bst&&) noexcept = default;

        // Constructs a BST from a range of elements defined by two iterators.
        template<typename It>
        bst(It first, It last){
            for (; first != last; ++first)
                insert(*first);
        }

        // Constructs a BST from an initializer list of elements.
        bst(std::initializer_list<T> initializer){
            for(const auto &val : initializer)
                insert(val);
        }

        // Searches for a value and returns a pointer to its node, or nullptr if not found.
        Node* find(T key) const{
            return findI(root.get(),key);
        }

        // Inserts a value into the BST while preserving the binary search tree property.
        void insert( T key){
            auto* current = &root;

            while(*current != nullptr){
                if(compare(key,(*current)->value)){
                    current = &(*current)->left;
                }
                else if (compare((*current)->value, key)){
                    current = &(*current)->right;
                }
                else //unique elements
                    return;
            }
            //move gera rvalue ref -> Construtor de move-semantics
            *current = std::make_unique<Node>(std::move(key));
            ++size;
        }

        private:

        cmp compare;

        std::unique_ptr<Node> root = nullptr;

        size_t size = 0;

        // Recursively searches for a value starting from the given node.
        Node* findI(Node* N, const T &key) const{
            if(N == nullptr)
                return nullptr;

            if(compare(key,N->value))
                return findI(N->left.get(),key);

            else if(compare(N->value,key))
                return findI(N->right.get(),key);

            else
                return N;
        }

        // Iteratively searches for a value starting from the given node.
        Node* findIIt(Node* N, T key) const{
            while(N != nullptr){

                if(compare(N->value,key))
                    N = N->right.get();

                else if(compare(key,N->value))
                    N = N->left.get();
                else
                    return N;
            }
            return nullptr;
        }
    };

}
