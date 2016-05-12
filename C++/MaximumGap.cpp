/*
 *  runtime - O(NlogN)
 *
 */


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int diff = 0;
        
        for(int i = 1; i < nums.size(); i++){
            diff = max(diff, nums[i] - nums[i-1]);
        }
        
        return diff;
    }
};


/*
 *  runtime - O(N)  space - O(N)
 *
 */

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        // find the max and min value in nums
        int maxValue = nums[0];
        int minValue = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxValue) maxValue = nums[i];
            if(nums[i] < minValue) minValue = nums[i];
        }
        
        // recording the max and min value inside a bucket
        int len = (maxValue - minValue) / nums.size() + 1;
        vector<vector<int>> buckets((maxValue - minValue) / len + 1);
        for(int i = 0; i < nums.size(); i++){
            int buck = (nums[i] - minValue) / len;
            
            if(buckets[buck].empty() == true){
                buckets[buck].push_back(nums[i]);
                buckets[buck].push_back(nums[i]);
                
            }else{
                if(nums[i] < buckets[buck][0]) buckets[buck][0] = nums[i];
                if(nums[i] > buckets[buck][1]) buckets[buck][1] = nums[i];
            }
        }
        
        // Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets
        int maxGap = 0;
        int prevBuck = 0;
        for(int i = 1; i < buckets.size(); i++){
            if(buckets[i].empty() == true) {
                continue;
            }
            maxGap = max(maxGap, buckets[i][0] - buckets[prevBuck][1]);
            prevBuck = i;
        }
        
        return maxGap;
    }
};