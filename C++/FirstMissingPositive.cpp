/*
 *  place each number under their corresponding index
 *
 */


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            // swap when:
            // 1. current number is in the range: ( 0 , nums.size() ]
            // 2. current number is not in the right place
            // 3. the numbers that will be swapped are not equal, e.g. [1, 1]
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                return i + 1;
            }
        }
        
        return nums.size() + 1;
    }
};