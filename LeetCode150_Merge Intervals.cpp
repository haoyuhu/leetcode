/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> answer;
        sort(intervals.begin(), intervals.end(), [](const Interval &ia, const Interval &ib)->bool{return ia.start < ib.start;});
        for (auto interval : intervals) {
        	if (answer.empty())
        		answer.push_back(interval);
        	else {
        		Interval pre_interval = answer.back();
        		if (interval.start > pre_interval.end)
        			answer.push_back(interval);
        		else {
        			answer.pop_back();
        			answer.push_back(Interval(pre_interval.start, max(interval.end, pre_interval.end)));
        		}
        	}
        }
        return answer;
    }
};