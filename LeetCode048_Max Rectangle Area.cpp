class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> h, index;
        int area = 0;
        for (int i = 0; i != height.size() || !h.empty(); ){
        	while (i != height.size() && (h.empty() || h.top() <= height[i])){
        		h.push(height[i]); index.push(i);
        		++i;
        	}
        	int ht, k;
        	while (!h.empty() && (i == height.size() || h.top() > height[i])){
        		ht = h.top();
        		k = index.top();
        		int new_area = ht * (i - k);
        		if (new_area > area){
        			area = new_area;
        		}
        		h.pop(); index.pop();
        	}
        	if (i != height.size()){
        		h.push(height[i]);
        		index.push(k);
        		++i;
        	}
        }
        return area;
    }
};