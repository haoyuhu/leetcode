class Solution {
public:
    #define MAX_INT 999999999
    int minCut(string s) {
        int size = s.size();
        if (!size)
            return 0;
        int answer[size];
        bool tag[size][size];
        for (int i = 0; i != size; ++i){
            tag[i][i] = true;
        }
        for (int l = 1; l != size; ++l){
            for (int i = 0; i != size - l; ++i){
                int j = i + l;
                if ((i + 1 > j - 1 || tag[i+1][j-1]) && s[i] == s[j])
                    tag[i][j] = true;
                else
                    tag[i][j] = false;
            }
        }
        for (int i = 0; i != size; ++i){
            answer[i] = MAX_INT;
            for (int j = 0; j <= i; ++j){
                if (tag[j][i]) {
                    if (!j) {
                        answer[i] = 1; break;
                    }
                    else
                        answer[i] = min_val(answer[i], answer[j-1] + 1);
                }
            }
        }
        return answer[size-1] - 1;
    }
/*    bool ispalindrome(string s, int i, int j){
        if (i == j)
            return true;
        stack<char> cstk;
        int mid = (i + j) / 2;
        for (int k = i; k <= mid; ++k){
            cstk.push(s[k]);
        }
        if ((j - i + 1) % 2)
            cstk.pop();
        ++mid;
        for (; mid <= j; ++mid){
            if (s[mid] != cstk.top())
                return false;
            cstk.pop();
        }
        return true;
    }*/
    int min_val(int ix, int iy) {
        return ix < iy ? ix : iy;
    }
}; 