class Solution {
public:
    void solve(vector<vector<char>> &board) {
    	int row = board.size();
        if (!row) return;
        int col = board[0].size();
        vector< vector<bool> > visited(row, vector<bool>(col, true));
        for (int i = 0; i != row; ++i) {
        	if (board[i][0] != 'X' && visited[i][0])
        		findAreaOutofBoard(board, i, 0, visited);
        	if (board[i][col-1] != 'X' && visited[i][col-1])
        		findAreaOutofBoard(board, i, col-1, visited);
        }
        for (int j = 0; j != col; ++j) {
        	if (board[0][j] != 'X' && visited[0][j])
        		findAreaOutofBoard(board, 0, j, visited);
        	if (board[row-1][j] != 'X' && visited[row-1][j])
        		findAreaOutofBoard(board, row-1, j, visited);
        }
        for (int i = 0; i != row; ++i) {
        	for (int j = 0; j != col; ++j) {
        		if (board[i][j] != 'X' && visited[i][j])
        			board[i][j] = 'X';
        	}
        }
    }
    void findAreaOutofBoard(vector< vector<char> > &board, int i, int j, vector< vector<bool> > &visited) {
        if (board[i][j] == 'X') return;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        visited[i][j] = false;
        for (int k = 0; k != 4; ++k) {
            if (inMatrix(i + dx[k], j + dy[k], board.size(), board[0].size()) && visited[i+dx[k]][j+dy[k]])
                findAreaOutofBoard(board, i + dx[k], j + dy[k], visited);
        }
    }
    bool inMatrix(int i, int j, int row, int col) {
        if (i < row && i >= 0 && j < col && j >= 0)
            return true;
        else
            return false;
    }
};
//
class Solution {  
public:    
    int m, n;  
      
    void traversal(int x, int y, vector<vector<char>> &board) {  
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {  
            board[x][y] = 'Z';  
            traversal(x - 1, y, board);  
            traversal(x + 1, y, board);  
            traversal(x, y - 1, board);  
            traversal(x, y + 1, board);  
        }      
    }  
      
    void solve(vector<vector<char>> &board) {  
        if (board.empty() || board.size() == 0 || board[0].size() == 0) {  
            return;  
        }  
        m = board.size(), n = board[0].size();  
        for (int i = 0; i < n; i++) {  
            traversal(0, i, board);  
            traversal(m - 1, i, board);  
        }  
        for (int i = 0; i < m; i++) {  
            traversal(i, 0, board);  
            traversal(i, n - 1, board);  
        }  
        for (int i = 0; i < m; i++) {  
            for (int j = 0; j < n; j++) {  
                board[i][j] = board[i][j] == 'Z' ? 'O' : 'X';  
            }  
        }  
    }  
};  
//
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int row = board.size();
        if (!row) return;
        int col = board[0].size();
        for (int i = 0; i != row; ++i) {
            bfs(board, i, 0);
            bfs(board, i, col - 1);
        }
        for (int j = 0; j != col; ++j) {
            bfs(board, 0, j);
            bfs(board, row - 1, j);
        }
        for (int i = 0; i != row; ++i) {
            for (int j = 0; j != col; ++j) {
                board[i][j] = board[i][j] == 'P' ? 'O' : 'X'; 
            }
        }
    }
    void bfs(vector<vector<char>> &board, int i, int j) {
        int row = board.size(), col = board[0].size();
        queue<int> ix, iy;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        ix.push(i); iy.push(j);
        while (!ix.empty()) {
            int x = ix.front(), y = iy.front();
            ix.pop(); iy.pop();
            if (board[x][y] == 'O') {
                board[x][y] = 'P';
                for (int k = 0; k != 4; ++k) {
                    int newx = x + dx[k], newy = y + dy[k];
                    if (newx >= 0 && newx < row && newy >= 0 && newy < col) {
                        ix.push(newx); iy.push(newy);
                    }
                }
            }
        }
    }
};