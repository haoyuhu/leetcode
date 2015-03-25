class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)
        	return s;
        string answer;
        int gap = 2 * nRows - 2;
        for (int i = 0; i != nRows; ++i){
        	int rear_gap = 2 * i;
        	int front_gap = gap - rear_gap;
        	if (!rear_gap || !front_gap) {
        		for (int k = i; k < s.size(); k += gap)
        			answer.push_back(s[k]);
        	}
        	else {
        		for (int k = i; k < s.size(); ){
        			answer.push_back(s[k]);
        			k += front_gap;
        			if (k >= s.size())
        				break;
        			else
        				answer.push_back(s[k]);
        			k += rear_gap;
        		}
        	}
        }
        return answer;
    }
};