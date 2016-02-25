class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        makePermute(vector<int>(), nums);
        return answer;
    }
private:
	vector<vector<int>> answer;
	void makePermute(vector<int> current, vector<int> remain) {
		int size = remain.size();
		if (size == 0) {
			answer.push_back(current);
			return;
		}
		for (int i = 0; i != size; ++i) {
			vector<int> next(current), nextRemain(remain);
			next.push_back(remain[i]);
			nextRemain.erase(nextRemain.begin() + i);
			makePermute(next, nextRemain);
		}
	}
};