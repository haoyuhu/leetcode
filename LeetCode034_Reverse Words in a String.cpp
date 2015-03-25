class Solution {
public:
    typedef struct SLNode{
    	char ch;
    	struct SLNode *next;
    }SLNode, *LinkedStack;
    bool EmptyStack(LinkedStack S){
    	if (!S) return true;
    	else return false;
    }
    void PushStack(LinkedStack &S, char ch){
    	LinkedStack p = (LinkedStack)malloc(sizeof(SLNode));
    	p->ch = ch; p->next = NULL;
    	if (EmptyStack(S)) S = p;
    	else {
    		p->next = S; S = p;
    	}
    }
    void PopStack(LinkedStack &S, char &ch){
    	if (!EmptyStack(S)){
    		LinkedStack q = S->next;
    		ch = S->ch; free(S);
    		if (q) S = q;
    		else S = NULL;
    	}
    }
    void reverseWords(string &s) {
        LinkedStack S = NULL, T = NULL;
        char ch;
        int i, ct = 0;
        for (i = 0; s[i] == ' '; ++i) --s.length();
        for (; i < s.length(); ++i){
        	PushStack(S, s[i]);
        }
        while (!EmptyStack(S)){
        	PopStack(S, ch);
        	if (ch == ' '){
        		s[ct++] = ch;
        	}
        	else {
        		PushStack(T, ch);
        		while (S && S->ch != ' '){
        			PopStack(S, ch); PushStack(T, ch);
        		}
        		while (!EmptyStack(T)){
        			PopStack(T, ch); s[ct++] = ch;
        		}
        	}
        }
    }
};
///////////////////////////////////////////////////////////
class Solution {
public:
    void reverseWords(string &s) {
        stack<char> rlstk, rwstk;
        string::const_iterator itstart = s.begin();
        while (itstart != s.end() && *itstart == ' '){
            ++itstart;
        }
        while (itstart != s.end()){
            while (itstart != s.end() && *itstart != ' '){
                rwstk.push(*itstart); ++itstart;
            }
            while (!rwstk.empty()){
                rlstk.push(rwstk.top()); rwstk.pop();
            }
            if (itstart != s.end()){
                rlstk.push(*itstart); ++itstart;
            }
            while (itstart != s.end() && *itstart == ' '){
                ++itstart;
            }
        }
        s.clear();
        while (!rlstk.empty() && rlstk.top() == ' '){
            rlstk.pop();
        }
        while (!rlstk.empty()){
            s.insert(s.end(), rlstk.top()); rlstk.pop();
        }
    }
};
////////////////////////////////////////////////////////////////
class Solution {
public:
    void reverseWords(string &s) {
        stack<string> sstk;
        istringstream istrm(s);
        string word;
        while (istrm >> word){
            sstk.push(word);
        }
        s.clear();
        while (!sstk.empty()){
            s += sstk.top(); sstk.pop();
            s += " ";
        }
        if (s.size()){
            s.erase(--s.end());
        }
    }
};//good