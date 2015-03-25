class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size(), col;
        if (row)
        	col = matrix[0].size();
        else
        	return;
        unordered_set<int> setrow, setcol;
        unordered_set<int>::iterator it;
        for (int i = 0; i != row; ++i){
        	for (int j = 0; j != col; ++j){
        		if (!matrix[i][j]) {
        			if (setrow.find(i) == setrow.end())
        				setrow.insert(i);
        			if (setcol.find(j) == setcol.end())
        				setcol.insert(j);
        		}
        	}
        }
        for (it = setrow.begin(); it != setrow.end(); ++it){
        	for (int j = 0; j != col; ++j){
        		matrix[*it][j] = 0;
        	}
        }
        for (int i = 0; i != row; ++i){
        	for (it = setcol.begin(); it != setcol.end(); ++it){
        		matrix[i][*it] = 0;
        	}
        }
        return ;
    }
};