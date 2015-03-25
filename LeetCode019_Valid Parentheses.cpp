class Solution {
public:
    typedef struct Stack{
		char ch[10000];
		int top;
    }Stack;
	void InitStack(Stack &S){
		S.top = -1;
		return;
	}
	bool isEmptyStack(Stack S){
		if (S.top == -1){
			return true;
		}
		else{
			return false;
		}
	}
	bool isFullStack(Stack S){
		if (S.top == 9999){
			return true;
		}
		else{
			return false;
		}
	}
	void PushStack(Stack &S, char ch){
		if (isFullStack(S)){
			return;
		}
		++S.top;
		S.ch[S.top] = ch;
	}
	void PopStack(Stack &S, char &ch){
		if (!isEmptyStack(S)){
			ch = S.ch[S.top];
			S.top--;
		}
	}
    bool isValid(string s) {
        Stack S;
		InitStack(S);
		char tmp;
		int i = 0, len = s.length();
		while (i < len){
			switch (s[i]){
			case '(':
			case '{':
			case '[': 
				PushStack(S, s[i]); break;
			case ')':
				if (!isEmptyStack(S) && S.ch[S.top] == '('){
					PopStack(S, tmp);
				}
				else{
					return false;
				}
				break;
			case ']':
				if (!isEmptyStack(S) && S.ch[S.top] == '['){
					PopStack(S, tmp);
				}
				else{
					return false;
				}
				break;
			case '}':
				if (!isEmptyStack(S) && S.ch[S.top] == '{'){
					PopStack(S, tmp);
				}
				else{
					return false;
				}
				break;
			}
			++i;
		}
		if (isEmptyStack(S)){
			return true;
		}
		else{
			return false;
		}
    }
};