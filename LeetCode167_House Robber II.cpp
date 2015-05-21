class Solution {
public:
	const static int MIN_INT = -999999999;

    int rob(vector<int>& nums) {
        int houseNumber = nums.size();
        if (!houseNumber) return 0;
        if (houseNumber == 1) return nums[0];
        int robMoney[houseNumber][4];

        for (int i = 0; i != houseNumber; ++i) {
        	for (int j = 0; j != 4; ++j) {
        		robMoney[i][j] = 0;
        	}
        }

        robMoney[0][3] = nums[0];
        robMoney[0][1] = robMoney[0][2] = MIN_INT;

        for (int i = 1; i < houseNumber; ++i) {
        	robMoney[i][0] = max(robMoney[i-1][0], robMoney[i-1][1]);
        	robMoney[i][1] = robMoney[i-1][0] + nums[i];
        	robMoney[i][2] = max(robMoney[i-1][2], robMoney[i-1][3]);
        	robMoney[i][3] = robMoney[i-1][2] + nums[i];
        }

        return max(robMoney[houseNumber-1][0], robMoney[houseNumber-1][1], robMoney[houseNumber-1][2]);
    }

    int max(int x, int y) { return x > y ? x : y; }

    int max(int x, int y, int z) {
    	if (x >= y && x >= z) return x;
    	if (y >= x && y >= z) return y;
    	return z;
    }
};