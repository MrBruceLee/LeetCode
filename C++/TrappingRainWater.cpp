/*
 *  Runtime - O(N)
 *  Space - O(N)
 *
 *  Has better solution: O(1) space
 *
 */


class Solution {
public:
    int trap(vector<int>& height) {
        // the min height between "the max height among bars on the left of i" &  "the max height among bars on the right of i"
        vector<int> container(height.size());
        
        int maxHight = 0; // max hight: from left to right
        for(int i = 0; i < height.size(); i++){
            container[i] = maxHight;
            maxHight = max(maxHight, height[i]);
        } // now value in the container -> the max height among bars on the left of i
        
        int water = 0; // total water that can be trapped
        
        maxHight = 0; // max hight: from right to left
        for(int i = height.size()-1; i >= 0; i--){
            container[i] = min(container[i], maxHight); // now value in the container -> the min height between...
            maxHight = max(maxHight, height[i]);
            
            // if container[i] is greater than height[i], the difference is how much water it can trap
            if(container[i] > height[i])
                water += container[i] - height[i];
        }
        
        return water;
    }
};