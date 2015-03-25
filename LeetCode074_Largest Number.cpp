void qsort(vector<int> &num, int i, int j, bool (*compare)(int, int));
bool compare(int ix, int iy);
int make_num(int ix, int iy);
class Solution {
public:
    string largestNumber(vector<int> &num) {
    	int tag;
    	for (tag = 0; tag != num.size() && !num[tag]; ++tag);
    	if (tag == num.size())
    		return string("0");
        qsort(num, 0, num.size() - 1, compare);
        string save;
        for (int i = num.size() - 1; i >= 0; --i){
        	int t = num[i];
        	if (!t) {
        		save.insert(save.end(), '0');
        		continue;
        	}
        	stack<char> cstk;
        	while (t != 0){
        		cstk.push(turn_str(t % 10));
        		t /= 10;
        	}
        	while (!cstk.empty()) {
        		save.insert(save.end(), cstk.top());
        		cstk.pop();
        	}
        }
        return save;
    }
    char turn_str(int ix){
    	return '0' + ix;
    }
};
void qsort(vector<int> &num, int i, int j, bool (*compare)(int, int)){
	if (i >= j)
		return;
	int bottom = i, top = j;
	int save = num[i];
	while (bottom < top){
		for (; top != bottom && compare(save, num[top]); --top);
		num[bottom] = num[top];
		for (; top != bottom && compare(num[bottom], save); ++bottom);
		num[top] = num[bottom];
	}
	num[bottom] = save;
	if (2 * (bottom - i) < j - i + 1){
		qsort(num, i, bottom - 1, compare);
		qsort(num, bottom + 1, j, compare);
	}
	else {
		qsort(num, bottom + 1, j, compare);
		qsort(num, i, bottom - 1, compare);
	}
}
bool compare(int ix, int iy) {
	int ix_iy = make_num(ix, iy);
	int iy_ix = make_num(iy, ix);
	if (ix_iy <= iy_ix)
		return true;
	else
		return false;
}
int make_num(int ix, int iy) {
	if (!ix)
		return iy;
	if (!iy)
		return 10 * ix;
	int expn = 1;
	while (expn <= iy)
		expn *= 10;
	return ix * expn + iy;
}