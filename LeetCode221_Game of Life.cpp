class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board_copy = board;
        int row = board.size();
        int col = board[0].size();
        int scale = 8;
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++j) {
        		int count_live = 0, count_dead = 0;
        		for (int k = 0; k != scale; ++k) {
        			int new_i = i + dx[k], new_j = j + dy[k];
        			if (isInBoard(new_i, new_j, row, col) && board[new_i][new_j] != 0) {
        				++count_live;
        			} else {
        				++count_dead;
        			}
        		}
        		if (board[i][j] != 0) {
        			if (count_live < 2 || count_live > 3) {
        				board_copy[i][j] = 0;
        			} else {
        				board_copy[i][j] = 1;
        			}
        		} else {
        			if (count_live == 3) {
        				board_copy[i][j] = 1;
        			} else {
        				board_copy[i][j] = 0;
        			}
        		}
        	}
        }
        board = board_copy;
    }

    bool isInBoard(int i, int j, int row, int col) {
    	return i >= 0 && i < row && j >= 0 && j < col;
    }
};