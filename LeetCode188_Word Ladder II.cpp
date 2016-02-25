class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string>> trace;
        unordered_map<string, int> isUsed;
        int level = 0, saveLevel;
        queue<string> strQueue;
        strQueue.push(start);
        string* final = &strQueue.front(), *last;
        bool isFound = false;
        int len = start.length();

        while (!isFound && !strQueue.empty()) {
        	string& current = strQueue.front();
        	
        	for (int i = 0; i != len; ++i) {
        		for (int j = 0; j != LENGTH; ++j) {
        			char ch = getChar(j);
        			if (ch != current[i]) {
        				string copy(current);
        				copy[i] = ch;
        				if (copy == start) {
        					break;
        				}
        				if (copy == end) {
        					saveLevel = level - 1;
        					isFound = true;
        					trace.insert(make_pair(end, vector<string> {current}));
        				}
        				unordered_map<string, int>::iterator it = isUsed.find(copy);
        				if (dict.find(copy) != dict.end() && (it == isUsed.end() || it->second == level)) {
        					if (it == isUsed.end()) {
        						strQueue.push(copy);
        						last = &strQueue.back();
        						isUsed.insert(make_pair(copy, level));
        						trace.insert(make_pair(copy, vector<string> {current}));
        					} else {
        						unordered_map<string, vector<string>>::iterator traceIter = trace.find(copy);
        						traceIter->second.push_back(current);
        					}
        				}
        			}
        		}
        	}
        	if (&current == final) {
        		final = last;
        		++level;
        	}

        	strQueue.pop();
        }

        if (!strQueue.empty()) {
        	string front = strQueue.front(); strQueue.pop();
        	unordered_map<string, vector<string>>::iterator it = trace.find(end);
        	
        	while (isUsed.find(front)->second == saveLevel) {
        		if (isOneLetterDiff(front, end)) {
        			it->second.push_back(front);
        		}
        		if (!strQueue.empty()) {
        			front = strQueue.front(); strQueue.pop();
        		} else {
        			break;
        		}
        	}
        }
        
		if (trace.find(end) == trace.end()) {
			return vector<vector<string>> ();
		}
        return getTraceVector(trace, start, end);
    }
private: 
	int LENGTH = 26;
	char getChar(int index) {
		return static_cast<char> ('a' + index);
	}

	bool isOneLetterDiff(string front, string end) {
		if (front.size() != end.size()) {
			return false;
		}
		int count = 0;
		for (int i = 0; i != front.size() && count < 2; ++i) {
			if (front[i] != end[i]) {
				++count;
			}
		}
		if (count == 1) {
			return true;
		} else {
			return false;
		}
	}

	vector<vector<string>> getTraceVector(unordered_map<string, vector<string>>& trace, string start, string end) {
		if (start == end) {
			vector<vector<string>> answer(1);
			answer[0].push_back(start);
			return answer;
		}
		vector<vector<string>> answer;
		unordered_map<string, vector<string>>::iterator it = trace.find(end);
		for (string item : it->second) {
			vector<vector<string>> back = getTraceVector(trace, start, item);
			for (vector<string>& list : back) {
				list.push_back(end);
				answer.push_back(list);
			}

		}
		return answer;
	}
};