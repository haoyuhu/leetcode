class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	    queue<string> strque;
	    vector<string> last;
	    unordered_map<string, vector<string> > path;
	    unordered_set<string> del;
	    strque.push(start);
	    string tail, final = start;
	    int count = 2;
	    while (!strque.empty()) {
	    	string t = strque.front(); strque.pop();
	    	unordered_set<string>::iterator it;
	    	if (isOneLetterDiffer(t, end)) {
	    		last.push_back(t);
	    		while (t != final) {
	    			t = strque.front(); strque.pop();
	    			if (isOneLetterDiffer(t, end))
	    				last.push_back(t);
	    		}
	    		break;
	    	}
	    	unordered_set<string>::iterator it_del;
	    	for (int i = 0; i != start.size(); ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (ch == t[i])
						continue;
					string str(t);
					str[i] = ch;
					it = dict.find(str); it_del = del.find(str);
					if (it != dict.end()) {
						unordered_map<string, vector<string> >::iterator it_path= path.find(str);
	                    if (it_path == path.end())
	                        path.insert(make_pair(str, vector<string>{t}));
	                    else
	                        it_path->second.push_back(t);
	                    tail = str;
						if (it_del == del.end())
							del.insert(str);
						strque.push(str);
					}
				}
	    	}
	    	if (t == final) {
	    		final = tail; ++count;
	    		for (it_del = del.begin(); it != del.end(); ) {
	    			dict.erase(dict.find(*it_del));
	    			it_del = del.erase(it_del);
	    		}
	    	}
	    }
	    if (!last.size())
	    	return vector< vector<string> >();
	    else {
	    	vector< vector<string> > answer;
	        for (int i = 0; i != last.size(); ++i)
	    	   create_answer(answer, path, start, end, last[i], vector<string>());
	    	return answer;
	    }
	}
	void create_answer(vector< vector<string> > &answer, unordered_map<string, vector<string> > &path,
	    string &start, string &end, string begin, vector<string> tvec) {
	    if (begin == start) {
	        tvec.insert(tvec.begin(), start); tvec.push_back(end);
	        answer.push_back(tvec);
	        return;
	    }
	    for (int i = 0; i != path[begin].size(); ++i) {
	        string t = path[begin][i];
	        vector<string> cur(tvec);
	        cur.insert(cur.begin(), begin);
	        create_answer(answer, path, start, end, t, cur);
	    }
	}
	bool isOneLetterDiffer(const string &s, const string &t) {
	    int i, count = 0;
	    for (int i = 0; i != s.size(); ++i) {
	        if (s[i] != t[i] && ++count > 1)
	            return false;
	    }
	    return !count ? false : true;
	}
};
//
class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	    typedef unordered_set<string>::iterator unorderSetIterator;
	    unordered_set<string> check;
	    unordered_map<string, vector<string> > save;
	    queue<string> level;
	    vector< vector<string> > answer;
	    string final = start, last, str;
	    level.push(start);
	    unorderSetIterator dict_it = dict.find(end), check_it;
	    if (dict_it == dict.end())
	    	dict.insert(end);
	    dict_it = dict.find(start);
	    if (dict_it != dict.end())
	        dict.erase(dict_it);
	    while (!level.empty()) {
	    	str = level.front(); level.pop();
	    	if (str == end) break;
	    	for (int i = 0; i != str.size(); ++i) {
	    		for (char ch = 'a'; ch <= 'z'; ++ch) {
	    			string t(str);
	    			if (t[i] != ch) t[i] = ch;
	    			else continue;
	    			check_it = check.find(t);
	    			unordered_map<string, vector<string> >::iterator save_it;
	    			if (check_it != check.end()) {
	    				level.push(t);
	    				save_it = save.find(t);
	    				if (save_it == save.end())
	    					save.insert(make_pair(t, vector<string>(1, str)));
	    				else
	    					save_it->second.push_back(str);
	    				last = t;
	    			}
	    			else {
	    				dict_it = dict.find(t);
	    				if (dict_it != dict.end()) {
	    					level.push(t);
	    					if (save_it == save.end())
	    						save.insert(make_pair(t, vector<string>(1, str)));
	    					else
	    						save_it->second.push_back(str);
	    					last = t;
	    					dict.erase(dict_it); check.insert(t);
	    				}
	    			}
	    		}
	    	}
	    	if (str == final) {
	    		final = last;
	    		check.clear();
	    	}
	    }
	    if (save.size()) {
	    	create_answer(save, start, end, vector<string>(), answer);
	    }
	    return answer;
	}
	void create_answer(unordered_map<string, vector<string> > &save, string start, string end, vector<string> path, vector< vector<string> > &answer) {
		if (end == start) {
			answer.push_back(path); return;
		}
		unordered_map<string, vector<string> >::iterator it = save.find(end);
		vector<string> &cur = it->second;
		path.insert(path.begin(), end);
		for (vector<string>::iterator vecit = cur.begin(); vecit != cur.end(); ++vecit) {
			create_answer(save, start, *vecit, path, answer);
		}
	}
};