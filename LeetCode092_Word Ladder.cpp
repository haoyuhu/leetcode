class Solution {
public:
	#define MAX_INT 999999999
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int size = dict.size(), i, j;
        size += 2;
        bool tag[size][size];
        unordered_set<string>::const_iterator itslow, itfast;
        for (i = 1, itslow = dict.begin(); i != size - 1; ++i, ++itslow){
        	for (j = i, itfast = itslow; j != size - 1; ++j, ++itfast){
        		if (isOneLetterDiff(*itslow, *itfast)) {
        			tag[i][j] = true;
        			tag[j][i] = true;
        		}
        		else {
        			tag[i][j] = false;
        			tag[j][i] = true;
        		}
        	}
        }
        for (i = 1, itslow = dict.begin(); i != size - 1; ++i, ++itslow){
        	if (isOneLetterDiff(start, *itslow))
        		tag[0][i] = tag[i][0] = true;
        	else
        		tag[0][i] = tag[i][0] = false;
        	if (isOneLetterDiff(end, *itslow))
        		tag[size-1][i] = tag[i][size-1] = true;
        	else
        		tag[size-1][i] = tag[i][size-1] = false;
        }
        tag[0][0] = tag[size-1][size-1] = true;
        if (isOneLetterDiff(start, end))
        	return 2;
        else
        	tag[0][size-1] = tag[size-1][0] = false;
        bool isbest[size];
        for (int i = 0; i != size; ++i){
        	isbest[i] = false;
        }
        isbest[0] = true;
        int distance[size];
        for (int i = 0; i != size; ++i){
        	if (tag[0][i])
        		distance[i] = 1;
        	else
        		distance[i] = MAX_INT;
        }
        for (int i = 0; !isbest[size-1]; ++i){
        	int index, min = MAX_INT;
        	for (int k = 0; k != size; ++k){
        		if (!isbest[k] && distance[k] < min) {
        			min = distance[k];
        			index = k;
        		}
        	}
        	if (!index)
        		break;
        	isbest[index] = true;
        	for (int k = 0; k != size; ++k){
        		if (!isbest[k] && tag[index][k] && min + 1 < distance[k])
        			distance[k] = min + 1;
        	}
        }
        if (distance[size-1] != MAX_INT)
        	return distance[size-1] + 1;
        else
        	return 0;
    }
    bool isOneLetterDiff(const string &s, const string &t) {
    	int count = 0, size = s.size();
    	for (int i = 0; i != size; ++i){
    		if (s[i] != t[i]) {
    			if (!count)
    				++count;
    			else
    				return false;
    		}
    	}
    	return true;
    }
};
//TLE :(
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int cnt = 1, answer = 0;
        string tail, final = start;
        queue<string> path;
        path.push(start); dict.insert(end);
        while (!path.empty()) {
            string now = path.front();
            path.pop();
            if (now == end) {
                answer = cnt;
                break;
            }
            for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ) {
                if (isOneLetterDiff(now, *it)) {
                    path.push(*it); tail = *it;
                    it = dict.erase(it);
                }
                else
                    ++it;
            }
            if (now == final) {
                final = tail; ++cnt;
            }
        }
        return answer;
    }
    bool isOneLetterDiff(const string &s, const string &t) {
        int count = 0, size = s.size();
        for (int i = 0; i != size; ++i){
            if (s[i] != t[i]) {
                if (!count)
                    ++count;
                else
                    return false;
            }
        }
        return true;
    }
};//AC! :)