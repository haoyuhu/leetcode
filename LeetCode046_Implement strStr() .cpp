class Solution {
public:
    int strStr(char *haystack, char *needle) {
        string hstk(haystack), ndl(needle);
	    int len_hstk = hstk.size();
	    int len_ndl = ndl.size();
	    if (len_hstk < len_ndl) return -1;
	    int next[len_ndl];
	    for (int k = 0; k != len_ndl; ++k){
	        next[k] = -1;
	    }
	    for (int k = 0, l = -1; k != len_ndl; ){
	    	if (l == -1 || ndl[k] == ndl[l]){
	    		++k; ++l;
	    		if (k == len_ndl) break;
	    		if (ndl[k] == ndl[l]){
	    			next[k] = next[l];
	    		}
	    		else next[k] = l;
	    	}
	    	else
	    		l = next[l];
	    }
	    int i, j;
	    for (i = 0, j = 0; i != len_hstk && j != len_ndl; ){
	    	if (j == -1 || hstk[i] == ndl[j]){
	    		++i; ++j;
	    	}
	    	else
	    		j = next[j];
	    }
	    if (j == len_ndl)
	    	return i - j;
	    else return -1;
    }
};