class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer;
        solute_graycode(answer, 0, n);
        return answer;
    }
    void solute_graycode(vector<int> &answer, int num, int cnt) {
    	if (!cnt) {
    		answer.push_back(num);
    		return;
    	}
    	num <<= 1;
    	solute_graycode(answer, num, cnt - 1);
    	solute_graycode(answer, num + 1, cnt - 1);
    }
};
//
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> answer(size);
        for (int i = 0; i != size; ++i) {
        	answer[i] = i ^ (i >> 1);
        }
        return answer;
    }
};