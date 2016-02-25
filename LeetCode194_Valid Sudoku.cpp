class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	int scale = 9;
        for (int i = 0; i != scale; ++i) {
        	vector<bool> isAvailableInRow(10, true);
        	vector<bool> isAvailableInCol(10, true);
        	for (int j = 0; j != scale; ++j) {
        		int numInRow = getNumber(board[i][j]);
        		int numInCol = getNumber(board[j][i]);
	        	if (numInRow != 0) {
	        		if (isAvailableInRow[numInRow]) {
	        			isAvailableInRow[numInRow] = false;
	        		} else {
	        			return false;
	        		}
	        	}
	        	if (numInCol != 0) {
	        		if (isAvailableInCol[numInCol]) {
	        			isAvailableInCol[numInCol] = false;
	        		} else {
	        			return false;
	        		}
	        	}
        	}
        }

        int dx[] = {0, 1, 0, -1, 0, 1, -1, 1, -1};
        int dy[] = {0, 0, 1, 0, -1, -1, 1, 1, -1};

        for (int i = 1; i <= 7; i += 3) {
        	for (int j = 1; j <= 7; j += 3) {
        		vector<bool> isAvailable(10, true);
        		for (int k = 0; k != scale; ++k) {
        			int ix = i + dx[k];
        			int iy = j + dy[k];
        			int num = getNumber(board[ix][iy]);
	        		if (num != 0) {
	        			if (isAvailable[num]) {
	        				isAvailable[num] = false;
	        			} else {
	        				return false;
	        			}
	        		}
        		}
        	}
        }

        return true;
    }

private:
	int getNumber(char ch) {
		if (ch == '.') {
			return 0;
		} else {
			return static_cast<int> (ch - '0');
		}
	}
};
