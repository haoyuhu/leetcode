class Solution {
public:
	#define MAX_INT 2147483647
	#define MIN_INT -2147483648
    int atoi(const char *str) {
        int len = length(str);
        if (!len)
        	return 0;
        int start = 0, minus = 0, plus = 0;
        while (str[start] == ' ')
        	++start;
        while (str[start] == '-' || str[start] == '+') {
        	if (str[start] == '-')
        		++minus;
        	if (str[start] == '+')
        		++plus;
        	++start;
        }
        if (minus + plus > 1)
        	return 0;
        long int answer = 0;
        while (start != len){
        	int num = turn_number(str[start]);
        	if (num == -1)
        		break;
        	if (!minus && (MAX_INT - answer * 10 < num || answer > MAX_INT / 10)) {
        		answer = MAX_INT; break;
        	}
        	if (minus && (-answer * 10 - MIN_INT < num || -answer < MIN_INT / 10)) {
        		answer = MIN_INT; break;
        	}
        	answer = answer * 10 + num;
        	++start;
        }
        if (minus && answer != MIN_INT)
        	answer *= -1;
        return answer;
    }
    int turn_number(char ch) {
    	int num = ch - '0';
    	if (num >= 0 && num <= 9)
    		return num;
    	else
    		return -1;
    }
    int length(const char *str) {
    	int cnt = 0;
    	if (str)
    		for (; str[cnt] != '\0'; ++cnt);
    	return cnt;
    }
};