// Question: https://leetcode.com/problems/add-and-search-word-data-structure-design/

#include "headers.h"

struct TrieNode {
    vector<TrieNode*> children;
    bool end;
    TrieNode() : children(26, NULL), end(false) {}
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        if (word.empty()) {
            return;
        }
        TrieNode* node = &root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode;
            }
            node = node->children[idx];
        }
        node->end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.empty()) {
            return false;
        }
        helper(word, 0, &root);
    }

private:
    bool helper(string& word, int start, TrieNode* node) {
        if (start == word.size()) {
            return node->end;
        }
        if (word[start] == '.') {
            bool ans = false;
            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    if (helper(word, start+1, node->children[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            return node->children[word[start]-'a'] && helper(word, start+1, node->children[word[start]-'a']);
        }
    }

private:
    TrieNode root;
};

int main(int argc, char** argv) {

// Your WordDictionary object will be instantiated and called as such:
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    cout << wordDictionary.search("pattern") << endl;
    cout << wordDictionary.search("word") << endl;
    cout << wordDictionary.search("w.rd") << endl;

}
