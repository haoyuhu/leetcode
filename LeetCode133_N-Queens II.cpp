class Solution {
public:
    int totalNQueens(int n) {
    	if (!n)
    		return 0;
        vector< vector<bool> > canPlace(n, vector<bool>(n, true));
        return NQueensProblem(canPlace, 0);
    }
    int NQueensProblem(vector< vector<bool> > canPlace, int row) {
    	bool is_finished = false;
    	int size = canPlace.size(), answer = 0;
    	for (int i = 0; i != size; ++i) {
    		if (canPlace[row][i]) {
    			vector< vector<bool> > tag_cp(canPlace);
    			for (int k = row, stp = 0; k != size; ++k, ++stp) {
    				tag_cp[k][i] = false;
    				if (inMatrix(k, i - stp, size))
    					tag_cp[k][i-stp] = false;
    				if (inMatrix(k, i + stp, size))
    					tag_cp[k][i+stp] = false;
    			}
    			if (row != size - 1)
    				answer += NQueensProblem(tag_cp, row + 1);
    			else
    				answer += 1;
    		}
    	}
    	return answer;
    }
    bool inMatrix(int i, int j, int size) {
    	if (i >= 0 && i < size && j >= 0 && j < size)
    		return true;
    	else
    		return false;
    }
};//Time Limit Exceeded
//
class Solution {
public:
	typedef struct Point {
		int x, y;
	}Point;
    int totalNQueens(int n) {
        if (!n)
        	return 0;
        vector<Point> queen;
        return NQueensProblem(queen, 0, n); 
    }
    int NQueensProblem(vector<Point> queen, int row, int size) {
    	int answer = 0;
    	for (int i = 0; i != size; ++i) {
    		bool canPlace = true;
    		for (int k = 0; k != queen.size(); ++k) {
    			if (!judge_location(queen[k].x, queen[k].y, row, i)) {
    				canPlace = false; break;
    			}
    		}
    		if (canPlace) {
    			if (row != size - 1) {
	    			Point pnt;
	    			pnt.x = row; pnt.y = i;
	    			vector<Point> queen_cp(queen);
	    			queen_cp.push_back(pnt);
	    			answer += NQueensProblem(queen_cp, row + 1, size);
    			}
    			else
    				answer += 1;
    		}
    	}
    	return answer;
    }
    bool judge_location(int qx, int qy, int newx, int newy) {
    	if (qy == newy || abs(qx - newx) == abs(qy - newy))
    		return false;
    	else
    		return true;
    }
};
