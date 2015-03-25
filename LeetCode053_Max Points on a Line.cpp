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
	#define MAX_INT 999999999.0
	bool compare_points(const Point &p1, const Point &p2){
		return p1.x == p2.x && p1.y == p2.y;
	}
    int maxPoints(vector<Point> &points) {
    	if (!points.size())
    		return 0;
        multiset<double> linearset;
        vector<Point>::iterator it_end = unique(points.begin(), points.end(), compare_points);
        points.erase(it_end, points.end());
        for (int i = 0; i != points.size() - 1; ++i){
        	for (int j = i + 1; j != points.size(); ++j){
        		int x1 = points[i].x, y1 = points[i].y;
        		int x2 = points[j].x, y2 = points[j].y;
        		double k = x1 != x2 ? (y2 - y1) / (x2 - x1) : MAX_INT;
        		linearset.insert(k);
        	}
        }
        int cnt = 0, max = 0;
	    for (multiset<double>::iterator itf = linearset.begin(), its = linearset.begin(); 
	    	 itf != linearset.end(); ){
	    	if (*itf == *its) {
	    		++cnt; ++itf;
	    	}
	    	else {
	    		if (max < cnt) max = cnt;
	    		cnt = 0;
	    		its = itf;
	    	}
	    }
	    if (cnt > max)
	    	max = cnt;
	    return (1 + sqrt(1 + 8 * max)) / 2;
    }
};