class Solution {
public:
    string numberToWords(int num) {
        string answer;
        int count = 0;
        if (num == 0) {
        	answer = "Zero";
        }
    	while (num) {
    		string part = addEnglishNumber(num % 1000);
    		if (part != "") {
    			answer = unit[count] + " " + answer;
    		}
    		answer = part + " " + answer;
    		num /= 1000;
    		++count;
    	}
    	string after;
    	bool isSpace = false;
    	for (char ch : answer) {
    		if (ch != ' ') {
    			after.push_back(ch);
    			isSpace = false;
    		} else {
    			if (!isSpace) {
    				after.push_back(' ');
    				isSpace = true;
    			}
    		}
    	}
    	if (after.back() == ' ') {
    		after.erase(after.end() - 1);
    	}
    	if (after.front() == ' ') {
    		after.erase(after.begin());
    	}
    	return after;
    }

private:
	vector<string> nums = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	vector<string> nums_teen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	vector<string> nums_ty = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	string hundred = "Hundred";
	vector<string> unit = {"", "Thousand", "Million", "Billion"};

	string addEnglishNumber(int num) {
		string answer;
		if (num) {
			int t = num % 100;
			if (t >= 10 && t < 20) {
				answer = nums_teen[t % 10];
			} else {
				int p = t % 10, q = t / 10;
				answer = (q != 0 ? nums_ty[q - 2] : "") + " " + (p != 0 ? nums[p - 1] : "");
			}
			int o = num / 100;
			if (o != 0) {
				answer = nums[o - 1] + " " + hundred + " " + answer;
			}
		}
		return answer;
	}
};