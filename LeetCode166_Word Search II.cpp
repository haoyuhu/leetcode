int find(char letter) { return static_cast<int> (letter - 'a'); }

class TrieNode {
public:
	string * wordLocation;
	TrieNode * letters[26];

	TrieNode() {
		wordLocation = NULL;
		for (int i = 0; i != 26; ++i) { letters[i] = NULL; }
	}
};

class WordsDictionary {
public:
	WordsDictionary(): root(new TrieNode()) {}

	void addWord(string& word) {
		TrieNode * curr = root;

		for (int i = 0; i != word.size(); ++i) {
			int index = find(word[i]);
			if (!curr->letters[index]) {
				curr->letters[index] = new TrieNode();
			}
			curr = curr->letters[index];
		}
		curr->wordLocation = &word;
	}

	TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> answer;
        WordsDictionary wordsDict;
        unordered_set<string> check;
        int row = board.size(), col = board[0].size();

        for (string& word : words) {
        	wordsDict.addWord(word);
        }

        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++j) {
        		findWordsInBoard(board, i, j, wordsDict.root, answer, check);
        	}
        }

        return answer;
    }

    void findWordsInBoard(vector<vector<char>>& board, int i, int j, TrieNode * curr, vector<string>& answer, unordered_set<string>& check) {
    	if (!inBoard(board, i, j) || board[i][j] == 'X') return;

    	char currentLetter = board[i][j];
    	int dx[] = {1, 0, -1, 0};
    	int dy[] = {0, 1, 0, -1};
    	int index = find(currentLetter);
    	board[i][j] = 'X';

    	if (curr->letters[index]) {
    		string * location = curr->letters[index]->wordLocation;
    		if (location && check.find(*location) == check.end()) {
    			answer.push_back(*curr->letters[index]->wordLocation);
    			check.insert(*location);
    		}
    		for (int k = 0; k != 4; ++k) {
    			findWordsInBoard(board, i + dy[k], j + dx[k], curr->letters[index], answer, check);
    		}
    	}
    	board[i][j] = currentLetter;
    }

    bool inBoard(vector<vector<char>>& board, int i, int j) {
    	int row = board.size();
    	int col = board[0].size();

    	return i >= 0 && i < row && j >= 0 && j < col;
    }
};