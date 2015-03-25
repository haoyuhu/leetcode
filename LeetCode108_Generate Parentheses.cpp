class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        if (!n)
        	return answer;
        string s;
        buildParenthesis(answer, s, 0, 0, n);
        return answer;
    }
    void buildParenthesis(vector<string> &answer, string s, int left, int right, int size) {
    	if (left == size && right == size) {
    		answer.push_back(s); return;
    	}
    	string t(s);
    	if (left == right) {
    		s.push_back('(');
    		buildParenthesis(answer, s, 1 + left, right, size);
    	}
    	else {
    		if (left == size) {
    			s.push_back(')');
    			buildParenthesis(answer, s, left, 1 + right, size);
    		}
    		else {
    			s.push_back('(');
    			t.push_back(')');
    			buildParenthesis(answer, s, 1 + left, right, size);
    			buildParenthesis(answer, t, left, 1 + right, size);
    		}
    	}
    }
};