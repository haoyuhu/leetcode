class Solution {
    public:
    vector< vector<string> > partition(string s) {
        vector< vector<string> > answer;
        if (!s.size())
            return answer;
        answer.push_back(vector<string>());
        part_solution(s, s.size() - 1, answer, 0);
        return answer;
    }
    void part_solution(string s, int split, vector< vector<string> > &answer, int now){
        if (split < 0)
            return;
        int start;
        bool isfirst = true;
        vector<string> st(answer[now]);
        for (start = 0; start <= split; ++start){
            if (ispalindrome(s, start, split)) {
                if (isfirst) {
                    answer[now].insert(answer[now].begin(), string(s, start, split - start + 1));
                    part_solution(s, start - 1, answer, now);                  
                    isfirst = false;
                }
                else {
                    answer.push_back(st);
                    int size = answer.size();
                    answer[size-1].insert(answer[size-1].begin(), string(s, start, split - start + 1));
                    part_solution(s, start - 1, answer, size - 1);
                }
            }
        }
    }
    bool ispalindrome(string s, int i, int j){
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
    }
};