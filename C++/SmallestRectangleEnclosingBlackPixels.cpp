/*
 *  DFS - time complexity O(M*N) - 32ms
 */

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty() || image[0].empty()) return 0;
        
        row = image.size();
        col = image[0].size();
        
        vector<bool> r(row, false);
        vector<bool> c(col, false);
        
        dfs(x, y, r, c, image);
        
        int rowCnt = 0, colCnt = 0;
        for(auto rr : r)
            if(rr == true) rowCnt++;
        for(auto cc : c)
            if(cc == true) colCnt++;
        
        return rowCnt * colCnt;
    }
private:
    int row;
    int col;
    
    void dfs(int x, int y, vector<bool>& r, vector<bool>& c, vector<vector<char>>& image){
        if(x < 0 || x >= row || y < 0 || y >= col) return;
        if(image[x][y] == '0') return;
        
        image[x][y] = '0';
        r[x] = true;
        c[y] = true;
        
        dfs(x+1, y, r, c, image);
        dfs(x-1, y, r, c, image);
        dfs(x, y+1, r, c, image);
        dfs(x, y-1, r, c, image);
    }
};



/*
 *  Binary Search - time complexity O(M*logN + N*logM) - 24ms
 *
 *  Reference: https://leetcode.com/discuss/71898/1ms-java-binary-search-dfs-is-4ms
 *
 */

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty() || image[0].empty()) return 0;
        
        row = image.size();
        col = image[0].size();
        
        int left = binarySearch(0, y, image, row, true, true);
        int right = binarySearch(y+1, col, image, row, true, false);
        int top = binarySearch(0, x, image, col, false, true);
        int bottom = binarySearch(x+1, row, image, col, false, false);
        
        return (right-left) * (bottom-top);
    }
    
private:
    int row;
    int col;
    
    int binarySearch(int front, int back, vector<vector<char>>& image, int max, bool isRow, bool lower){
        while(front < back){
            int mid = front + (back-front) / 2;
            bool found = false;
            for(int i = 0; i < max; i++){
                if( (isRow ? image[i][mid] : image[mid][i]) == '1'){
                    found = true;
                    break;
                }
            }
            if(found == lower)
                back = mid;
            else
                front = mid + 1;
        }
        return back;
    }
};