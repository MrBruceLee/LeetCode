/*
 *  Runtime - O(N^3)
 */


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            for(int j = i; j < heights.size(); j++) {
                
                int h = INT_MAX;
                for(int k = i; k <= j; k++) {
                    h = min(h, heights[k]);
                }
                
                largestArea = max(largestArea, h * (j - i + 1));
            }
        }
        
        return largestArea;
    }
};



/*
 *  Runtime - O(N^2)
 */


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            
            for(int j = i; j < heights.size(); j++) {
                h = min(h, heights[j]);
                largestArea = max(largestArea, h * (j - i + 1));
            }
        }
        
        return largestArea;
    }
};



/*
 *  Runtime - O(N)
 */


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        stack<int> index;
        
        for(int i = 0; i <= heights.size(); i++) {
            int currHight = (i == heights.size() ? -1 : heights[i]);
            
            while(index.empty() == false && currHight <= heights[index.top()]) {
                
                int h = heights[index.top()];
                index.pop();
                
                int w = (index.empty() == true ? i : i - index.top() - 1);
                
                largestArea = max(largestArea, h*w);
            }
            index.push(i);
        }
        
        return largestArea;
    }
    
};