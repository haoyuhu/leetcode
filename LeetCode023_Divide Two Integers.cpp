class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1 || divisor == -1)
            return dividend * -1;
        bool tagdd = dividend>0 ? true: false;
        bool tagdr = divisor>0 ? true: false;
        bool tag = tagdd && tagdr || !tagdd && !tagdr ? true: false;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int ct = 0, tmp = divisor;
        while (tmp <= dividend){
        	++ct; tmp += divisor;
        }
        if (tag){
        	return ct;
        }
        else return -ct;
    }
};
//
class Solution {
public:
    #define MAX_INT 2147483647
    #define MIN_INT -2147483648
    int divide(int dividend, int divisor) {
        if (!divisor)
            return MAX_INT;
        if (dividend == MIN_INT) {
            if (divisor == 1)
                return MIN_INT;
            else if (divisor == -1)
                return MAX_INT;
        }
        bool tag = find_tag(dividend, divisor);
        int count = 0, use, t, answer;
        if (pre_deal(count, dividend, divisor, answer))
            return answer;
        while (divisor <= dividend) {
            t = divisor; use = 1;
            while (t <= dividend && (t << 1) > t) {
                t <<= 1; use <<= 1;
            }
            if (t > dividend) {
                t >>= 1; use >>= 1;
            }
            dividend -= t;
            if (count != MAX_INT)
                count += use;
        }
        if (tag)
            return count;
        else
            return -count;
    }
    bool pre_deal(int &count, int &dividend, int &divisor, int &answer) {
        dividend = minus(dividend); divisor = minus(divisor);
        if (dividend > divisor) {
            answer = count; return true;
        }
        else {
            dividend -= divisor;
            ++count;
            dividend = plus(dividend);
            if (divisor != MIN_INT) {
                divisor = plus(divisor);
                return false;
            }
            else {
                answer = count;
                return true;
            }
        }
    }
    int minus(int x) {
        return x > 0 ? -x : x;
    }
    int plus(int x) {
        return x > 0 ? x : -x;
    }
    bool find_tag(int ix, int iy) {
        if (ix >= 0 && iy >= 0 || ix <= 0 && iy <= 0)
            return true;
        else
            return false;
    }
};