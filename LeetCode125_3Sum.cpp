class Solution {
public:
	#define MAX_INT 999999999
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > answer;
        if (num.size() < 3)
        	return answer;
        sort(num.begin(), num.end());
        int left, right, now, near_zero = find_zero(num), pre_val = MAX_INT;
        for (now = 1; now != num.size() - 1; ++now){
        	if (pre_val != MAX_INT && pre_val == num[now])
        		continue;
        	if (num[now] < 0) {
        		right = max(near_zero + 1, now + 1);
        		left = now - 1;
        	}
        	else {
        		left = min(near_zero, now - 1);
        		right = now + 1;
        	}
        	int left_pre, right_pre;
        	left_pre = right_pre = MAX_INT;
        	for (; left >= 0 && right < num.size(); ){
        		int sum = num[left] + num[now] + num[right];
        		if (sum < 0)
        			++right;
        		else if (sum > 0)
        			--left;
        		else {
        			// vector<int> t;
        			// t.push_back(num[left]); t.push_back(num[now]); t.push_back(num[right]);
        			// answer.push_back(t);
        			if (left_pre != MAX_INT && left_pre == num[left]) {
        				++right; --left; continue;
        			}
        			left_pre = num[left]; right_pre = num[right];
        			int ans[3] = {num[left], num[now], num[right]};
        			answer.push_back(vector<int>(ans, ans + 3));
        			++right; --left;
        			pre_val = num[now];
        		}
        	}
        }
/*        sort(answer.begin(), answer.end());
        vector< vector<int> >::iterator it = unique(answer.begin(), answer.end());
        answer.erase(it, answer.end());*/
        return answer;
    }
    int find_zero(vector<int> &num) {
    	int bottom = 0, top = num.size() - 1;
    	while (bottom <= top) {
    		int mid = (bottom + top) / 2;
    		if (num[mid] > 0)
    			top = mid - 1;
    		else if (num[mid] < 0)
    			bottom = mid + 1;
    		else
    			return mid;
    	}
    	return top;
    }
};

//
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > answer;
        if (num.size() < 3)
        	return answer;
        sort(num.begin(), num.end());
        int left, right, now, near_zero = find_zero(num);
        for (now = 1; now != num.size() - 1; ++now){
        	if (num[now] < 0) {
        		right = max(near_zero + 1, now + 1);
        		left = now - 1;
        	}
        	else {
        		left = min(near_zero, now - 1);
        		right = now + 1;
        	}
        	for (; left >= 0 && right < num.size(); ){
        		int sum = num[left] + num[now] + num[right];
        		if (sum < 0)
        			++right;
        		else if (sum > 0)
        			--left;
        		else {
        			// vector<int> t;
        			// t.push_back(num[left]); t.push_back(num[now]); t.push_back(num[right]);
        			// answer.push_back(t);
        			int ans[3] = {num[left], num[now], num[right]};
        			answer.push_back(vector<int>(ans, ans + 3));
        			++right; --left;
        		}
        	}
        }
        sort(answer.begin(), answer.end());
        vector< vector<int> >::iterator it = unique(answer.begin(), answer.end());
        answer.erase(it, answer.end());
        return answer;
    }
    int find_zero(vector<int> &num) {
    	int bottom = 0, top = num.size() - 1;
    	while (bottom <= top) {
    		int mid = (bottom + top) / 2;
    		if (num[mid] > 0)
    			top = mid - 1;
    		else if (num[mid] < 0)
    			bottom = mid + 1;
    		else
    			return mid;
    	}
    	return top;
    }
};

///
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > answer;
        if (num.size() < 3)
            return answer;
        unordered_set<int> tag;
        int pre_val = 0;
        sort(num.begin(), num.end());
        int left, right, now, near_zero = find_zero(num);
        for (now = 1; now != num.size() - 1; ++now){
            if (num[now] != pre_val) {
                pre_val = num[now];
                tag.clear();
            }
            if (num[now] < 0) {
                right = max(near_zero + 1, now + 1);
                left = now - 1;
            }
            else {
                left = min(near_zero, now - 1);
                right = now + 1;
            }
            for (; left >= 0 && right < num.size(); ){
                int sum = num[left] + num[now] + num[right];
                if (sum < 0)
                    ++right;
                else if (sum > 0)
                    --left;
                else {
                    // vector<int> t;
                    // t.push_back(num[left]); t.push_back(num[now]); t.push_back(num[right]);
                    // answer.push_back(t);
                    unordered_set<int>::iterator it = tag.find(num[left]);
                    if (it != tag.end()) {
                        ++right; --left;
                        continue;
                    }
                    int ans[3] = {num[left], num[now], num[right]};
                    answer.push_back(vector<int>(ans, ans + 3));
                    tag.insert(num[left]);
                    ++right; --left;
                }
            }
        }
        return answer;
    }
    int find_zero(vector<int> &num) {
        int bottom = 0, top = num.size() - 1;
        while (bottom <= top) {
            int mid = (bottom + top) / 2;
            if (num[mid] > 0)
                top = mid - 1;
            else if (num[mid] < 0)
                bottom = mid + 1;
            else
                return mid;
        }
        return top;
    }
};//AC!