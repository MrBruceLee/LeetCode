class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        double median = 0;
        
        if(len % 2 == 1) {
            median = findKth(nums1, nums2, 0, 0, len / 2 + 1);
        } else {
            median = (findKth(nums1, nums2, 0, 0, len / 2) + findKth(nums1, nums2, 0, 0, len / 2 + 1)) / 2.0;
        }
        
        return median;
    }
    
private:
    double findKth(vector<int>& nums1, vector<int>& nums2, int p1, int p2, int k) {
        if(p1 >= nums1.size()) {
            return nums2[p2 + k - 1];
        }
        if(p2 >= nums2.size()) {
            return nums1[p1 + k - 1];
        }
        
        if(k == 1) {
            return min(nums1[p1], nums2[p2]);
        }
        
        int key1 = p1 + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[p1 + k / 2 - 1];
        int key2 = p2 + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[p2 + k / 2 - 1];
        
        if(key1 < key2) {
            return findKth(nums1, nums2, p1 + k / 2, p2, k - k / 2);
        } else {
            return findKth(nums1, nums2, p1, p2 + k / 2, k - k / 2);
        }
        
    }
};