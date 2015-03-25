class Solution {
public:
    typedef struct Stack{
		char ch[10000];
		int top;
    }Stack;
	bool EmptyStack(Stack S){
		if (S.top == -1){
			return true;
		}
		else{
			return false;
		}
	}
	bool FullStack(Stack S){
		if (S.top == 9999){
			return true;
		}
		else{
			return false;
		}
	}
	void PopStack(Stack &S, char &ch){
		if (!EmptyStack(S)){
			ch = S.ch[S.top];
			--S.top;
		}
	}
	void PushStack(Stack &S, char ch){
		if (!FullStack(S)){
			++S.top;
			S.ch[S.top] = ch;
		}
	}
	int longestValidParentheses(string s) {
        Stack S;
		S.top = -1;
		int ct = 0;
		char tmp;
		for (int i = 0; i < s.length(); ++i){
			switch (s[i]){
			case ')':
				if (!EmptyStack(S) && S.ch[S.top] == '('){
					PopStack(S, tmp);
					++ct;
				}
				break;
			case '(':
				PushStack(S, s[i]); break;
			}
		}
		return 2 * ct;
    }
};

//
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (!len)
        	return 0;
        int cntleft[len], cntright[len];
        int max = 0, cntl = 0, cntr = 0;
        for (int i = 0; i != len; ++i){
        	cntleft[i] = cntright[i] = 0;
        	if (!i) {
        		if (s[i] == '(')
        			cntleft[i] = 1;
        		else
        			cntright[i] = 1;
        	}
        	else {
        		if (s[i] == '(') {
        			cntleft[i] = cntleft[i-1] + 1;
        			cntright[i] = cntright[i-1];
        		}
        		else {
        			cntleft[i] = cntleft[i-1];
        			cntright[i] = cntright[i-1] + 1;
        		}
        	}
        }
        for (int i = 0; i < len; ++i){
        	if (cntleft[i] - cntl >= cntright[i] - cntr)
        		max = max_val(cntright[i] - cntr, max);
        	else {
        		cntl = cntleft[i];
        		cntr = cntright[i];
        	}
        }
        return max * 2;
    }
    int max_val(int ix, int iy){
    	return ix > iy ? ix : iy;
    }
};

//
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pstk;
        stack<int> lftstk;
        int max = 0;
        for (int i = 0; i != s.size(); ++i){
        	if (s[i] == '(') {
        		if (pstk.empty() || !pstk.empty() && pstk.top()) {
        			pstk.push(0); lftstk.push(1);
        		}
        		else {
        			int cnt = lftstk.top();
        			lftstk.pop(); lftstk.push(++cnt);
        		}
        	}
        	else {
        		if (!pstk.empty()) {
        			int cnt = lftstk.top();
        			int pair = pstk.top();
        			--cnt; ++pair;
        			lftstk.pop(); pstk.pop();
        			if (cnt > 0) {
        				pstk.push(pair); lftstk.push(cnt);
        			}
        			else if (!cnt) {
        				if (pstk.empty()) {
        					pstk.push(pair); lftstk.push(0);
        				}
        				else {
        					int pair_pre = pstk.top();
        					pstk.pop(); pstk.push(pair_pre + pair);
        				}
        			}
        			else
        				max = max_val(max, --pair);
        		}
        	}
        }
        while (!pstk.empty()){
        	max = max_val(max, pstk.top());
        	pstk.pop();
        }
        return max * 2;
    }
    int max_val(int ix, int iy){
    	return ix > iy ? ix : iy;
    }
};