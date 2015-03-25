class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        vector<string> button;
        create_button(button);
        string s;
        build_combination(button, digits, 0, answer, s);
        return answer;
    }
    void build_combination(const vector<string> &button, const string &dgt, 
    					  int index, vector<string> &answer, string t) {
    	if (index == dgt.size()) {
    		answer.push_back(t); return;
    	}
    	int num = turn_digit(dgt[index]);
    	if (!num) {
    		t += button[num];
    		build_combination(button, dgt, index + 1, answer, t);
    	}
    	else if (num >= 2 && num <= 6 || num == 8) {
    		for (int i = 0; i != 3; ++i){
    			string use(t);
    			use.push_back(button[num][i]);
    			build_combination(button, dgt, index + 1, answer, use);
    		}
    	}
    	else if (num == 9 || num == 7) {
    		for (int i = 0; i != 4; ++i){
    			string use(t);
    			use.push_back(button[num][i]);
    			build_combination(button, dgt, index + 1, answer, use);
    		}
    	}
    	else
    		build_combination(button, dgt, index + 1, answer, t);
    }
    void create_button(vector<string> &button) {
    	string t("abcdefghijklmnopqrstuvwxyz");
    	button.push_back(string(" "));
    	button.push_back(string());
    	string::iterator it = t.begin();
    	for (int i = 2; i != 10; ++i){
    		if (i != 9 && i != 7) {
    			button.push_back(string(it, it + 3));
    			it = it + 3;
    		}
    		else {
    			button.push_back(string(it, it + 4));
    			if (i == 7)
    				it = it + 4;
    		}
    	}
    }
    int turn_digit(char ch) {
    	return ch - '0';
    }
};