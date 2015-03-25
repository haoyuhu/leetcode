class Solution {
public:
    bool canJump(int A[], int n) {
        int far = 0;
        for (int i = 0; i < n - 1 && far < n - 1; ++i){
        	if (i > far){
        		return false;
        	}
        	if (A[i] + i >= far){
        		far = A[i] + i;
        	}
        }
        if (far >= n - 1){
        	return true;
        }
        else return false;
    }
};
////////////////////////////////////////////
class Solution {
public:
    bool canJump(int A[], int n) {
        typedef struct pair{
            int index, int minjp;
        }pair;
        list<pair> lst;
        lst.push_back(pair(-1, 0));
        for (int i = 0; i < n; ++i){
            int min = 0;
            pair use = lst.front();
            if (use.index == -1)
                min = use.minjp;
            else {
                while (A[use.index] < i - use.index){
                    lst.erase(lst.begin());
                    if (lst.empty())
                        return -1;
                    use = lst.front(); 
                }
                min = use.minjp;
            }
            ++min;
            while (lst.back().minjp > min){
                lst.erase(lst.rbegin());
            }
            lst.push_back(pair(i, min));
        }
        return lst.front().minjp + 1;
    }
};
//
class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 1)
            return true;
        queue<int> available;
        vector<int> visited(n, false);
        available.push(0); visited[0] = true;
        while (!available.empty()) {
            int cur = available.front(); available.pop();
            for (int i = A[cur]; i != 0; --i) {
                if (cur + i >= n - 1)
                    return true;
                if (visited[cur+i])
                    break;
                available.push(cur + i); visited[cur+i] = true;
            }
        }
        return false;
    }
};