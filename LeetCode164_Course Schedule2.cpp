class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> answer;
        if (numCourses == 1) {
            answer.push_back(0); return answer;
        }
        vector<vector<int>> map(numCourses, vector<int>());
        stack<int> reversePostOrder;
        for (int i = 0; i < prerequisites.size(); ++i) {
        	map[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<bool> isVisited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
        	if (!isVisited[i]) {
        		vector<bool> onStack(numCourses, false);
        		if (hasCycle(map, i, isVisited, onStack, reversePostOrder))
        			return answer;
        	}
        }
        while (!reversePostOrder.empty()) {
        	int index = reversePostOrder.top(); reversePostOrder.pop();
        	answer.push_back(index);
        }
        return answer;
    }
    bool hasCycle(vector<vector<int>> &map, int i, vector<bool> &isVisited, vector<bool> &onStack, stack<int> &reversePostOrder) {
    	isVisited[i] = true;
    	onStack[i] = true;
    	for (int k : map[i]) {
			if (onStack[k])
				return true;
			else if (!isVisited[k])
				if (hasCycle(map, k, isVisited, onStack, reversePostOrder))
					return true;
    	}
    	onStack[i] = false;
    	reversePostOrder.push(i);
    	return false;
    }
};