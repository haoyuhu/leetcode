class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int size = num.size();
        sort(num.begin(), num.end());
        int answer[size];
        answer[0] = 1;
        for (int i = 1; i != size; ++i){
            if (num[i] == num[i-1] + 1)
                answer[i] = answer[i-1] + 1;
            else if (num[i] != num[i-1])
                answer[i] = 1;
            else
                answer[i] = answer[i-1];
        }
        int max = 0;
        for (int i = 0; i != size; ++i){
            max = max_val(answer[i], max);
        }
        return max;
    }
/*    void quicksort(vector<int> &num, int bottom, int top) {
    	if (bottom >= top)
            return;
        int i = bottom, j = top;
        int save = num[i];
    	while (i < j){
    		for (; j != i && num[j] >= save; --j);
            num[i] = num[j];
            for (; i != j && num[i] <= save; ++i);
            num[j] = num[i];
    	}
        num[i] = save;
        quicksort(num, bottom, i - 1);
        quicksort(num, i + 1, top);
    }*/
    int max_val(int ix, int iy) {
        return ix > iy ? ix : iy;
    }
};