class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int row = 0, cnt = 0, size = n;
        vector< vector<int> > answer(size, vector<int>(size));
        while (n > 0) {
        	for (int i = row; i != size - row - 1; ++i) {
        		answer[row][i] = ++cnt;
        	}
        	for (int i = row; i != size - row - 1; ++i) {
        		answer[i][size-row-1] = ++cnt;
        	}
        	for (int i = size - row - 1; i != row; --i) {
        		answer[size-row-1][i] = ++cnt;
        	}
        	for (int i = size - row - 1; i != row; --i) {
        		answer[i][row] = ++cnt;
        	}
        	if (n == 1)
        		answer[row][row] = ++cnt;
        	++row; n -= 2;
        }
        return answer;
    }
};