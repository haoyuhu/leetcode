class Solution {
public:
    int majorityElement(vector<int> &num) {
        vector<int>::const_iterator it = num.begin();
        int max = num.front(), min = num.front();
        while (it != num.end()){
        	if (*it > max){
        		max = *it;
        	}
        	if (*it < min){
        		min = *it;
        	}
        	++it;
        }
        int *cnt = (int*)calloc((max - min + 1)*sizeof(int));
        for (it = num.begin(); it != num.end(); ++it){
        	int t = *it;
        	if (++cnt[t-min] > num.size() / 2){
        		free(cnt);
        		return t;
        	}
        }
    }
};
////////////////////////////////////////////////////////////
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int i, cnt;
        do {
            for (i = 0, cnt = 0; i < num.size(); i += 2){
                if (i + 1 == num.size() || i + 1 < num.size() && num[i] == num[i+1]){
                    num[cnt++] = num[i];
                }
            }
            num.resize(cnt);
        } while (cnt != 1);
        return num.front();
    }
};
////////////////////////////////////////////////////////////
class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
        int bottom = 0, top = 0, cnt = 0;
        for (; top != num.size(); ){
            if (num[top] == num[bottom]){
                ++cnt; ++top;
            }
            else {
                if (cnt > num.size() / 2){
                    return num[bottom];
                }
                cnt = 0; bottom = top;
            }
        }
        if (cnt > num.size() / 2){
            return num[bottom];
        }
    }
};
////////////////////////////////////////////////////////////
