class Solution {
public:
    int numDecodings(string s) {
		int len = s.length();
		char *ch = (char *)malloc((len + 1) * sizeof(char));
		for (int i = 0; i < len; ++i){
			ch[i] = s[i];
		}
		ch[i] = '\0';
        return FindNumCoding(ch, 0, len);
    }
	int FindNumCoding(char *s, int i, int len){
		if (i >= len){
			return 0;
		}
		if (i == len - 1){
			return 1;
		}
		else{
			char ch1[2] = {s[i], '\0'};
			char ch2[3] = {s[i], s[i+1], '\0'};
			int tmp1 = atoi(ch1);
			int tmp2 = atoi(ch2);
			if (tmp1 >= 1 && tmp2 >= 1 && tmp1 <= 26 && tmp2 <= 26){
				return FindNumCoding(s, i+1, len) + FindNumCoding(s, i+2, len);
			}
			else if (tmp1 >= 1 && tmp1 <= 26){
				return FindNumCoding(s, i+1, len);
			}
			else if (tmp2 >= 1 && tmp2 <= 26){
				return FindNumCoding(s, i+2, len);
			}
			else{
				return 0;
			}
		}
	}
};
//
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (!len)
        	return 0;
        int num[len];
        if (s[0] == '0')
        	return 0;
        else
        	num[0] = 1;
        for (int i = 1; i < len; ++i){
        	num[i] = 0;
        	if (isdecode(s, i))
        		num[i] = num[i-1];
        	if (isdecode(s, i-1, i)){
        		if (i - 2 >= 0)
        			num[i] += num[i-2];
        		else
        			num[i] += 1;
        	}
        }
        return num[len-1];
    }
    bool isdecode(string s, int i){
    	return s[i] == '0' ? false : true;
    }
    bool isdecode(string s, int i, int j){
    	if (s[i] == '1')
    		return true;
    	else if (s[i] == '2' && isZerotoSix(s[j]))
    		return true;
    	else
    		return false;
    }
    bool isZerotoSix(char ch){
    	string s("0123456");
    	string::iterator it = s.begin();
    	for (; it != s.end() && *it != ch; ++it);
    	if (it != s.end())
    		return true;
    	else
    		return false;
    }
};