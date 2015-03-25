class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int bad_cost = 0, start;
        int sum_gas = 0, sum_cost = 0;
        for (int i = 0; i != gas.size(); ++i){
        	sum_cost += cost[i];
        	sum_gas += gas[i];
        	if (sum_gas - sum_cost < bad_cost){
        		bad_cost = sum_gas - sum_cost;
        		start = i;
        	}
        }
        if (sum_cost - sum_gas > 0){
        	return -1;
        }
        else return (start + 1) % gas.size();
    }
};