class Solution {
public:
    int findMin(vector<int> &num) {
        int bottom = 0, top = num.size() - 1;
        int mid;
        while (bottom < top){
            mid = (bottom + top) / 2;
            if (mid && num[mid] < num[mid-1])
                return num[mid];
            if (num[mid] >= num[top] && num[mid] >= num[bottom])
                bottom = mid + 1;
            else if (num[mid] < num[top] && num[mid] < num[bottom])
                top = mid - 1;
            else
                top = mid - 1;
        }
        return num[bottom];
    }
};