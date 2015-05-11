class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i != 26; ++i) {
            child[i] = NULL;
            isTail = false;
        }
    }
    TrieNode *child[26];
    bool isTail;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *curr = root;
        for (int i = 0; i != s.size(); ++i) {
            int index = find(s[i]);
            if (!curr->child[index]) {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isTail = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *curr = root;
        for (int i = 0; i != key.size(); ++i) {
            int index = find(key[i]);
            if (!curr->child[index]) return false;
            curr = curr->child[index];
        }
        if (!curr->isTail) return false;
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i != prefix.size(); ++i) {
            int index = find(prefix[i]);
            if (!curr->child[index]) return false;
            curr = curr->child[index];
        }
        return true;
    }

private:
    TrieNode* root;
    int find(char ch) { return ch - 'a'; }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");