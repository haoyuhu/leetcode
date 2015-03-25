class Solution {
public:
    typedef struct Snode{
    	char ch[1000];
    	int top;
    }Stack;
    void PushStack(Stack &S, char ch){
    	++S.top;
		S.ch[S.top] = ch;
		return;
    }
    void PopStack(Stack &S, char &ch){
    	ch = S.ch[S.top];
    	--S.top;
    }
	int lengthOfLastWord(const char *s) {
        Stack S;
        S.top = -1;
        int i = 0, ct = 0;
        char ch;
        bool tag = false;
        while (s[i] != '\0'){
        	PushStack(S, s[i]);
        	++i;
        }
        while (S.top != -1){
			if (S.ch[S.top] == ' ') PopStack(S, ch);
			else break;
        }
        if (S.top == -1) return 0;
        while (S.top != -1){
        	if (S.ch[S.top] != ' '){
        		PopStack(S, ch);
        		++ct;
        	}
        	else break;
        }
        return ct;
    }
};
