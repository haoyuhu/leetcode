class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector< vector<int> > answer;
        sort(S.begin(), S.end());
        solute_answer(answer, S, 0, vector<int>());
        return answer;
    }
    void solute_answer(vector< vector<int> > &answer, const vector<int> &set, 
    					int index, vector<int> now) {
    	if (index == set.size()) {
    		answer.push_back(now); return;
    	}
    	solute_answer(answer, set, index + 1, now);
    	now.push_back(set[index]);
    	solute_answer(answer, set, index + 1, now);
    }
};