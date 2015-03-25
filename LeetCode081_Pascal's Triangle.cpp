class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        queue<int> nque;
        nque.push(0); nque.push(1);
        int cnt = 0;
        int first, second;
        vector< vector<int> > answer;
        if (!numRows)
        	return answer;
        answer.push_back(vector<int>(1, 1));
        if (numRows == 1)
        	return answer;
        while (cnt != numRows){
        	first = nque.front();
        	nque.pop();
        	second = nque.front();
        	if (!first) {
        		answer.push_back(vector<int>());
        		nque.push(0);
        		++cnt;
        	}
        	nque.push(first + second);
        	answer[cnt].push_back(first + second);
        }
        answer.erase(--answer.end());
        return answer;
    }
};