class TrieNode {
public:
	TrieNode() {
		isTail = false;
		for (TrieNode *&letter : letters) { letter = NULL; }
	}
	bool isTail;
	TrieNode *letters[26];
};

class WordDictionary {
public:
	WordDictionary() { root = new TrieNode(); }
    // Adds a word into the data structure.
    void addWord(string word) {
    	TrieNode *curr = root;
        for (char letter : word) {
        	int index = find(letter);
        	if (!curr->letters[index]) {
        		curr->letters[index] = new TrieNode();
        	}
        	curr = curr->letters[index];
        }
        curr->isTail = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs_search(word, 0, root);
    }
private:
	TrieNode *root;

	int find(char letter) {
		return static_cast<int>(letter - 'a');
	}

	bool dfs_search(string word, int i, TrieNode *curr) {
		if (!curr) return false;
		if (word.size() == i) { return curr->isTail; }

		if (word[i] != '.') {
			return dfs_search(word, i + 1, curr->letters[find(word[i])]);
		} else {
			for (int k = 0; k != 26; ++k) {
				if (curr->letters[k] && dfs_search(word, i + 1, curr->letters[k])) {
					return true;
				}
			}
		}
		return false;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");