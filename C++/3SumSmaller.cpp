class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // runtime - O(N*log(N))
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        // runtime - O(N^2)
        for(int i = 0; i < nums.size(); i++) {
            int front = i + 1;
            int end = nums.size() - 1;
            
            while(front < end) {
                if(nums[i] + nums[front] + nums[end] < target) {
                    count += end - front;
                    front++;
                    
                } else {
                    end--;
                }
            }
        }
        
        return count;
    }
};