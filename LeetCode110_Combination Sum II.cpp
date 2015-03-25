class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int size = num.size();
        vector< vector< vector<bool> > > path(size + 1, vector< vector<bool> >(target + 1, vector<bool>(2, false)));
        // bool path[size][target+1][2], tag[target+1];
        bool tag[target+1];
        for (int i = 0; i <= target; ++i){
        	tag[i] = false;
        }
        tag[0] = true;
        for (int i = 1; i <= size; ++i){
        	for (int j = target; j >= 0; --j){
        		if (tag[j])
        			path[i][j][0] = true;
        		// else
        		// 	path[i][j][0] = false;
        		if (j - num[i-1] >= 0 && tag[j-num[i-1]]) {
        			path[i][j][1] = true;
        			tag[j] = true;
        		}
        		// else
        		// 	path[i][j-num[i]][1] = false;
        	}
        }
        vector< vector<int> > answer;
        vector<int> now;
        if (tag[target])
        	create_answer(num, answer, path, size, target, now);
        sort(answer.begin(), answer.end());
        vector< vector<int> >::iterator it = unique(answer.begin(), answer.end());
        answer.erase(it, answer.end());
        return answer;
    }
    void create_answer(const vector<int> &num, vector< vector<int> > &answer, 
    				   const vector< vector< vector<bool> > > &path, int i, int j, vector<int> now) {
    	if (i == 0 && j == 0) {
    		sort(now.begin(), now.end());
    		answer.push_back(now);
    		return;
    	}
    	if (path[i][j][0])
    		create_answer(num, answer, path, i - 1, j, now);
    	if (path[i][j][1]) {
    		now.push_back(num[i-1]);
    		create_answer(num, answer, path, i - 1, j - num[i-1], now);
    	}
    }
};