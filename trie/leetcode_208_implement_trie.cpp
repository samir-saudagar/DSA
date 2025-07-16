
// | Operation      | Time Complexity                    | Space Complexity |
// | -------------- | ---------------------------------- | ---------------- |
// | `insert()`     | `O(L)` per word / `O(n * L)` total | `O(n * L)`       |
// | `search()`     | `O(L)`                             | `O(1)`           |
// | `startsWith()` | `O(L)`                             | `O(1)`           |

// n is no of words, L is maximum length of a word. 

#include <iostream>
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

    void insert(const string& word) {
        TrieNode* current_node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current_node->children[index] == nullptr)
                current_node->children[index] = new TrieNode();

            current_node = current_node->children[index];
        }
        current_node->is_end_of_word = true;
    }

    bool search(const string& word, bool var = true) {
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

    bool startsWith(const string& word) {
        return search(word, false);
    }
};
