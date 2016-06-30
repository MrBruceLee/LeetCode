class NumArray {
public:
    NumArray(vector<int> &nums) {
        // nums = [-2, 0, 3, -5, 2, -1]
        // sum  = [0, -2, -2, 1, -4, -2, -3]
        sum.push_back(0);
        for(int i = 0; i < nums.size(); i++) {
            sum.push_back(sum.back() + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
    
private:
    vector<int> sum;
};