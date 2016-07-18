public class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        // runtime - O(N*log(N))
        Arrays.sort(nums);
        
        int count = 0;
        
        // runtime - O(N^2)
        for(int i = 0; i < nums.length; i++) {
            int front = i + 1;
            int end = nums.length - 1;
            
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
}