class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector< vector<int> > answer;
        vector<int> use;
        permute_solution(answer, use, num);
        sort(answer.begin(), answer.end());
        vector< vector<int> >::iterator it = unique(answer.begin(), answer.end());
        answer.erase(it, answer.end());
        return answer;
    }
    void permute_solution(vector< vector<int> > &answer, vector<int> use, 
    	vector<int> num) {
    	if (!num.size()) {
    		answer.push_back(use); return;
    	}
    	vector<int>::iterator it;
    	for (it = num.begin(); it != num.end(); ++it) {
    		vector<int> use_cp(use);
    		use_cp.push_back(*it); it = num.erase(it);
    		permute_solution(answer, use_cp, num);
    		it = num.insert(it, use_cp.back());
    	}
    }
};