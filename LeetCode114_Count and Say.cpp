class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        int cnt = 1, count = 0;
       	char pre = '1';
        for (; cnt != n; ++cnt){
        	string t;
        	for (int i = 0; i != s.size();){
        		if (s[i] == pre) {
        			++count; ++i;
        		}	
        		else {
        			t += turn_str(count);
        			t.push_back(pre);
        			count = 0;
        			pre = s[i];
        		}
        	}
        	t += turn_str(count);
        	t.push_back(pre);
        	count = 0; pre = t[0];
        	s = t;
        }
        return s;
    }
    string turn_str(int count) {
    	string t;
    	while (count){
    		t.insert(t.begin(), '0' + count % 10);
    		count /= 10;
    	}
    	return t;
    }
};