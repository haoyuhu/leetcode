// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int bottom = 1, top = n;
        while (bottom <= top) {
        	int mid = bottom + (top - bottom) / 2;
        	if (isBadVersion(mid)) {
        		if (mid - 1 < 1 || mid - 1 >= 1 && !isBadVersion(mid - 1)) {
        			return mid;
        		} else {
        			top = mid - 1;
        		}
        	} else {
        		if (mid + 1 > n || mid + 1 <= n && isBadVersion(mid + 1)) {
        			return mid + 1;
        		} else {
        			bottom = mid + 1;
        		}
        	}
        }
    }
};