#include <iostream>
#include <numeric>
#include<array>

#include "../include/bst.hpp"
#include "../include/tries.hpp"
#include "../include/binHeaps.hpp"


int main() {
    bst::bst<int> tree;

    //INSERTING-VALUES
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(20);

    //FINDING-VALUES
    tree.find(10);
    tree.find(5);
    tree.find(20);
    tree.find(30);
    tree.find(-5);

    //------------------------------

    std::array<char,26> alph;
    std::iota(alph.begin(), alph.end(), 'a');

    tr::Trie<char,26> trie(alph);

    std::string word = "tree";
    trie.insert(word);
    word = "appletree";
    trie.insert(word);
    word = "bananatree";
    trie.insert(word);
    trie.printAllWords();

    return 0;
}
