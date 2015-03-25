class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int front1, front2, i, j;
        front1 = front2 = 0;
        for (i = 0, j = 0; i != len1 && j != len2; ){
        	while (i != len1 && version1[i] != '.')
        		++i;
        	while (j != len2 && version2[j] != '.')
        		++j;
        	int num1 = turn_digit(string(version1, front1, i - front1));
        	int num2 = turn_digit(string(version2, front2, j - front2));
        	if (num1 < num2)
        		return -1;
        	else if (num1 > num2)
        		return 1;
        	else {
        		if (i != len1) front1 = ++i;
        		if (j != len2) front2 = ++j;
        	}
        }
        while (i != len1) {
            while (i != len1 && version1[i] != '.')
                ++i;
            if (turn_digit(string(version1, front1, i - front1)))
                return 1;
            if (i != len1) front1 = ++i;
        }
        while (j != len2) {
            while (j != len2 && version2[j] != '.')
                ++j;
            if (turn_digit(string(version2, front2, j - front2)))
                return -1;
            if (j != len2) front2 = ++j;
        }
        return 0;
    }
    int turn_digit(string s) {
    	int num = 0;
    	for (int i = 0; i != s.size(); ++i){
    		num = num * 10 + (s[i] - '0');
    	}
    	return num;
    }
};