class Solution {
public:
    #define MAX_INT 2147483647
    #define MIN_INT -2147483648
    string fractionToDecimal(int numerator, int denominator) {
        string answer;
        if (!denominator)
            return answer;
        if (numerator == MIN_INT) {
            if (denominator == 1)
                return string("-2147483648");
            else if (denominator == -1)
                return string("2147483648");
        }
        if (!numerator)
            return string("0");
        if (denominator == MIN_INT)
            return ftoa((double)numerator / denominator);
        int md = input_integerpart(answer, numerator, denominator);
        if (md) {
            answer.push_back('.');
            int t = md * 10, cnt = 0;
            string s;
            unordered_map<int, int> save;
            unordered_map<int, int>::iterator it;
            while (t && (it = save.find(t)) == save.end()) {
                save.insert(pair<int, int>(t, cnt++));
                if (t < denominator) {
                    t *= 10; s.push_back('0');
                }
                else
                    t = input_decimalpart(s, t, denominator) * 10;
            }
            if (t) {
                s.insert(it->second, 1, '(');
                s.push_back(')');
            }
            answer += s;
        }
        return answer;
    }
    int input_integerpart(string &answer, int &numerator, int &denominator) {
        bool tag;
        if (numerator >= 0 && denominator >=0 || numerator < 0 && denominator < 0)
            tag = true;
        else
            tag = false;
        numerator = abs(numerator); denominator = abs(denominator);
        int intpart = numerator / denominator, decpart = numerator - intpart * denominator;
        if (!intpart)
            answer.push_back('0');
        while (intpart) {
            answer.insert(answer.begin(), turn_char(intpart % 10));
            intpart /= 10;
        }
        if (!tag)
            answer.insert(answer.begin(), '-');
        return decpart;
    }
    int input_decimalpart(string &answer, int numerator, int denominator) {
        int intpart = numerator / denominator, decpart = numerator - intpart * denominator;
        answer.push_back(turn_char(intpart));
        return decpart;
    }
    char turn_char(int intpart) {
        return '0' + intpart;
    }
    string ftoa(double x) {
        if (x == 1)
            return string("1");
        string answer;
        int cnt = 0;
        if (x < 0)
            answer += string("-0.");
        else
            answer += string("0.");
        x = abs(x) * 10;
        while (x != 0) {
            int intpart = static_cast<int> (x);
            answer.push_back(turn_char(intpart));
            x = (x - intpart) * 10;
        }
        return answer;
    }
};