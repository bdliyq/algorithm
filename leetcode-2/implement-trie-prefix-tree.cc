// Question: https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        end_ = false;
    }

    unordered_map<char, TrieNode*> data_;
    bool end_;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto node = root;
        for (char c : word) {
            if (node->data_.count(c) == 0) {
                node->data_[c] = new TrieNode;
            }
            node = node->data_[c];
        }
        node->end_ = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto node = root;
        for (char c : word) {
            if (node->data_.count(c) == 0) {
                return false;
            }
            node = node->data_[c];
        }
        return node->end_;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto node = root;
        for (char c : prefix) {
            if (node->data_.count(c) == 0) {
                return false;
            }
            node = node->data_[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
