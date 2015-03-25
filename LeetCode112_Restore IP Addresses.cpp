#define third  4
#define second 2
#define first  1
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> answer;
        if (!len)
        	return answer;
        int path[len];
        bool tag[len];
        tag[0] = true; path[0] = first;
        for (int i = 1; i != len; ++i){
        	path[i] = 0; tag[i] = false;
        	if (tag[i-1] && isIpAddr(string(s, i, 1))) {
        		tag[i] = true; path[i] += first;
        	}
        	if ((i - 2 == -1 || i - 2 >= 0 && tag[i-2]) && isIpAddr(string(s, i - 1, 2))) {
        		tag[i] = true; path[i] += second;
        	}
        	if ((i - 3 == -1 || i - 3 >= 0 && tag[i-3]) && isIpAddr(string(s, i - 2, 3))) {
        		tag[i] = true; path[i] += third;
        	}
        }
        if (tag[len-1])
        	create_answer(answer, s, path, len - 1, 0);
        return answer;
    }
    void create_answer(vector<string> &answer, string now, int path[], int index, int count) {
    	if (index == -1 && count == 4) {
    		answer.push_back(now); return;
    	}
    	// if (count > 3)
    	if (1 + index > (4 - count) * 3)
    		return;
    	if (path[index] & 1) {
    		string t(now);
    		if (index != 0)
    			t.insert(index, 1, '.');
    		create_answer(answer, t, path, index - 1, count + 1);
    	}
    	else
    		return;
    	if (path[index] >> 1 & 1) {
    		string t(now);
    		if (index != 1)
    			t.insert(index - 1, 1, '.');
    		create_answer(answer, t, path, index - 2, count + 1);
    	}
    	if (path[index] >> 2 & 1) {
    		string t(now);
    		if (index != 2)
    			t.insert(index - 2, 1, '.');
    		create_answer(answer, t, path, index - 3, count + 1);
    	}
    }
    bool isIpAddr(string t) {
    	int size = t.size();
    	if (size == 1)
    		return true;
    	if (size == 2 && t[0] != '0')
    		return true;
    	if (size == 3 && t[0] != '0') {
    		int num = turn_digit(t);
    		if (num <= 255)
    			return true;
    	}
    	return false;
    }
    int turn_digit(string t) {
    	return (t[0] - '0') * 100 + (t[1] - '0') * 10 + (t[2] - '0');
    }
};

//
#define fourth 8
#define third  4
#define second 2
#define first  1
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> answer;
        if (!len)
        	return answer;
        int path[len], tag[len];
        tag[0] = first; path[0] = first;
        for (int i = 1; i != len; ++i){
        	path[i] = 0; tag[i] = 0;
        	if (tag[i-1] && isIpAddr(string(s, i, 1)) && tag[i-1] != fourth) {
        		if (tag[i-1] >= fourth)
        			tag[i] |= ((tag[i-1] - fourth) << 1);
        		else
        			tag[i] |= (tag[i-1] << 1);
        		path[i] += first;
        	}
        	if ((i - 2 == -1 || i - 2 >= 0 && tag[i-2]) 
        		&& isIpAddr(string(s, i - 1, 2)) 
        		&& (i - 2 == -1 || tag[i-2] != fourth)) {
        		if (i - 2 == -1)
        			tag[i] = first;
        		else {
        			if (tag[i-2] >= fourth)
        				tag[i] |= ((tag[i-2] - fourth) << 1);
        			else
        				tag[i] |= (tag[i-2] << 1);
        		}
        		path[i] += second;
        	}
        	if ((i - 3 == -1 || i - 3 >= 0 && tag[i-3]) 
        		&& isIpAddr(string(s, i - 2, 3))
        		&& (i - 3 == -1 || tag[i-3] != fourth)) {
        		if (i - 3 == -1)
        			tag[i] = first;
        		else {
        			if (tag[i-3] >= fourth)
        				tag[i] |= ((tag[i-3] - fourth) << 1);
        			else
        				tag[i] |= (tag[i-3] << 1);
        		}
        		path[i] += third;
        	}
        }
        if (tag[len-1])
        	create_answer(answer, s, path, len - 1);
        return answer;
    }
    void create_answer(vector<string> &answer, string now, int path[], int index) {
    	if (index == -1) {
    		answer.push_back(now); return;
    	}
    	if (path[index] & 1) {
    		string t(now);
    		if (index != 0)
    			t.insert(index, 1, '.');
    		create_answer(answer, t, path, index - 1);
    	}
    	else
    		return;
    	if (path[index] >> 1 & 1) {
    		string t(now);
    		if (index != 1)
    			t.insert(index - 1, 1, '.');
    		create_answer(answer, t, path, index - 2);
    	}
    	if (path[index] >> 2 & 1) {
    		string t(now);
    		if (index != 2)
    			t.insert(index - 2, 1, '.');
    		create_answer(answer, t, path, index - 3);
    	}
    }
    bool isIpAddr(string t) {
    	int size = t.size();
    	if (size == 1)
    		return true;
    	if (size == 2 && t[0] != '0')
    		return true;
    	if (size == 3 && t[0] != '0') {
    		int num = turn_digit(t);
    		if (num <= 255)
    			return true;
    	}
    	return false;
    }
    int turn_digit(string t) {
    	return (t[0] - '0') * 100 + (t[1] - '0') * 10 + (t[2] - '0');
    }
};
//
#define third  4
#define second 2
#define first  1
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> answer;
        if (!len)
        	return answer;
        int tag[5][len+1];
        vector< vector<int> > path(4, vector<int>(len, 0));
        for (int i = 0; i != 5; ++i)
        	tag[i][0] = false;
        for (int j = 0; j <= len; ++j)
        	tag[0][j] = false;
        tag[0][0] = true;
        for (int i = 1; i != 5; ++i){
        	for (int j = 1; j <= len; ++j){
        		tag[i][j] = false;
        		if (tag[i-1][j-1] && isIpAddr(string(s, j - 1, 1))) {
        			tag[i][j] = true; path[i-1][j-1] += first;
        		}
        		if (j - 2 >= 0 && tag[i-1][j-2] && isIpAddr(string(s, j - 2, 2))) {
        			tag[i][j] = true; path[i-1][j-1] += second;
        		}
        		if (j - 3 >= 0 && tag[i-1][j-3] && isIpAddr(string(s, j - 3, 3))) {
        			tag[i][j] = true; path[i-1][j-1] += third;
        		}
        	}
        }
        if (tag[4][len])
        	create_answer(answer, s, path, 3, len - 1);
        return answer;
    }
    void create_answer(vector<string> &answer, string now, vector< vector<int> > &path, int i, int j) {
    	if (i == -1) {
    		answer.push_back(now); return;
    	}
    	if (path[i][j] & 1) {
    		string t(now);
    		if (i != 0)
    			t.insert(j, 1, '.');
    		create_answer(answer, t, path, i - 1, j - 1);
    	}
    	if (path[i][j] >> 1 & 1) {
    		string t(now);
    		if (i != 0)
    			t.insert(j - 1, 1, '.');
    		create_answer(answer, t, path, i - 1, j - 2);
    	}
    	if (path[i][j] >> 2 & 1) {
    		string t(now);
    		if (i != 0)
    			t.insert(j - 2, 1, '.');
    		create_answer(answer, t, path, i - 1, j - 3);
    	}
    }
    bool isIpAddr(string t) {
    	int size = t.size();
    	if (size == 1)
    		return true;
    	if (size == 2 && t[0] != '0')
    		return true;
    	if (size == 3 && t[0] != '0') {
    		int num = turn_digit(t);
    		if (num <= 255)
    			return true;
    	}
    	return false;
    }
    int turn_digit(string t) {
    	return (t[0] - '0') * 100 + (t[1] - '0') * 10 + (t[2] - '0');
    }
};
//best algorithm!