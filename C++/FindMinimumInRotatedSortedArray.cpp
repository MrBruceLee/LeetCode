/*
 *  Binary search - runtime O(logN) - space O(1)
 *
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int back = nums.size()-1;
        
        int mid = 0;
        while(front <= back){
            // ascending order, min must be nums[front]
            if(nums[front] <= nums[back]) return nums[front];
            
            int mid = front + (back - front) / 2;
            
            // not ascending order, mid >= front --> min must in right side of mid
            if(nums[mid] >= nums[front])
                front = mid+1;
            
            // not ascending order, mid < front --> min must in left side of mid
            else
                back = mid;
        }
        
        return nums[back];
    }
};