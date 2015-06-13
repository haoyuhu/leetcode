class Solution {
public:
    int calculate(string s) {
        stack<char> operations;
        stack<int> numbers;
        int answer = 0;
        for (int i = 0; i != s.size(); ) {
        	if (s[i] == ' ') {
        		++i;
        		continue;
        	}
        	if (s[i] == '(') {
        		operations.push(s[i]);
        		++i;
        	} else if (s[i] == '+' || s[i] == '-') {
        		if (operations.empty() || operations.top() == '(') {
        			operations.push(s[i]);
        			++i;
        		} else {
        			int y = numbers.top(); numbers.pop();
        			int x = numbers.top(); numbers.pop();
        			char operation = operations.top(); operations.pop();
        			numbers.push(operate(operation, x, y));
        		}
        	} else if (s[i] == ')') {
        		char operation = operations.top(); operations.pop();
        		while (operation != '(') {
        			int y = numbers.top(); numbers.pop();
        			int x = numbers.top(); numbers.pop();
        			numbers.push(operate(operation, x, y));
        			operation = operations.top();
        			operations.pop();
        		}
        		++i;
        	} else {
        		int number = 0;
        		int integer = customAtoi(s[i]);
        		while (integer >= 0 && integer <= 9) {
        			number = number * 10 + integer;
        			integer = customAtoi(s[++i]);
        		}
        		numbers.push(number);
        	}
        }

        if (operations.empty()) {
        	return numbers.top();
        } else {
        	int y = numbers.top(); numbers.pop();
        	int x = numbers.top(); numbers.pop();
        	char operation = operations.top(); operations.pop();
        	return operate(operation, x, y);
        }
    }

    int customAtoi(char ch) {
    	return static_cast<int> (ch - '0');
    }

    int operate(char operation, int x, int y) {
    	if (operation == '+') {
    		return x + y;
    	} else {
    		return x - y;
    	}
    }
};