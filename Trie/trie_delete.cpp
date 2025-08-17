//https://www.naukri.com/code360/problems/trie-delete-operation_1062663

// n = number of words, m = length of word to be deleted

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

bool isEmpty(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i])
            return false;
    }
    return true;
}


TrieNode* deleteWordHelper(TrieNode* node, string& word, int depth) {
    if (!node) return NULL;

    if (depth == word.length()) {
        if (node->isEnd)
            node->isEnd = false;

        if (isEmpty(node)) {
            delete node;
            return NULL;
        }

        return node;
    }

    int index = word[depth] - 'a';
    node->children[index] = deleteWordHelper(node->children[index], word, depth + 1);

    if (isEmpty(node) && !node->isEnd) {
        delete node;
        return NULL;
    }

    return node;
}

TrieNode* deleteWord(TrieNode* root, string word) { //Time Complexity: O(m), Space Complexity: O(m)
    return deleteWordHelper(root, word, 0);
}
