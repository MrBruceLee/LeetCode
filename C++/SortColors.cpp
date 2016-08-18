/*
 *  if nums[i] == 0 --> swap with nums[++red] (after swap, we definitely sure that, right now, nums[i] either equals 0 (when red == i) or 1 (when red < i). So, we do not need to check nums[i] again. It's already ordered) and increase i
 *  if nums[i] == 1 --> increase i
 *  if nums[i] == 2 --> swap with nums[--blue] (after swap, we don't know what number has been swapped into nums[i], so we need to check nums[i] again)
 *
 *  Runtime: O(N)    Space: O(1)
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = -1;
        int blue = nums.size();
        
        for(int i = 0; i < blue;){
            if(nums[i] == 0) {
                red += 1;
                swap(nums[i], nums[red]);
                i++;  // Do not omit
            }else if(nums[i] == 2){
                blue -= 1;
                swap(nums[i], nums[blue]);
            }else{
                i++;
            }
        }
    }
};