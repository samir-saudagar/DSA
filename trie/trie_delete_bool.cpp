#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool is_end_of_word;

    TrieNode() {
        is_end_of_word = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    // Helper function for delete
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.length()) {
            if (!node->is_end_of_word)
                return false; // Word not found

            node->is_end_of_word = false;

            // If node has no children, it can be deleted
            for (int i = 0; i < 26; i++)
                if (node->children[i]) return false;

            return true; // Safe to delete this node
        }

        int index = word[depth] - 'a';
        if (deleteHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;

            // Check if current node can also be deleted
            if (!node->is_end_of_word) {
                for (int i = 0; i < 26; i++)
                    if (node->children[i]) return false;
                return true;
            }
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->is_end_of_word = true;
    }

    bool search(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return curr->is_end_of_word;
    }

    void remove(const string& word) {
        deleteHelper(root, word, 0);
    }
};