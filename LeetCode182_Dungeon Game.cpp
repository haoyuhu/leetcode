class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        for (int i = row - 1; i >= 0; --i) {
        	for (int j = col - 1; j >= 0; --j) {
        		solveCurrentMinValue(dungeon, row, col, i, j);
        	}
        }
        return dungeon[0][0] + 1;
    }

    void solveCurrentMinValue(vector<vector<int>>& dungeon, int row, int col, int i, int j) {
    	pair<int, int> rightPoint(make_pair(i, j + 1)), lowerPoint(make_pair(i + 1, j));
    	int lower, right, min, MAX_INT;
    	bool hasLower, hasRight;
    	lower = right = 0;
    	hasLower = hasRight = true;
    	MAX_INT = 999999999;

    	if (rightPoint.first < row && rightPoint.second < col) {
    		right = dungeon[rightPoint.first][rightPoint.second];
    	} else {
    		hasRight = false;
    	}
    	if (lowerPoint.first < row && lowerPoint.second < col) {
    		lower = dungeon[lowerPoint.first][lowerPoint.second];
    	} else {
    		hasLower = false;
    	}

    	if (!hasLower && !hasRight) {
    		min = 0;
    	} else {
    		min = minValue(hasLower ? lower : MAX_INT, hasRight ? right : MAX_INT);
    	}

    	int current = min - dungeon[i][j];
    	dungeon[i][j] = current >= 0 ? current : 0;
    }

    int minValue(int x, int y) {
    	return x < y ? x : y;
    }
};
