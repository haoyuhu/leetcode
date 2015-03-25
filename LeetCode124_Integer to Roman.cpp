class Solution {
public:
    string intToRoman(int num) {
        string answer;
        int number[4];
        for (int i = 0; i != 4; ++i){
        	number[i] = num % 10;
        	num /= 10;
        }
        for (int i = 3; i >= 0; --i){
        	answer += num_to_roman(number, i);
        }
        return answer;
    }
    string num_to_roman(int number[], int i) {
    	string t;
    	char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int num[7] = {1, 5, 10, 50, 100, 500, 1000};
        if (i == 3) {
        	return string(number[i], roman[6]);
        }
        int k = 2 * i + 1;
        if (!number[i])
        	return t;
        else if (number[i] >= 1 && number[i] <= 3) {
        	t = string(number[i], roman[k-1]);
        }
        else if (number[i] == 4) {
        	t.push_back(roman[k-1]); t.push_back(roman[k]);
        }
        else if (number[i] >= 5 && number[i] <= 8) {
        	t.push_back(roman[k]); t += string(number[i] - 5, roman[k-1]);
        }
        else {
        	t.push_back(roman[k-1]); t.push_back(roman[k+1]);
        }
        return t;
    }
};