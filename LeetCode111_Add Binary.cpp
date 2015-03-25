class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size(), lenb = b.size(), i, j;
        string answer;
        bool upgrade = false;
        for (i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; --i, --j){
        	if (a[i] != '0' && b[j] != '0' && upgrade) {
        		answer.insert(answer.begin(), '1');
        		upgrade = true;
        	}
        	else if ((a[i] != '0' && b[j] != '1' || a[i] != '1' && b[j] != '0') && upgrade 
        			|| a[i] != '0' && b[j] != '0' && !upgrade) {
        		answer.insert(answer.begin(), '0');
        		upgrade = true;
        	}
        	else if (a[i] != '1' && b[j] != '1' && upgrade ||
        			(a[i] == '1' || b[j] == '1') && !upgrade) {
        		answer.insert(answer.begin(), '1');
        		upgrade = false;
        	}
        	else
        		answer.insert(answer.begin(), '0');
        }
        for (; i >= 0; --i) {
        	if (!upgrade) {
				answer.insert(answer.begin(), a[i]);
        	}
        	else {
        		if (a[i] == '0') {
        			answer.insert(answer.begin(), '1');
        			upgrade = false;
        		}
        		else
        			answer.insert(answer.begin(), '0');
        	}
        }
        for (; j >= 0; --j) {
        	if (!upgrade)
        		answer.insert(answer.begin(), b[j]);
        	else {
        		if (b[j] == '0') {
        			answer.insert(answer.begin(), '1');
        			upgrade = false;
        		}
        		else
        			answer.insert(answer.begin(),'0');
        	}
        }
        if (upgrade)
        	answer.insert(answer.begin(), '1');
        return answer;
    }
};