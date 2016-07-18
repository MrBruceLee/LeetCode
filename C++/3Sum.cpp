/*
 *  Runtime - O(N^2)
 *  Space - O(1)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort - runtime O(N*log(N))
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> results;
        
        // runtime O(N^2)
        for(int i = 0; i < nums.size(); i++) {
            // prevent duplicate triplets
            if(i != 0) {
                if(nums[i] == nums[i-1]){
                    continue;
                }
            }
            
            // tow sum
            int front = i + 1;
            int end = nums.size() - 1;
            int sum = 0 - nums[i];
            
            while(front < end) {
                if(nums[front] + nums[end] < sum) {
                    front++;
                } else if(nums[front] + nums[end] > sum) {
                    end--;
                } else {
                    /* prevent duplicate triplets. The two conditions are both worked, because here we guarantee that:
                     * either: nums[front] == nums[front-1] && nums[end] == nums[end+1]
                     * or: nums[front] != nums[front-1] && nums[end] != nums[end+1]
                     */
                    //if( front == i+1 || nums[front] != nums[front-1] ) {
                    if( end == nums.size() -1 || nums[end] != nums[end+1] ) {
                        results.push_back({nums[i], nums[front], nums[end]});
                    }
                    front++;
                    end--;
                }
            }
        }
        
        return results;
    }
};