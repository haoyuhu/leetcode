/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int pointsNumber = points.size();
        if (pointsNumber == 0) {
            return 0;
        }
        vector<int> pointsCounter;
        vector<Point> cpPoints;
        for (int i = 0; i != pointsNumber; ++i) {
            bool isNewPoint = true;
            int index = 0;
            for (int j = 0; j != cpPoints.size(); ++j) {
                if (cpPoints[j].x == points[i].x && cpPoints[j].y == points[i].y) {
                    isNewPoint = false;
                    index = j;
                    break;
                }
            }
            if (isNewPoint) {
                cpPoints.push_back(points[i]);
                pointsCounter.push_back(1);
            } else {
                pointsCounter[index] += 1;
            }
        }

        unordered_map<double, int> kStore;
        int maxCount = 0;
        for (int i = 0; i < cpPoints.size(); ++i) {
        	for (int j = i + 1; j < cpPoints.size(); ++j) {
        		double dx = cpPoints[i].x - cpPoints[j].x;
        		double dy = cpPoints[i].y - cpPoints[j].y;
        		double k = dx == 0 ? MAX_INT : dy / dx;
        		unordered_map<double, int>::iterator it = kStore.find(k);
        		if (it != kStore.end()) {
        			it->second += pointsCounter[j];
        		} else {
        			kStore.insert(make_pair(k, pointsCounter[i] + pointsCounter[j]));
        		}
        	}
        	for (unordered_map<double, int>::const_iterator it = kStore.begin(); it != kStore.end(); ++it) {
        		maxCount = max(maxCount, it->second);
        	}
        	kStore.clear();
        }
        return maxCount ? maxCount : points.size();
    }
private:
	double MAX_INT = 999999999;
};