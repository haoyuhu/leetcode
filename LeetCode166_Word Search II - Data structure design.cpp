class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> answer;
        int row = board.size();
        int col = board[0].size();
        vector<vector<pair<int, int>>> store(26);

        for (int i = 0; i != row; ++i) {
            for (int j = 0; j != col; ++j) {
                int index = find(board[i][j]);
                store[index].push_back(make_pair(i, j));
            }
        }

        for (string word : words) {
            if (!word.size()) {
                answer.push_back("");
                break;
            }
            int index = find(word[0]);
            for (auto pair : store[index]) {
                if (search(board, pair.first, pair.second, word, 0)) {
                    answer.push_back(word);
                }
            }
        }
        return answer;
    }

    int find(char letter) { return static_cast<int> (letter - 'a'); }

    bool search(vector<vector<char>>& board, int i, int j, string word, int k) {
        if (++k == word.size()) return true;
        board[i][j] = 'X';
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int s = 0; s != 4; ++s) {
            int new_i = i + dy[s], new_j = j + dx[s];
            if (inBoard(board, new_i, new_j) 
                && board[new_i][new_j] == word[k] 
                && search(board, new_i, new_j, word, k)) {
                board[i][j] = word[--k];
                return true;
            }
        }
        board[i][j] = word[--k];
        return false;
    }

    bool inBoard(vector<vector<char>>& board, int i, int j) {
        int row = board.size(), col = board[0].size();
        return i < row && i >= 0 && j < col && j >= 0;
    }
};