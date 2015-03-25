class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        if (!k) return;
        int count = 0, cur = n - 1, pre;
        vector<int> visited(n, false);
        while (count < n) {
        	for (; cur >= 0 && visited[cur]; --cur);
        	int save = nums[cur];
        	for (pre = (cur + n - k) % n; !visited[pre]; cur = pre, pre = (cur + n - k) % n) {
        		visited[cur] = true;
        		nums[cur] = nums[pre];
        		++count;
        	}
        	visited[cur] = true;
        	nums[cur] = save; ++count;
        	cur = pre;
        }
    }
};
//
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        if (!k) return;
        int s = n - k;
        reverseArray(nums, s, n - 1);
        reverseArray(nums, 0, s - 1);
        reverseArray(nums, 0, n - 1);
    }
    void reverseArray(int nums[], int s, int e) {
    	while (s < e) {
    		int t = nums[s];
    		nums[s] = nums[e];
    		nums[e] = t;
    		++s; --e;
    	}
    }
};