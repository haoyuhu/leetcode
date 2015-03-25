class Solution {
public:
    string convertToTitle(int n) {
        string s;
        if (n <= 0) return s;
        do {
        	int t = n % 26;
        	s.insert(s.begin(), transform(t));
        	if (t == 0) n = n / 26 - 1;
        	else n /= 26;
        } while (n);
        return s;
    }
    char transform(int t){
    	return !t ? 'Z' : 'A' + t - 1;
    }
};