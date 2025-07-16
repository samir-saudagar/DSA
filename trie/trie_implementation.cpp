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

    bool search(const string& word) {
        TrieNode* current_node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current_node->children[index] == nullptr)
                return false;

            current_node = current_node->children[index];
        }
        return current_node->is_end_of_word;
    }

    void deleteTrie(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) deleteTrie(node->children[i]);
    }
    delete node;
    }

    ~Trie() {
        deleteTrie(root);
    }
};

int main() {
    Trie trie;

    trie.insert("samir");
    trie.insert("ibrahim");
    trie.insert("sohel");
    trie.insert("shamoil");
    trie.insert("apple");
    trie.insert("bat");
    trie.insert("batman");
    trie.insert("bats");

    cout << "Search 'samir': " << trie.search("samir") << endl;      // 1
    cout << "Search 'sami': "  << trie.search("sami")  << endl;      // 0
    cout << "Search 'shamoil': " << trie.search("shamoil") << endl;  // 1
    cout << "Search 'shamo': "   << trie.search("shamo")   << endl;  // 0
    cout << "Search 'apple': "   << trie.search("apple")   << endl;  // 1
    cout << "Search 'app': "     << trie.search("app")     << endl;  // 0
    cout << "Search 'batman': "  << trie.search("batman")  << endl;  // 1
    cout << "Search 'bat': "     << trie.search("bat")     << endl;  // 1
    cout << "Search 'bats': "    << trie.search("bats")    << endl;  // 1
    cout << "Search 'battle': "  << trie.search("battle")  << endl;  // 0

    return 0;
}
