class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
		char *t = (char *)malloc(len * sizeof(char));;
		int j = 0;
		for (int i = 0; i < len; ++i){
			if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
				t[j++] = tolower(s[i]);
			}
		}
		int top, bottom;
		bottom = 0;
		top = j - 1;
		while (top > bottom){
			if (t[top] != t[bottom]){
				return false;
			}
			else{
				--top;
				++bottom;
			}
		}
		return true;
    }
};