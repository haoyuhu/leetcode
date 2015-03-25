class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        typedef vector< vector<int> > ivvector;
        int row = matrix.size();
        if (!row)
        	return;
        int col = matrix[0].size();
        ivvector answer(matrix);
        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++j) {
        		answer[j][col-i-1] = matrix[i][j];
        	}
        }
        swap(matrix, answer);
    }
};