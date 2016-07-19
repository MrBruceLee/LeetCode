class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> results;
        
        // 4Sum
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            // 3Sum
            for(int j = i + 1; j < nums.size(); j++) {
                if(j != i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                
                // 2Sum
                int sum = target - nums[i] - nums[j];
                int front = j + 1;
                int end = nums.size() - 1;
                
                while(front < end) {
                    if(nums[front] + nums[end] < sum) {
                        front++;
                    } else if (nums[front] + nums[end] > sum) {
                        end--;
                    } else {
                        if(front == j + 1 || nums[front] != nums[front-1]) {
                            results.push_back({nums[i], nums[j], nums[front], nums[end]});
                        }
                        front++;
                        end--;
                    }
                }
            }
        }
        
        return results;
    }
};