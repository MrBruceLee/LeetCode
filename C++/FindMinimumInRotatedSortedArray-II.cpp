/*
 *  Binary Search - runtime O(logN) - space O(1)
 *
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int back = nums.size() - 1;
        
        while(front < back){
            int mid = front + (back - front) / 2;
            
            if(nums[mid] > nums[back])
                front = mid + 1;
            else if(nums[mid] < nums[back])
                back = mid;
            else
                back--;
        }
        
        return nums[front];
    }
};