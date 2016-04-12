/*
 *  unordered_set is implemented by hash table, so time complex of “insert”, "find", and "erase" are O(1)
 *
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        // insert each element in nums into the unordered_set -> O(N)
        st.insert(nums.begin(), nums.end());
        
        int lenght = 0;
        for(int i = 0; i < nums.size(); i++){
            if(st.size() <= 0) break;
            
            int currLen = 0;
            
            // find nums[i], nums[i]+1, nums[i]+2, ...
            int currNum = nums[i];
            while(st.count(currNum) == 1){ // since no duplication, count equals either 1 or 0
                currLen++;
                st.erase(currNum); // erase each time
                currNum++;
            }
            
            // find nums[i]-1, nums[i]-2, nums[i-3], ...
            currNum = nums[i]-1;
            while(st.count(currNum) == 1){ // since no duplication, count equals either 1 or 0
                currLen++;
                st.erase(currNum); // erase each time
                currNum--;
            }
            
            // maintian the max length of sequence
            lenght = max(lenght, currLen);
        }
        
        return lenght;
    }
};
