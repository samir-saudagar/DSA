//https://leetcode.com/problems/implement-trie-prefix-tree?envType=problem-list-v2&envId=trie

// n = number of words, m = length of longest word

#include <bits/stdc++.h> //include all standard headers
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool is_end_of_word;

    TrieNode() {
        is_end_of_word = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) { // Time Complexity: O(m), Space Complexity: O(m)
        if (word.empty()) return; 
        TrieNode* current_node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current_node->children[index] == nullptr)
                current_node->children[index] = new TrieNode();

            current_node = current_node->children[index];
        }
        current_node->is_end_of_word = true;
    }

    bool search(const string& word, bool var = true) { // Time Complexity: O(m), Space Complexity: O(1)
        if (word.empty()) return false;
        TrieNode* current_node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current_node->children[index] == nullptr)
                return false;

            current_node = current_node->children[index];
        }
        if(var) return current_node->is_end_of_word;
        return true;
    }

    bool startsWith(const string& word) { // Time Complexity: O(m), Space Complexity: O(1)
        return search(word, false);
    }
};
