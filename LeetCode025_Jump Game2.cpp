//method 1:
class Solution {
public:
    #define MAX_INT	2147483647
    int jump(int A[], int n) {
        return JumpTime(A, n, 0);
    }
    int JumpTime(int *arr, int n, int i){
    	if (i == n - 1){
    		return 0;
    	}
    	int min = MAX_INT, tmp;
    	for (int j = 1; j <= arr[i] && j < n - i; ++j){
    		tmp = JumpTime(arr, n, i + j);
    		if (tmp < min){
    			min = tmp;
    		}
    	}
    	return min + 1;
    }
};//more than O(n2)
//////////////////////////////////////////////////////////
//method 2:
class Solution {
public:
    #define MAX_INT	2147483647
    int jump(int A[], int n) {
        if (n == 1){
        	return 0;
        }
        return JumpTime(A, n, 0);
    }
    int JumpTime(int *arr, int n, int i){
    	if (arr[i] >= n - i - 1){
    		return 1;
    	}
    	int min = MAX_INT, tmp;
    	for (int j = 1; j <= arr[i]; ++j){
    		if (!arr[i+j]){
    			continue;
    		}
    		tmp = JumpTime(arr, n, i + j);
    		if (tmp < min){
    			min = tmp;
    		}
    	}
    	return min + 1;
    }
};//more than O(n2)
//////////////////////////////////////////////////////////
//method 3:
class Solution {
public:
    #define MAX_INT 2147483647
    int jump(int A[], int n) {
        if (n == 1){
            return 0;
        }
        int distance[n];
        bool final[n];
        for (int i = 0; i < n; ++i){
            if (i > 0 && i <= A[i]){
                distance[i] = 1;
            }
            else distance[i] = MAX_INT;
            final[i] = false;
        }
        final[0] = true;
        int min, v;
        for (int i = 1; i < n - 1; ++i){
            min = MAX_INT;
            for (int w = 0; w < n; ++w){
                if (!final[w] && distance[w] < min){
                    min = distance[w]; v = w;
                }
            }
            final[v] = true;
            for (int w = v + 1; w <= v + A[v] && w < n; ++w){
                if (!final[w] && distance[w] > min + 1){
                    distance[w] = min + 1;
                }
            }
        }
        return distance[n-1];
    }
};//O(n2)
//////////////////////////////////////////////////////////
//method 4:
class Solution {
public:
    #define MAX_INT 2147483647
    int jump(int A[], int n) {
        int distance[n];
        distance[0] = 0;
        for (int i = 1; i < n; ++i){
            int min = MAX_INT;
            for (int j = 0; j < i; ++j){
                if (j + A[j] >= i && distance[j] < min){
                    min = distance[j];
                }
            }
            if (min < MAX_INT){
                distance[i] = min + 1;
            }
            else return -1;
        }
        return distance[n-1];
    }
};//O(n2)
//////////////////////////////////////////////////////////
//method 5:
class Solution {
public:
    int jump(int A[], int n) {
        int distance[n], ct = 1;//ct start 1, important!
        for (int i = 0; i < n; ++i){
            distance[i] = 0;
        }
        for (int i = 0; i < n && !distance[n-1]; ++i){
            if (i && !distance[i]){
                return -1;
            }
            while (ct <= i + A[i] && ct < n){
                distance[ct++] = distance[i] + 1;
            }
        }
        return distance[n-1];
    }
};//O(n) good! accepted by leetcode!
//
class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1)
            return 0;
        queue<int> available, count;
        vector<int> visited(n, false);
        available.push(0); visited[0] = true;
        count.push(0);
        while (!available.empty()) {
            int cur = available.front(); available.pop();
            int cnt = count.front(); count.pop();
            for (int i = A[cur]; i != 0; --i) {
                if (cur + i >= n - 1)
                    return cnt + 1;
                if (visited[cur+i])
                    break;
                available.push(cur + i); count.push(cnt + 1);
                visited[cur+i] = true;
            }
        }
        return -1;
    }
};
