// Question: https://leetcode.com/problems/implement-trie-prefix-tree/

#include "headers.h"

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        end_ = false;
    }

private:
    bool end_;
    unordered_map<char, TrieNode*> children_;

    friend class Trie;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (word.empty()) {
            return;
        }

        TrieNode* node = root;
        for (char c : word) {
            if (node->children_.count(c) == 0) {
                node->children_[c] = new TrieNode();
            }
            node = node->children_[c];
        }
        node->end_ = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if (word.empty()) {
            return false;
        }

        TrieNode* node = root;
        for (char c : word) {
            if (node->children_.count(c) == 0) {
                return false;
            }
            node = node->children_[c];
        }
        return node->end_;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (prefix.empty()) {
            return false;
        }

        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children_.count(c) == 0) {
                return false;
            }
            node = node->children_[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main(int argc, char** argv) {
// Your Trie object will be instantiated and called as such:
    Trie trie;
    trie.insert("somestring");
    trie.insert("anotherthing");
    cout << trie.search("key") << endl;
    cout << trie.search("some") << endl;
    cout << trie.search("something") << endl;
    cout << trie.search("anotherthing") << endl;
    cout << trie.startsWith("ano") << endl;
    cout << trie.startsWith("some") << endl;
    cout << trie.startsWith("th") << endl;

    return 0;
}
