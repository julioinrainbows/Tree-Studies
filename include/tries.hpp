#pragma once

/*
 * Generic Trie (Prefix Tree) implementation.
 * Stores sequences of elements using a tree structure, where each node
 * represents a prefix and its children represent possible continuations.
 * Supports iterative and recursive insertion, word traversal and printing.
 *
 * T: Type of the elements stored in the Trie.
 * N: Number of possible elements in the alphabet.
 */

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

namespace tr {

    using size_t = std::size_t;

    template <typename T, size_t N>
    class Trie {

    public:

        std::array<T, N> alphabet;

        using value_type = T;

        // Disables copy construction to prevent multiple Tries from sharing the same nodes.
        Trie(const Trie&) = delete;

        // Disables copy assignment to prevent shallow copying of the Trie.
        Trie& operator=(const Trie&) = delete;

        struct Node {

            std::array<Node*, N> children{};

            bool endOfWord{false};

            // Initializes all child pointers to nullptr.
            Node() {
                children.fill(nullptr);
            }

        };

        // Initializes the Trie with the given alphabet and creates its root node.
        Trie(std::array<T, N> alp)
            : alphabet(std::move(alp)),
              root(new Node())
        {

            for(size_t i = 0; i < alp.size(); ++i) {
                indexMap[alp[i]] = i;
            }

        }

        // Returns the index associated with a given alphabet element.
        size_t indexAt(const T& val) {
            return indexMap.at(val);
        }

        // Inserts a sequence into the Trie using an iterative approach.
        void insert(std::span<const T> arr) {

            Node* nPtr = root;

            for(const auto& val : arr) {

                auto i = indexAt(val);

                if(nPtr->children[i] == nullptr)
                    nPtr->children[i] = new Node();

                nPtr = nPtr->children[i];
            }

            nPtr->endOfWord = true;
        }

        // Starts recursive insertion from the root node.
        void insertR(std::span<const T> arr) {
            insertR(root, arr);
        }

        // Recursively inserts a sequence by processing one element at a time.
        void insertR(Node* nP, std::span<const T> arr) {

            if(arr.size() <= 0) {
                nP->endOfWord = true;
                return;
            }

            auto i = indexAt(arr[0]);

            if(nP->children[i] == nullptr)
                nP->children[i] = new Node();

            insertR(nP->children[i], arr.subspan(1));
        }

        // Starts the recursive traversal that prints all words stored in the Trie.
        void printAllWords() {

            std::string str;

            printAllWords(root, str);
        }

        ~Trie(){
            destroy(root);
        }
    private:

        // Recursively traverses the Trie, building and printing complete words.
        void printAllWords(Node* nd, std::string& str) {

            if(nd->endOfWord == true)
                std::cout << str << '\n';

            for(size_t i = 0; i < N; ++i) {

                if(nd->children[i] != nullptr) {

                    str.push_back(alphabet[i]);

                    printAllWords(nd->children[i], str);

                    str.pop_back();
                }
            }
        }

        // Recursively releases all nodes allocated in the Trie.
        void destroy(Node* node){
            if(node == nullptr)
                return;

            for(auto children : node->children)
                destroy(children);

            delete node;
        }

        std::unordered_map<T, size_t> indexMap;

        Node* root;

        size_t size;

        // Releases the entire Trie when the object is destroyed.

    };

}
