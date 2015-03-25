class Solution {
public:
    string simplifyPath(string path) {
        deque<string> pathque;
        int len = path.size();
        string use;
        for (int i = 0; i != len; ++i){
        	if (isLetterOrNumber(path[i]))
        		use.push_back(path[i]);
        	else if (isDot(path[i]))
        		use.push_back(path[i]);
        	else {
        		if (!use.empty()) {
        			if (isName(use))
        				pathque.push_back(use);
        			else if (isBack(use)) {
        				if (!pathque.empty())
        					pathque.erase(--pathque.end());
        			}
        			else if (use != string("."))
        				pathque.push_back(use);
        			use.clear();
        		}
        	}
        }
        if (!use.empty()) {
        	if (isBack(use)) {
        		if (!pathque.empty())
        			pathque.erase(--pathque.end());
        	}
        	else if (use != string("."))
        		pathque.push_back(use);
        }
        string answer;
        deque<string>::iterator it;
        for (it = pathque.begin(); it != pathque.end(); ++it){
        	answer.push_back('/');
        	answer += *it;
        }
        if (answer.empty())
        	answer.push_back('/');
        return answer;
    }
    bool isLetterOrNumber(char ch) {
    	int t1 = ch - 'a';
    	int t2 = ch - 'A';
    	int t3 = ch - '0';
    	if (t1 >= 0 && t1 <= 25 || t2 >= 0 && t2 <= 25 || t3 >= 0 && t3 <= 9 || ch == '_')
    		return true;
    	else
    		return false;
    }
    bool isDot(char ch) {
    	return ch != '.' ? false : true;
    }
    bool isName(string s) {
    	return isLetterOrNumber(s[0]);
    }
    bool isBack(string s) {
    	return s != string("..") ? false : true;
    }
};