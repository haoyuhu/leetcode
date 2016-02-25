class Solution {
public:
    bool isScramble(string s1, string s2) {
        return checkScrambleStrings(s1, s2);
    }
private:
	bool checkScrambleStrings(string origin, string match) {
		vector<int> store(26, 0);
		int length = origin.length(), half;
		for (int i = 0; i != length; ++i) {
			store[origin[i] - 'a'] += 1;
		}
		for (int i = 0; i != length; ++i) {
			store[match[i] - 'a'] -= 1;
			if (store[match[i] - 'a'] < 0) {
				return false;
			}
		}
		if (origin == match) {
			return true;
		}
		if (length == 1 && origin != match) {
			return false;
		}
		for (half = 1; half < length; ++half) {
			string frontOrigin(origin, 0, half), rearOrigin(origin, half, length - half);
			string frontMatch(match, 0, half), rearMatch(match, half, length - half);
			string rfrontMatch(match, 0, length - half), rrearMatch(match, length - half, half);

			if (checkScrambleStrings(frontOrigin, frontMatch) && checkScrambleStrings(rearOrigin, rearMatch)) {
				return true;
			}
			if (checkScrambleStrings(rearOrigin, rfrontMatch) && checkScrambleStrings(frontOrigin, rrearMatch)) {
				return true;
			}
		}
		return false;
 	}
};