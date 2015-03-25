class Solution {
public:
    int search(int A[], int n, int target) {
        for (int i = 0; i != n; ++i) {
            if (A[i] == target)
                return i;
        }
        return -1;
    }
};
//
class Solution {
public:
    int search(int A[], int n, int target) {
        int bottom = find_min_index(A, n);
        return binary_search(A, n, bottom, target);
    }
    int binary_search(int arr[], int n, int start, int target) {
        int bottom = start, top = start + n - 1;
        while (bottom <= top) {
            int mid = ((bottom + top) / 2);
            if (arr[mid%n] > target)
                top = mid - 1;
            else if (arr[mid%n] < target)
                bottom = mid + 1;
            else
                return mid%n;
        }
        return -1;
    }
    int find_min_index(int arr[], int n) {
    	int bottom = 0, top = n - 1;
    	while (bottom <= top) {
    		int mid = (bottom + top) / 2;
    		if (mid && arr[mid] < arr[mid-1])
    			return mid;
    		else if (arr[mid] >= arr[bottom] && arr[mid] >= arr[top])
    			bottom = mid + 1;
    		else
    			top = mid - 1;
    	}
    	return 0;
    }
};