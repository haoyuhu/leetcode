//Given an array of integers, every element appears twice except for one. Find that single one.
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
//LeetCode OJ
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n == 1) return A[0];
        int max = A[0];
        int min = A[0];
        int num;
        for (int i = 1; i < n; ++i){
            if (max < A[i]) max = A[i];
            if (min > A[i]) min = A[i];
        }
        num = max - min + 1;
        int tmp[num];
        for (int i = 0; i < num; ++i) tmp[i] = 0;
        for (int i = 0; i < n; ++i) tmp[A[i] - min]++;
        for (int i = 0; i < num; ++i){
            if (tmp[i] == 1) return i + min;
        }
    }
};
