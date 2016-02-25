class Solution {
public:
    string multiply(string num1, string num2) {
        return multiplyNumbers(num1, num2);
    }
private:
	void preprocessing(string& str) {
		while (str.begin() != str.end() && *str.begin() == '0') {
			str.erase(str.begin());
		}
		if (str.empty()) {
			str.push_back('0');
		}
	}
	string multiplyNumbers(string num1, string num2) {
		if (num1.length() == 1) {
			return mulitplySingleNumber(num2, num1);
		}
		if (num2.length() == 1) {
			return mulitplySingleNumber(num1, num2);
		}
		int halfLen = min(num1.length() / 2, num2.length() / 2);
		string front1(num1, 0, num1.length() - halfLen), rear1(num1, num1.length() - halfLen, halfLen);
		string front2(num2, 0, num2.length() - halfLen), rear2(num2, num2.length() - halfLen, halfLen);
		preprocessing(front1); preprocessing(front2); preprocessing(rear1); preprocessing(rear2);
		string AC = multiplyNumbers(front1, front2);
		string BD = multiplyNumbers(rear1, rear2);
		bool isPositive1, isPositive2;
		isPositive1 = isPositive2 = true;
		string AmB = minus(front1, rear1, isPositive1), CmD = minus(front2, rear2, isPositive2);
		string AmBmCmD = multiplyNumbers(AmB, CmD);
		string answer = addAll(AC, BD, AmBmCmD, halfLen, isPositive1 && isPositive2 || !isPositive1 && !isPositive2);
		return answer;
	}
	string mulitplySingleNumber(string number, string single) {
		int t = charToInt(single[0]);
		if (t == 0) {
			return string ("0");
		}
		int need = 0;
		string answer;
		for (int i = number.length() - 1; i >= 0; --i) {
			int cur = charToInt(number[i]);
			int tp = cur * t + need;
			answer.push_back(intToChar(tp % 10));
			need = tp / 10;
		}
		if (need) {
			answer.push_back(intToChar(need));
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
	string minus(string num1, string num2, bool& isPositive) {
		if (num1.length() > num2.length()) {
			isPositive = true;
		} else if (num1.length() < num2.length()) {
			isPositive = false;
		} else {
			for (int i = 0; i != num1.length(); ++i) {
				int n1 = charToInt(num1[i]), n2 = charToInt(num2[i]);
				if (n1 > n2) {
					isPositive = true;
					break;
				} else if (n1 < n2) {
					isPositive = false;
					break;
				} else {
					continue;
				}
			}
		}

		if (!isPositive) {
			string tp(num2);
			num2 = num1;
			num1 = tp;
		}

		bool need = false;
		string answer;
		int i, j;
		for (i = num1.length() - 1, j = num2.length() - 1; i >= 0; --i, --j) {
			int n1 = charToInt(num1[i]), n2 = j >= 0 ? charToInt(num2[j]) : 0;
			if (need) {
				n1 -= 1;
				need = false;
			}
			if (n1 >= n2) {
				answer.push_back(intToChar(n1 - n2));
			} else {
				need = true;
				answer.push_back(intToChar(n1 + 10 - n2));
			}
		}

		for (int i = answer.length() - 1; i >= 0; --i) {
			if (answer[i] == '0') {
				answer.erase(answer.end() - 1);
			} else {
				break;
			}
		}

		if (answer.empty()) {
			answer.push_back('0');
		}

		reverse(answer.begin(), answer.end());
		return answer;
	}
	string addAll(string AC, string BD, string AmBmCmD, int len, bool isPositive) {
		string mid = add(AC, BD);
		if (isPositive) {
			mid = minus(mid, AmBmCmD, isPositive);
		} else {
			mid = add(mid, AmBmCmD);
		}

		for (int i = 0; i != len; ++i) {
			AC += "00";
			mid.push_back('0');
		}

		string answer;
		answer = add(AC, mid);
		answer = add(answer, BD);
		return answer;
	}
	string add(string num1, string num2) {
		string answer;
		bool need = false;
		for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0; --i, --j) {
			int n1 = i >= 0 ? charToInt(num1[i]) : 0, n2 = j >= 0 ? charToInt(num2[j]) : 0;
			int r = 0;
			if (need) {
				r += 1;
				need = false;
			}
			r += n1 + n2;
			if (r >= 10) {
				need = true;
				answer.push_back(intToChar(r - 10));
			} else {
				need = false;
				answer.push_back(intToChar(r));
			}
		}
		if (need) {
			answer.push_back('1');
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
	int charToInt(char ch) {
		return static_cast<int> (ch - '0');
	}
	char intToChar(int ix) {
		return static_cast<char> ('0' + ix);
	}
};
//(A * 10^k + B)(C * 10^k + D) = AC * 10 ^2k + (AD + BC) * 10^k + BD = AC * 10 ^2k + (AC + BD - (A-B)(C-D)) * 10^k + BD
