class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum.push_back(0);
        for(int num : nums)
            sum.push_back(sum.back() + num);
    }
    
    void update(int i, int val) {
        int diff = sumRange(i, i) - val;
        for(int j = i+1; j < sum.size(); j++)
            sum[j] -= diff;
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
private:
    vector<int> sum;
};


/*
 *  Optimal solution - Segment Tree
 *  https://leetcode.com/articles/range-sum-query-mutable/
 */

class NumArray {
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        if(n > 0) {
            segmentTree.resize(nums.size() * 2);
            for(int i = n, j = 0; i < 2 * n; i++, j++) {
                segmentTree[i] = nums[j];
            }
            for(int i = n - 1; i > 0; i--) {
                segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
            }
        }
        
    }
    
    void update(int i, int val) {
        int pos = i + n;
        segmentTree[pos] = val;
        while(pos > 0) {
            int left, right;
            if(pos % 2 == 0) {
                left = pos;
                right = pos + 1;
            } else {
                left = pos - 1;
                right = pos;
            }
            segmentTree[pos / 2] = segmentTree[left] + segmentTree[right];
            pos = pos / 2;
        }
    }
    
    int sumRange(int i, int j) {
        int l = i + n;
        int r = j + n;
        int sum = 0;
        while(l <= r) {
            if((l % 2) == 1) {
                sum += segmentTree[l];
                l++;
            }
            if((r % 2) == 0) {
                sum += segmentTree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
    
private:
    vector<int> segmentTree;
    int n = 0;
};