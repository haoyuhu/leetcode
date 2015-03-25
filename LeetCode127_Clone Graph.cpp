/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	UndirectedGraphNode *root;
    	unordered_map<int, UndirectedGraphNode*> save;
    	clone(node, root, save);
    	return root;
    }
    void clone(UndirectedGraphNode *node, UndirectedGraphNode *&root,
    	unordered_map<int, UndirectedGraphNode*> &save) {
    	if (!node) {
    		root = NULL; return;
    	}
    	root = new UndirectedGraphNode(node->label);
    	save.insert(make_pair(root->label, root));
    	unordered_map<int, UndirectedGraphNode*>::iterator it;
    	for (int i = 0; i != node->neighbors.size(); ++i) {
    		int t = node->neighbors[i]->label;
    		if ((it = save.find(t)) != save.end())
    			root->neighbors.push_back(it->second);
    		else {
    			root->neighbors.push_back(NULL);
    			clone(node->neighbors[i], root->neighbors[root->neighbors.size()-1], save);
    		}
    	}
    }
};