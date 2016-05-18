/*
 *  BFS - Breadth-first search
 *
 *  e.g [2,3,1,1,4]
 *  jumps = 1, start = 0, end = 0  -  [2]
 *  jumps = 2, start = 1, end = 4  -  [3,1,1,4]
 *
 */


class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0;
        int n = nums.size();
        
        int jumps = 0;
        
        while(end < n - 1){
            jumps += 1;
            int nextEnd = end; // It does't matter what value is here, since last index is always reachable
            
            for(int i = start; i <= end; i++){
                if(i + nums[i] >= n - 1){
                    return jumps;
                }
                nextEnd = max(nextEnd, i + nums[i]);
            }
            
            start = end + 1;
            end = nextEnd;
        }
        
        return jumps;
    }
};