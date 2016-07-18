/*
 *  Runtime - add O(1), find O(N)
 *  Space - O(N)
 */


class TwoSum {
public:
    
    // Add the number to an internal data structure.
    void add(int number) {
        nums[number] += 1;
    }
    
    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for(auto& e : nums) {
            int diff = value - e.first;
            
            if( (diff == e.first && e.second > 1)  || (diff != e.first && nums.find(diff) != nums.end()) ) {
                return true;
            }
        }
        return false;
    }
    
private:
    unordered_map<int, int> nums;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);