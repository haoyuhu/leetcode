class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;

        vector<vector<int>> height(row, vector<int>(col, 0)), width(row, vector<int>(col, 0));
        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++i) {
        		if (i == 0) {
        			height[i][j] = matrix[i][j] == '1' ? 1 : 0;
        		} else {
        			height[i][j] = matrix[i][j] == '1' ? height[i-1][j] + 1 : 0;
        		}
        	}
        }
        for (int j = 0; j != col; ++j) {
        	for (int i = 0; i != row; ++i) {
        		if (j == 0) {
        			width[i][j] = matrix[i][j] == '1' ? 1 : 0;
        		} else {
        			width[i][j] = matrix[i][j] == '1' ? width[i][j-1] + 1 : 0;
        		}
        	}
        }

        int maxLength = 0;
        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++j) {
        		int localMaxLength = width[i][j] < height[i][j] ? width[i][j] : height[i][j];
        		if (localMaxLength > maxLength) {
        			maxLength = localMaxLength;
        		}
        	}
        }

        return maxLength * maxLength;
    }
};
//wrong

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;

        vector<vector<int>> height(row, vector<int>(col, 0));
        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++j) {
        		if (i == 0) {
        			height[i][j] = matrix[i][j] == '1' ? 1 : 0;
        		} else {
        			height[i][j] = matrix[i][j] == '1' ? height[i-1][j] + 1 : 0;
        		}
        	}
        }

        int maxLength = 0;
        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++j) {
        		int left, right, heightSaved = height[i][j], width, localMaxLength = 0;
        		left = right = j;
        		for (; left >= 0 && height[i][left] >= heightSaved; --left);
        		for (; right < col && height[i][right] >= heightSaved; ++right);
        		width = right - left - 1;
        		localMaxLength = width < heightSaved ? width : heightSaved;
        		if (localMaxLength > maxLength) {
        			maxLength = localMaxLength;
        		}
        	}
        }

        return maxLength * maxLength;
    }
};
//AC
