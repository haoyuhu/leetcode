class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> answer;
        int size = tokens.size();
        if (!size)
        	return 0;
        for (int i = 0; i != size; ){
        	while (i != size && isdigit(tokens[i])){
        		answer.push(atoi(tokens[i].c_str()));
        		++i;
        	}
        	if (i == size)
        		break;
        	int numl, numr;
        	numr = answer.top(); answer.pop();
        	numl = answer.top(); answer.pop();
        	answer.push(calculation(numl, numr, tokens[i]));
        	++i;
        }
        return answer.top();
    }
    bool isdigit(string s) {
    	string t("0123456789");
    	if (find(t.begin(), t.end(), s[s.size()-1]) != t.end())
    		return true;
    	else
    		return false;
    }
    int calculation(int numl, int numr, string s) {
    	switch (s[0]) {
    		case '+': return numl + numr;
    		case '-': return numl - numr;
    		case '*': return numl * numr;
    		case '/': return numl / numr;
    	}
    }
};