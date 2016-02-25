class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        vector<bool> isStarted;
        for (vector<int>& building : buildings) {
        	points.push_back(make_pair(building[0], building[2]));
        	points.push_back(make_pair(building[1], building[2]));
        	isStarted.push_back(false);
        	isStarted.push_back(true);
        }
        sortPoints(points, isStarted, 0, points.size() - 1);

        multiset<int> height;
        vector<pair<int, int>> answer;
        int currentHeight, previousHeight = 0;
        for (int i = 0; i != points.size(); ++i) {
        	if (isStarted[i]) {
        		int count = height.erase(points[i].second);
        		while (--count) {
        			height.insert(points[i].second);
        		}
        	} else {
        		height.insert(points[i].second);
        	}
	        if (i + 1 >= points.size() || points[i].first != points[i+1].first) {
				if (!height.empty()) {
	        		currentHeight = *(height.rbegin());
	        		if (currentHeight != previousHeight) {
	        			answer.push_back(make_pair(points[i].first, currentHeight));
	        			previousHeight = currentHeight;
	        		}
	        	} else {
	        		answer.push_back(make_pair(points[i].first, 0));
	        		previousHeight = 0;
	        	}
	        }
        }
        return answer;
    }
private:
	void sortPoints(vector<pair<int, int>>& points, vector<bool>& isStarted, int bottom, int top) {
		if (bottom >= top) {
			return;
		}
		int i = bottom, j = top;
		pair<int, int> savePoint = points[bottom];
		bool saveState = isStarted[bottom];
		while (i < j) {
			for (; i < j && points[j].first >= savePoint.first; --j);
			points[i].first = points[j].first;
			points[i].second = points[j].second;
			isStarted[i] = isStarted[j];
			for (; i < j && points[i].first <= savePoint.first; ++i);
			points[j].first = points[i].first;
			points[j].second = points[i].second;
			isStarted[j] = isStarted[i];
		}
		points[i].first = savePoint.first;
		points[i].second = savePoint.second;
		isStarted[i] = saveState;

		sortPoints(points, isStarted, bottom, i - 1);
		sortPoints(points, isStarted, i + 1, top);
	}
};