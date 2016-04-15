/*
 *  Binary Search
 *
 *  Runtime - approximately: O(N*logN)    vector insertion: linear time complexity
 *  Space - O(N)
 *
 */


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted; // maintain an sorted array of numbers have been visited
        vector<int> res(nums.size(), 0); // the results
        
        for(int i = nums.size()-1; i >= 0; i--){
            int idx = findIdx(sorted, nums[i]);
            res[i] = idx;
            sorted.insert(sorted.begin()+idx, nums[i]);
        }
        
        return res;
    }
    
private:
    // binary search
    // find the first element in the sorted array which is larger or equal to target number
    int findIdx(vector<int>& sorted, int target){
        if(sorted.size() == 0) return 0;
        
        int front = 0;
        int back = sorted.size() - 1;
        
        if(sorted[front] > target) return 0;
        if(sorted[back] < target) return sorted.size();
        
        while(front + 1 < back){
            int mid = front + (back - front) / 2;
            
            if(sorted[mid] < target)
                front = mid + 1;
            else
                back = mid;
        }
        
        if(sorted[front] >= target) return front;
        else return back;
    }
};