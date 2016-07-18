public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        // runtime - O(N*log(N))
        Arrays.sort(nums);
        
        int diff = Integer.MAX_VALUE;
        
        // runtime - (N^2)
        for(int i = 0; i < nums.length; i++) {
            int front = i + 1;
            int end = nums.length - 1;
            
            while(front < end) {
                int sum = nums[i] + nums[front] + nums[end];
                
                if(Math.abs(sum - target) < Math.abs(diff)) {
                    diff = sum - target;
                }
                
                if(sum < target) {
                    front++;
                } else if (sum > target) {
                    end--;
                } else {
                    return target;
                }
            }
        }
        
        return target + diff;
    }
}
