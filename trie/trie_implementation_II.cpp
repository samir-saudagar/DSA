//https://www.naukri.com/code360/problems/implement-trie_1387095

// n = number of words, m = length of longest word

#include <bits/stdc++.h> //include all standard headers
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    int word_count;     // Number of times a word ends here
    int prefix_count;   // Number of words that pass through this node

    TrieNode() {
        word_count = 0;
        prefix_count = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
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

    void insert(string &word) { // Time Complexity: O(m), Space Complexity: O(m)
        if (word.empty()) return; 
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->child[index])
                node->child[index] = new TrieNode();
            node = node->child[index];
            node->prefix_count++;
        }
        node->word_count++;
    }

    int countWordsEqualTo(string &word) { // Time Complexity: O(m), Space Complexity: O(1)
        if (word.empty()) return 0;
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->child[index])
                return 0;
            node = node->child[index];
        }
        return node->word_count;
    }

    int countWordsStartingWith(string &word) { // Time Complexity: O(m), Space Complexity: O(1)
        if (word.empty()) return 0;
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->child[index])
                return 0;
            node = node->child[index];
        }
        return node->prefix_count;
    }

    void erase(string &word) { // Time Complexity: O(m), Space Complexity: O(1)
        if (word.empty()) return;

        if (countWordsEqualTo(word) == 0) return; 

        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            TrieNode* next = node->child[index];
            next->prefix_count--;
            node = next;
        }
        node->word_count--;
    }
};
