/*
 *  Explanations:
 *  https://leetcode.com/discuss/79083/share-my-solution
 *
 */

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        }
        
        vector<long> sums(len + 1, 0);
        for(int i = 0; i < len; i++){
            sums[i+1] = sums[i] + nums[i];
        }
        
        return countWhileMergeSort(sums, 0, len+1, lower, upper);
    }
    
private:
    int countWhileMergeSort(vector<long>& sums, int start, int end, int lower, int upper){
        if(end - start <= 1) {
            return 0;
        }
        
        int mid = (end - start) / 2 + start;
        int cnt = countWhileMergeSort(sums, start, mid, lower, upper) + countWhileMergeSort(sums, mid, end, lower, upper);
        
        int l = mid, u = mid, s = mid; // lower, upper, sort
        int len = 0;
        vector<long> cache(end - start, 0);
        for(int i = start, j = 0; i < mid; i++, j++){
            while(l < end && sums[l] - sums[i] < lower) {
                l++;
            }
            while(u < end && sums[u] - sums[i] <= upper) {
                u++;
            }
            while(s < end && sums[s] < sums[i]) {
                cache[j++] = sums[s++];
            }
            cache[j] = sums[i];
            
            cnt += u - l;
            len = j;
        }
        
        for(int i = 0; i <= len; i++) {
            sums[start + i] = cache[i];
        }
        
        return cnt;
    }
};