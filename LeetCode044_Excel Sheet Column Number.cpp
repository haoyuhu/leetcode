class Solution {
public:
    int titleToNumber(string s) {
        string::iterator siter = s.begin();
        int sum = 0;
        while (siter != s.end()){
        	sum += turn_number(*siter);
        	if (++siter != s.end()){
        		sum *= 26;
        	}
        }
        return sum;
    }
    int turn_number(char ch){
    	return ch - 'A' + 1;
    }
};