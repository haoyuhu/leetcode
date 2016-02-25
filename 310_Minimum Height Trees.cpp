class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 1) return vector<int> (1, 0);
		if (n == 2) return vector<int> ({0, 1});
		int count = 0;
        vector<int> counter = vector<int> (n, 0);
        vector<vector<int>> nodes = vector<vector<int>> (n, vector<int> ());
        for (int i = 0; i != edges.size(); ++i) {
        	int s = edges[i].first, e = edges[i].second;
        	nodes[s].push_back(e);
        	nodes[e].push_back(s);
        	++counter[s];
        	++counter[e];
        }
        queue<int> leaves;
        bool tag = false;
        int last, final;
        for (int i = 0; i != n; ++i) {
        	if (counter[i] == 1) {
        		leaves.push(i);
        		final = i;
        	}
        }
        while (count < n - 2 || !tag) {
        	int curr = leaves.front();
        	leaves.pop();
        	++count;
        	for (int i = 0; i != nodes[curr].size(); ++i) {
        		int next = nodes[curr][i];
        		if (--counter[next] == 1) {
        			leaves.push(next);
        			last = next;
        			tag = false;
        		}
        	}
        	if (curr == final) {
        		final = last;
        		tag = true;
        	}
        }

        vector<int> answers;
        while (!leaves.empty()) {
        	answers.push_back(leaves.front());
        	leaves.pop();
        }
        return answers;
    }

	vector<int> findMinHeightTreesTLE1(int n, vector<pair<int, int>>& edges) {
		if (n == 1) return vector<int> (1, 0);
		if (n == 2) return vector<int> ({0, 1});
		int count = 0;
        vector<int> counter = vector<int> (n, 0);
        vector<vector<bool>> mat = vector<vector<bool>> (n, vector<bool> (n, false));
        for (int i = 0; i != edges.size(); ++i) {
        	int s = edges[i].first, e = edges[i].second;
        	mat[s][e] = mat[e][s] = true;
        	++counter[s];
        	++counter[e];
        }
        queue<int> leaves;
        bool tag = false;
        int last, final;
        for (int i = 0; i != n; ++i) {
        	if (counter[i] == 1) {
        		leaves.push(i);
        		final = i;
        	}
        }
        while (count < n - 2 || !tag) {
        	int curr = leaves.front();
        	leaves.pop();
        	counter[curr] = 0;
        	++count;
        	for (int i = 0; i != n; ++i) {
        		if (mat[curr][i]) {
        			mat[curr][i] = mat[i][curr] = false;
        			if (--counter[i] == 1) {
        				leaves.push(i);
        				last = i;
        				tag = false;
        			}
        		}
        	}
        	if (curr == final) {
        		final = last;
        		tag = true;
        	}
        }
        vector<int> answers;
        while (!leaves.empty()) {
        	answers.push_back(leaves.front());
        	leaves.pop();
        }
        return answers;
    }

    vector<int> findMinHeightTreesTLE2(int n, vector<pair<int, int>>& edges) {
        vector<vector<bool>> mat = vector<vector<bool>> (n, vector<bool> (n, false));
        for (int i = 0; i != edges.size(); ++i) {
        	int s = edges[i].first, e = edges[i].second;
        	mat[s][e] = mat[e][s] = true;
        }

        vector<int> answers;
        int min = -1;
        for (int root = 0; root != n; ++root) {
        	int local = bfs(root, mat);
        	if (local == min) {
        		answers.push_back(root);
        	} else if (local < min || min == -1) {
        		min = local;
        		answers.clear();
        		answers.push_back(root);
        	}
        }

        return answers;
    }

    int bfs(int root, vector<vector<bool>> mat) {
    	int height = 0;
    	int last, tag = root;
    	queue<int> nodes;
    	nodes.push(root);

    	while (!nodes.empty()) {
    		int curr = nodes.front();
    		nodes.pop();
    		for (int i = 0; i != mat.size(); ++i) {
    			if (mat[curr][i]) {
    				mat[curr][i] = mat[i][curr] = false;
    				nodes.push(i);
    				last = i;
    			}
    		}
    		if (curr == tag) {
    			++height;
    			tag = last;
    		}
    	}

    	return height;
    }

    int dfs(int curr, vector<vector<bool>>& mat) {
    	int maxValue = 1;
    	for (int i = 0; i != mat.size(); ++i) {
    		if (mat[curr][i]) {
    			mat[curr][i] = mat[i][curr] = false;
    			maxValue = max(maxValue, dfs(i, mat) + 1);
    			mat[curr][i] = mat[i][curr] = true;
    		}
    	}
    	return maxValue;
    }
};