class Solution {
public:
    int maxArea(vector<int> &height) {
        stack<int> index, hval;
        int size = height.size();
        int save;
        for (int i = 0; i != size; ){
        	if (hval.empty() || height[i] < hval.top()) {
        		if (hval.empty())
        			save = i;
        		hval.push(height[i]);
        		index.push(i);
        		++i;
        	}
        	else {
        		if (index.top() != save) {
        			index.pop();
        			hval.pop();
        		}
        		else {
        			hval.push(height[i]);
        			index.push(i);
        			save = i;
        			++i;
        		}
        	}
        }
        int max = 0;
        vector<int> huse, iuse;
        while (!hval.empty()){
        	huse.push_back(hval.top());
        	iuse.push_back(index.top());
        	hval.pop(); index.pop();
        }
        for (int i = 0, j = huse.size() - 1; i < j; ){
        	if (huse[i] < huse[j]) {
        		max = max_val(max, huse[i] * (iuse[i] - iuse[j]));
        		++i;
        	}
        	else {
        		max = max_val(max, huse[j] * (iuse[i] - iuse[j]));
        		--j;
        	}
        }
        return max;
    }
    int max_val(int ix, int iy) {
    	return ix > iy ? ix : iy;
    }
};
//
class Solution {
public:
    int maxArea(vector<int> &height) {
        if (!height.size())
            return 0;
        int max = 0;
        for (int i = 0, j = height.size() - 1; i < j; ){
            if (height[i] < height[j]) {
                max = max_val(max, height[i] * (j - i));
                ++i;
            }
            else {
                max = max_val(max, height[j] * (j - i));
                --j;
            }
        }
        return max;
    }
    int max_val(int ix, int iy) {
        return ix > iy ? ix : iy;
    }
};