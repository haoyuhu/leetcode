class Solution {
public:
	typedef struct Point {
		int x, y;
	}Point;
    vector<vector<string> > solveNQueens(int n) {
        vector< vector<string> > answer;
        vector<Point> queen;
        NQueensProblem(answer, 0, n, queen);
        return answer;
    }
    void NQueensProblem(vector< vector<string> > &answer, int row, int size, vector<Point> queen) {
    	for (int i = 0; i != size; ++i) {
    		bool canPlace = true;
    		for (int k = 0; k != queen.size(); ++k) {
    			if (!judge_location(queen[k].x, queen[k].y, row, i)) {
    				canPlace = false; break;
    			}
    		}
    		if (canPlace) {
	    		Point pnt;
	    		pnt.x = row; pnt.y = i;
	    		vector<Point> queen_cp(queen);
	    		queen_cp.push_back(pnt);
	    		if (row != size - 1)
	    			NQueensProblem(answer, row + 1, size, queen_cp);
	    		else {
	    			vector<string> solute;
		    		for (int x = 0; x != size; ++x) {
		    			string t;
		    			for (int j = 0; j != size; ++j) {
		    				if (j != queen_cp[x].y)
		    					t.push_back('.');
		    				else
		    					t.push_back('Q');
		    			}
		    			solute.push_back(t);
		    		}
		    		answer.push_back(solute);
	    		}
    		}
    	}
    }
    bool judge_location(int qx, int qy, int newx, int newy) {
    	if (qy == newy || abs(qx - newx) == abs(qy - newy))
    		return false;
    	else
    		return true;
    }
};