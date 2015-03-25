class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> str_cnt;
        unordered_multimap<char, int> save_index;
        map<int, char> seq;
        int beg, end, mingap = S.size();
        string answer;
        if (S.size() < T.size())
        	return answer;
        for (int i = 0; i != T.size(); ++i){
        	unordered_map<char, int>::iterator it = str_cnt.find(T[i]);
        	if (it == str_cnt.end())
        		str_cnt.insert(pair<char, int>(T[i], 1));
        	else
        		it->second += 1;
        }
        for (int i = 0; i != S.size(); ++i){
        	unordered_map<char, int>::iterator it_str = str_cnt.find(S[i]);
        	if (it_str != str_cnt.end()) {
        		if (it_str->second) {
        			seq.insert(pair<int, char>(i, S[i]));
        			save_index.insert(pair<char, int>(S[i], i));
        			it_str->second -= 1;
        		}
        		else {
        			unordered_map<char, int>::iterator it = save_index.begin(), save;
        			int index = S.size();
        			for (; it != save_index.end(); ++it){
        				if (it->first == S[i] && index > it->second)
        					save = it; index = it->second;
        			}
        			seq.erase(index);
        			save_index.erase(save);
        			seq.insert(pair<int, char>(i, S[i]));
        			save_index.insert(pair<char, int>(S[i], i));
        		}
        		if (seq.size() == T.size()) {
        			int start = seq.begin()->first;
        			int stop = seq.rbegin()->first;
        			if (mingap > stop - start) {
        				mingap = stop - start;
        				beg = start;
        				end = stop;
        			}
        		}
        	}
        }
        if (mingap != S.size())
        	answer = string(S, beg, end - beg + 1);
        return answer;
    }
};
//
class Solution {
public:
    string minWindow(string S, string T) {
        typedef unordered_map<char, int>::iterator str_cnt_iter;
        typedef map<int, char>::iterator index_str_iter;
        int beg, end, mingap = S.size();
        map<int, char> index_str;
        unordered_map<char, int> str_cnt;
        string answer;
        for (int i = 0; i != T.size(); ++i){
            str_cnt_iter it = str_cnt.find(T[i]);
            if (it != str_cnt.end())
                it->second += 1;
            else
                str_cnt.insert(pair<char, int>(T[i], 1));
        }
        for (int i = 0; i != S.size(); ++i){
            str_cnt_iter str_it = str_cnt.find(S[i]);
            if (str_it != str_cnt.end()) {
                if (str_it->second) {
                    index_str.insert(pair<int, char>(i, S[i]));
                    str_it->second -= 1;
                }
                else {
                    index_str_iter now;
                    for (now = index_str.begin(); now != index_str.end() 
                        && now->second != S[i]; ++now);
                    index_str.erase(now);
                    index_str.insert(pair<int, char>(i, S[i]));
                }
                if (index_str.size() == T.size()) {
                    int start = index_str.begin()->first;
                    int stop = index_str.rbegin()->first;
                    if (stop - start < mingap) {
                        mingap = stop - start;
                        beg = start;
                        end = stop;
                    }
                }
            }
        }
        if (mingap != S.size())
            answer = string(S, beg, end - beg + 1);
        return answer;
    }
};
//
class Solution {
public:
    string minWindow(string S, string T) {
        typedef unordered_map<char, int>::iterator str_cnt_iter;
        typedef map<int, char>::iterator index_str_iter;
        typedef unordered_map<char, queue<int> >::iterator str_index_iter;
        int beg, end, mingap = S.size();
        map<int, char> index_str;
        unordered_map<char, int> str_cnt;
        unordered_map<char, queue<int> > str_index;
        string answer;
        for (int i = 0; i != T.size(); ++i){
            str_cnt_iter it = str_cnt.find(T[i]);
            if (it != str_cnt.end())
                it->second += 1;
            else
                str_cnt.insert(pair<char, int>(T[i], 1));
        }
        for (int i = 0; i != S.size(); ++i){
            str_cnt_iter str_it = str_cnt.find(S[i]);
            if (str_it != str_cnt.end()) {
                if (str_it->second) {
                    index_str.insert(pair<int, char>(i, S[i]));
                    str_index_iter it = str_index.find(S[i]);
                    if (it == str_index.end()) {
                        str_index.insert(pair<char, queue<int> >(S[i], queue<int>()));
                        it = str_index.find(S[i]);
                    }
                    it->second.push(i);   
                    str_it->second -= 1;
                }
                else {
                    index_str_iter now;
                    str_index_iter fd = str_index.find(S[i]);
                    int k = fd->second.front();
                    index_str.erase(k);
                    fd->second.pop();
                    fd->second.push(i);
                    index_str.insert(pair<int, char>(i, S[i]));
                }
                if (index_str.size() == T.size()) {
                    int start = index_str.begin()->first;
                    int stop = index_str.rbegin()->first;
                    if (stop - start < mingap) {
                        mingap = stop - start;
                        beg = start;
                        end = stop;
                    }
                }
            }
        }
        if (mingap != S.size())
            answer = string(S, beg, end - beg + 1);
        return answer;
    }
};//AC