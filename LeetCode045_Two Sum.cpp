class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> answer, numbers_copy(numbers);
        int num_left, num_right;
        sort(numbers_copy.begin(), numbers_copy.end());
        for (int i = 0, j = numbers_copy.size() - 1; i < j; ){
        	if (numbers_copy[i] + numbers_copy[j] > target){
        		--j;
        	}
        	else if (numbers_copy[i] + numbers_copy[j] < target){
        		++i;
        	}
        	else {
        		num_left = numbers_copy[i];
        		num_right = numbers_copy[j];
        		break;
        	}
        }
        for (int i = 0; i != numbers.size(); ++i){
        	if (num_left == numbers[i] || num_right == numbers[i])
        		answer.push_back(i+1);
        }
        if (answer.front() > answer.back()){
        	reverse(answer.begin(), answer.end());
        }
        return answer;
    }
};