class Solution {
public:
    vector<int> getRow(int rowIndex) {
        queue<int> nque;
        nque.push(0); nque.push(1);
        int cnt = 0;
        int first, second;
        vector<int> answer;
        if (!rowIndex) {
        	answer.push_back(1);
        	return answer;
        }
        while (cnt != rowIndex + 1){
        	first = nque.front();
        	nque.pop();
        	second = nque.front();
        	if (!first) {
        		nque.push(0);
        		++cnt;
        	}
        	if (cnt != rowIndex + 1)
        		nque.push(first + second);
        }
        while (!nque.empty()){
        	answer.push_back(nque.front());
			nque.pop();
        }
        answer.erase(--answer.end());
        return answer;
    }
};