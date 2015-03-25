class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> answer;
        int row, rowsize = matrix.size();
        if (!rowsize)
            return answer;
        int colsize = matrix[0].size();
        for (row = 0; row != min(rowsize, colsize) / 2; ++row) {
            int inrow, incol;
            for (incol = row; incol < colsize - row - 1; ++incol)
                answer.push_back(matrix[row][incol]);
            for (inrow = row; inrow < rowsize - row - 1; ++inrow)
                answer.push_back(matrix[inrow][colsize-row-1]);
            for (incol = colsize - row - 1; incol > row; --incol)
                answer.push_back(matrix[rowsize-row-1][incol]);
            for (inrow = rowsize - row - 1; inrow > row; --inrow)
                answer.push_back(matrix[inrow][row]);
        }
        if (rowsize % 2 && rowsize <= colsize) {
            for (int i = rowsize / 2; i < colsize - rowsize / 2; ++i)
                answer.push_back(matrix[rowsize/2][i]);
        }
        else if (colsize % 2 && colsize < rowsize) {
            for (int i = colsize / 2; i < rowsize - colsize / 2; ++i)
                answer.push_back(matrix[i][colsize/2]);
        }
        return answer;
    }
};