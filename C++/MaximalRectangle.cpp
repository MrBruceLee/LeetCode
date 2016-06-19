/*
 *  Reference: https://leetcode.com/discuss/20240/share-my-dp-solution
 */


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() == true || matrix[0].empty() == true) {
            return 0;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> left(col, 0);
        vector<int> right(col, col);
        vector<int> height(col, 0);
        
        int maxArea = 0;
        for(int i = 0; i < row; i++) {
            int curr_left = 0;
            int curr_right = col;
            
            // compute left
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], curr_left);
                } else {
                    left[j] = 0;
                    curr_left = j + 1;
                }
            }
            
            // compute right
            for(int j = col - 1; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], curr_right);
                } else {
                    right[j] = col;
                    curr_right = j;
                }
            }
            
            // compute height
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            // compute maxArea
            for(int j = 0; j < col; j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        
        return maxArea;
    }
};