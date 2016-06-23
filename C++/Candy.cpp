class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0) {
            return 0;
        }
        
        vector<int> candy(ratings.size(), 1);
        
        /* only assign candies to increasing ratings */
        
        // from begin to end
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1]) {
                candy[i] = candy[i-1] + 1;
            }
        }
        
        // from end to begin
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candy[i] = max(candy[i], candy[i+1] + 1); // e.g. ratings   1 - 3 - 5 - 7 - 4 - 1
            }                                             //      candies   1 - 2 - 3 - 4 - 2 - 1
        }                                                 //                        max(4, 2+1) = 4
        
        // count total candies
        int totalCandies = 0;
        for(int i = 0; i < ratings.size(); i++) {
            totalCandies += candy[i];
        }
        
        return totalCandies;
    }
};