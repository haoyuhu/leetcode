class Solution {
public:
    double pow(double x, int n) {
        if (!x)
            return 0;
        if (n < 0)
        	return 1 / abs_pow(x, -n);
        else
        	return abs_pow(x, n);
    }
    double abs_pow(double x, int n) {
        if (!n) return 1;
        double t = abs_pow(x, n / 2);
        if (n % 2 == 0)
        	return t * t;
        else
        	return t * t * x;
    }
};
