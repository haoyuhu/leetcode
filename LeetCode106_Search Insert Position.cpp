class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j){
        	int mid = (i + j) / 2;
        	if (A[mid] > target)
        		j = mid - 1;
        	else if (A[mid] < target)
        		i = mid + 1;
        	else
        		return mid;
        }
        return j + 1;
    }
};