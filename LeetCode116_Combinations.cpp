class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector< vector<int> > answer;
        create_combine_sets(answer, vector<int>(), 1, n, 0, k);
        return answer;
    }
    void create_combine_sets(vector<vector<int> > &answer, vector<int> now, 
    						int i, int top_bound, int count, int size) {
    	if (count == size) {
    		answer.push_back(now); return;
    	}
    	if (top_bound - i + 1 < size - count)
    		return;
    	create_combine_sets(answer, now, i + 1, top_bound, count, size);
    	now.push_back(i);
    	create_combine_sets(answer, now, i + 1, top_bound, count + 1, size);
    }
};