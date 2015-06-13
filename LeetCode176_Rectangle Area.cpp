class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        pair<int, int> rectA[] = {make_pair(A, D), make_pair(C, D), make_pair(C, B), make_pair(A, B)};
        pair<int, int> rectB[] = {make_pair(E, H), make_pair(G, H), make_pair(G, F), make_pair(E, F)};
        int pointsNumberAInB = 0;
        int pointsNumberBInA = 0;
        int sa = (C - A) * (D - B), sb = (G - E) * (H - F), s = sa + sb;
        vector<int> AInB, BInA;
        for (int i = 0; i != 4; ++i) {
        	if (isInThisRectangle(rectB[1], rectB[3], rectA[i])) {
        		pointsNumberAInB += 1;
        		AInB.push_back(i);
        	}
        	if (isInThisRectangle(rectA[1], rectA[3], rectB[i])) {
        		pointsNumberBInA += 1;
        		BInA.push_back(i);
        	}
        }
        if (pointsNumberAInB == pointsNumberBInA) {
        	if (pointsNumberBInA == 1) {
        		return s - solveArea(rectA[AInB.front()], rectB[BInA.front()]);
        	} else {
        		if (rectA[1].first <= rectB[3].first || rectA[3].first >= rectB[1].first
        		|| rectA[3].second >= rectB[1].second || rectA[1].second <= rectB[3].second) {
        			return s;
        		} else {
        			return s - solveArea(make_pair(min(rectA[1].first, rectB[1].first), min(rectA[1].second, rectB[1].second))
        				, make_pair(max(rectA[3].first, rectB[3].first), max(rectA[3].second, rectA[3].second)));
        		}
        	}
        } else {
        	if (pointsNumberAInB == 4) {
        		return sb;
        	} else if (pointsNumberBInA == 4) {
        		return sa;
        	} else if (pointsNumberAInB == 2) {
        		int p1 = AInB[0], p2 = AInB[1];
        		if (p1 == 2 && p2 == 3) {
        			return s - solveArea(make_pair(rectA[2].first, rectB[1].second), rectA[3]);
        		} else if (p1 == 0 && p2 == 3) {
        			return s - solveArea(make_pair(rectB[1].first, rectA[0].second), rectA[3]);
        		} else if (p1 == 0 && p2 == 1) {
        			return s - solveArea(rectA[1], make_pair(rectA[0].first, rectB[3].second));
        		} else {
        			return s - solveArea(rectA[1], make_pair(rectB[3].first, rectA[2].second));
        		}
        	} else {
        		int p1 = BInA[0], p2 = BInA[1];
        		if (p1 == 2 && p2 == 3) {
        			return s - solveArea(make_pair(rectB[2].first, rectA[1].second), rectB[3]);
        		} else if (p1 == 0 && p2 == 3) {
        			return s - solveArea(make_pair(rectA[1].first, rectB[0].second), rectB[3]);
        		} else if (p1 == 0 && p2 == 1) {
        			return s - solveArea(rectB[1], make_pair(rectB[0].first, rectA[3].second));
        		} else {
        			return s - solveArea(rectB[1], make_pair(rectA[3].first, rectB[2].second));
        		}
        	}
        }
    }

    bool isInThisRectangle(pair<int, int> rightTop, pair<int, int> leftBottom, pair<int, int> point) {
    	int x = point.first, y = point.second;
    	return x < rightTop.first && x > leftBottom.first && y < rightTop.second && y > leftBottom.second;
    }

    int solveArea(pair<int, int> rightTop, pair<int, int> leftBottom) {
    	int value = (rightTop.first - leftBottom.first) * (rightTop.second - leftBottom.second);
    	return abs(value);
    }
};
