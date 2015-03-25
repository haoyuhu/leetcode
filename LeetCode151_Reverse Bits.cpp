class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int revn = 0;
        for (int i = 0; i != 32; ++i) {
            revn = (revn << 1) + n % 2;
            n >>= 1;
        }
        return revn;
    }
};