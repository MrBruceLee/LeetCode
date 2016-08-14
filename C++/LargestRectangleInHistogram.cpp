class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        stack<int> index;
        
        for(int i = 0; i <= heights.size(); i++) {
            int currHight = (i == heights.size() ? 0 : heights[i]);
            
            while(index.empty() == false && currHight <= heights[index.top()]) {
                
                int h = heights[index.top()];
                index.pop();
                
                int w = index.empty() == true ? i : i - index.top() - 1;
                
                largestArea = max(largestArea, h*w);
            }
            index.push(i);
        }
        
        return largestArea;
    }
    
};