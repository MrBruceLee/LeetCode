/*
 *  Binary Search
 *
 */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size()-1;
        
        while(front <= back){
            int mid = front + (back - front) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < nums[back]){
                if(nums[mid] < target && target <= nums[back])
                    front = mid + 1;
                else
                    back = mid - 1;
                
            }else{
                if(nums[front] <= target && target < nums[mid])
                    back = mid - 1;
                else
                    front = mid + 1;
            }
            
        }
        
        return -1;
    }
};