// Question: https://leetcode.com/problems/add-and-search-word-data-structure-design/

class TrieNode {
public:
    TrieNode() {
        end_ = false;
    }

    unordered_map<char, TrieNode*> data_;
    bool end_;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        auto node = root;
        for (char c : word) {
            if (node->data_.count(c) == 0) {
                node->data_[c] = new TrieNode;
            }
            node = node->data_[c];
        }
        node->end_ = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word, 0, root);
    }

private:
    bool helper(string& word, int start, TrieNode* root) {
        if (start == word.size()) {
            return root->end_;
        }
        if (word[start] == '.') {
            for (auto& kv : root->data_) {
                if (helper(word, start+1, kv.second)) {
                    return true;
                }
            }
            return false;
        } else {
            return root->data_.count(word[start]) && helper(word, start+1, root->data_[word[start]]);
        }
    }

private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
