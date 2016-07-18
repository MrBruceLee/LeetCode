class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // runtime - O(N*log(N))
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX;
        
        // runtime - (N^2)
        for(int i = 0; i < nums.size(); i++) {
            int front = i + 1;
            int end = nums.size() - 1;
            
            while(front < end) {
                int sum = nums[i] + nums[front] + nums[end];
                
                if(abs(sum - target) < abs(diff)) {
                    diff = sum - target;
                }
                
                if(sum < target) {
                    front++;
                } else if(sum > target) {
                    end--;
                } else {
                    return target;
                }
            }
        }
        
        return target + diff;
    }
};