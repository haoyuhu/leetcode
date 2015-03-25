class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_num;
        char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int num[7] = {1, 5, 10, 50, 100, 500, 1000};
        int sum = 0;
        for (int i = 0; i != 7; ++i){
        	roman_num.insert(pair<char, int>(roman[i], num[i]));
        }
        for (int i = s.size() - 1; i >= 0; ){
        	int j = s.size();
        	if (i - 1 >= 0)
        		j = i - 1;
        	if (j != s.size()) {
        		if (roman_num[s[i]] <= roman_num[s[j]]) {
        			sum += roman_num[s[i]]; --i;
        		}
        		else {
        			sum += roman_num[s[i]] - roman_num[s[j]];
        			i = --j;
        		}
        	}
        	else {
        		sum += roman_num[s[i]];
        		--i;
        	}
        }
        return sum;
    }
};
//
class Solution {
public:
    int romanToInt(string s) {
        char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int num[7] = {1, 5, 10, 50, 100, 500, 1000};
        int sum = 0, k;
        for (int i = s.size() - 1; i >= 0; ){
        	int j = s.size();
        	if (i - 1 >= 0)
        		j = i - 1;
        	if (j != s.size()) {
        		if (roman_to_num(roman, num, s[i]) <= roman_to_num(roman, num, s[j])) {
        			sum += s[i]; --i;
        		}
        		else {
        			sum += roman_to_num(roman, num, s[i]) - roman_to_num(roman, num, s[j]);
        			i = --j;
        		}
        	}
        	else {
        		sum += roman_to_num(roman, num, s[i]);
        	}
        }
        return sum;
    }
    int roman_to_num(char roman[], int num[], char ch) {
    	int k;
    	for (k = 0; k != 7 && roman[k] != ch; ++k);
        return num[k];
    }
};