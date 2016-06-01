class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() < 1){
            return 0;
        }
        
        heights.push_back(0);
        int area = 0;
        stack<int> index;
        
        for(int i = 0; i < heights.size(); i++){
            
            while(index.empty() == false && heights[index.top()] > heights[i]){
                int h = heights[index.top()];
                index.pop();
                
                int l = -1;
                if(index.empty() == false){
                    l = index.top();
                }
                
                area = max(area, h * ((i-1) - l));
            }
            
            index.push(i);
        }
        
        return area;
    }
};