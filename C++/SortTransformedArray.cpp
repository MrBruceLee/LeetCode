class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        if(a == 0) {
            if(b > 0) {
                for(int i = 0; i < nums.size(); i++) {
                    res.push_back(b * nums[i] + c);
                }
            } else {
                for(int i = nums.size() - 1; i >= 0; i--) {
                    res.push_back(b * nums[i] + c);
                }
            }
            return res;
        }
        
        double m = -1.0 * b / (2.0 * a);
        int idx = 0;
        for(int i = idx; i < nums.size(); i++) {
            if(nums[i] > m) {
                idx = i;
                break;
            }
        }
        
        if(a > 0) {
            int l_idx = idx - 1;
            int r_idx = idx;
            
            while(res.size() < nums.size()) {
                int l_num = a * nums[l_idx] * nums[l_idx] + b * nums[l_idx] + c;
                int r_num = a * nums[r_idx] * nums[r_idx] + b * nums[r_idx] + c;
                
                if(l_idx < 0) {
                    res.push_back(r_num);
                    r_idx++;
                } else if (r_idx >= nums.size()) {
                    res.push_back(l_num);
                    l_idx--;
                } else {
                    if(l_num < r_num) {
                        res.push_back(l_num);
                        l_idx--;
                    } else {
                        res.push_back(r_num);
                        r_idx++;
                    }
                }
            }
            
        } else {
            int l_idx = 0;
            int r_idx = nums.size() - 1;
            
            while(res.size() < nums.size()) {
                int l_num = a * nums[l_idx] * nums[l_idx] + b * nums[l_idx] + c;
                int r_num = a * nums[r_idx] * nums[r_idx] + b * nums[r_idx] + c;
                
                if(l_idx > idx) {
                    res.push_back(r_num);
                    r_idx--;
                } else if (r_idx < idx) {
                    res.push_back(l_num);
                    l_idx++;
                } else {
                    if(l_num < r_num) {
                        res.push_back(l_num);
                        l_idx++;
                    } else {
                        res.push_back(r_num);
                        r_idx--;
                    }
                }
            }
        }
        
        return res;
    }
};