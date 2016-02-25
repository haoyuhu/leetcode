class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i != pattern.size(); ++i) {
        	char ch = pattern[i];
        	unordered_map<int, vector<int>>::iterator it = map.find(ch);
        	if (it != map.end()) {
        		vector<int> &list = it->second;
        		list.push_back(i);
        	} else {
        		vector<int> list(1, i);
        		map.insert(make_pair(ch, list));
        	}
        }
        vector<string> wordList = split(str, ' ');
        if (wordList.size() != pattern.size()) {
        	return false;
        }
        vector<string> checkList;
        unordered_map<int, vector<int>>::iterator it = map.begin();
        for (; it != map.end(); ++it) {
        	vector<int> list = it->second;
        	string first = wordList[list[0]];
        	checkList.push_back(first);
        	for (int i = 1; i < list.size(); ++i) {
        		int index = list[i];
        		if (wordList[index] != first) {
        			return false;
        		}
        	}
        }
        if (!checkList.empty()) {
        	string first = checkList[0];
        	for (int i = 1; i < checkList.size(); ++i) {
        		if (first == checkList[i]) {
        			return false;
        		}
        	}
        }
        return true;
    }

private:

	vector<string> split(string str, char ch) {
		vector<string> answer;
		int begin = 0;
		for (int i = 0; i != str.size(); ++i) {
			if (ch == str[i]) {
				string t = str.substr(begin, i - begin);
				answer.push_back(t);
				begin = i + 1;
			}
		}
		if (answer.empty()) {
			answer.push_back(str);
		} else {
			answer.push_back(str.substr(begin, str.size() - begin));
		}
		return answer;
	}

};