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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int s, i;
        vector<Interval> answer;
        for (i = 0; i != intervals.size() && intervals[i].end < newInterval.start; ++i) {
        	answer.push_back(intervals[i]);
        }
        if (i == intervals.size()) {
        	answer.push_back(newInterval); return answer;
        }
        s = intervals[i].start > newInterval.start ? newInterval.start : intervals[i].start;
        for (; i != intervals.size() && intervals[i].end < newInterval.end; ++i);
        if (i == intervals.size()) {
        	answer.push_back(Interval(s, newInterval.end)); return answer;
        }
        if (newInterval.end < intervals[i].start) {
        	answer.push_back(Interval(s, newInterval.end));
        }
        else {
        	answer.push_back(Interval(s, intervals[i].end)); ++i;
        }
        for (; i != intervals.size(); ++i)
        	answer.push_back(intervals[i]);
        return answer;
    }
};