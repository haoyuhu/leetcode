class Solution {
public:
    int search(int A[], int n, int target) {
        int bottom = 0, top = n - 1, mid;
        while (bottom <= top){
        	mid = (bottom + top) / 2;
        	if (A[mid] == target) return mid;
        	else if (A[top] == target) return top;
        	else if (target > A[mid] || target < A[top]){
        		bottom = mid + 1;
        	}
        	else top = mid - 1;
        }
        return -1;
    }
};