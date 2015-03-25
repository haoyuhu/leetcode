class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector< vector<int> > answer;
        int size = candidates.size();
        bool tag[target+1];
        vector< vector< vector<int> > > path(size, vector< vector<int> >(target+1));
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= target; ++i)
            tag[i] = false;
        tag[0] = true;
        for (int i = 0; i != size; ++i) {
            for (int j = 0; j <= target; ++j) {
                int pre = j - candidates[i];
                if (tag[j])
                    path[i][j].push_back(0);
                if (pre >= 0 && tag[pre]) {
                    tag[j] = true;
                    for (int k = 0; k != path[i][pre].size(); ++k) {
                        path[i][j].push_back(path[i][pre][k] + 1);
                    }
                }
            }
        }
        if (tag[target])
            make_combination(answer, path, size - 1, target, candidates, vector<int>());
        return answer;
    }
    void make_combination(vector< vector<int> > &answer, vector< vector< vector<int> > > &path,
        int index, int target, vector<int> &candidates, vector<int> tvec) {
        if (!target) {
            answer.push_back(tvec); return;
        }
        int size = path[index][target].size();
        for (int i = 0; i != size; ++i) {
            vector<int> t(tvec);
            t.insert(t.begin(), path[index][target][i], candidates[index]);
            make_combination(answer, path, index - 1, target - path[index][target][i] * candidates[index],
                candidates, t);
        }
    }
};//AC!