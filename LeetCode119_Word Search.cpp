class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size(), col;
        if (row)
        	col = board[0].size();
        else
        	return false;
        bool isfound = false;
        vector< vector<bool> > isvisited(row, vector<bool>(col, false));
        for (int i = 0; i != row; ++i){
        	for (int j = 0; j != col; ++j){
        		if (SearchPath(board, isvisited, i, j, word, 0)) {
        			isfound = true; break;
        		}
        	}
        }
        return isfound;
    }
    bool SearchPath(vector< vector<char> > &board, vector< vector<bool> > &isvisited, 
    				int x, int y, const string &word, int index) {
    	if (index == word.size() - 1 && !isvisited[x][y] && word[index] == board[x][y])
    		return true;
    	if (word[index] != board[x][y])
    		return false;
    	int dx[4] = {1, 0, -1, 0};
    	int dy[4] = {0, 1, 0, -1};
    	isvisited[x][y] = true;
    	bool isfound = false;
    	for (int i = 0; i != 4; ++i){
    		int newx = x + dx[i], newy = y + dy[i];
    		if (inrange(newx, board.size()) && inrange(newy, board[0].size()) && !isvisited[newx][newy])
    			if (SearchPath(board, isvisited, newx, newy, word, index + 1)) {
    				isfound = true; break;
    			}
    	}
    	isvisited[x][y] = false;
    	return isfound;
    }
    bool inrange(int x, int bound) {
    	if (x >= 0 && x < bound)
    		return true;
    	else
    		return false;
    }
};