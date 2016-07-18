/*
 *  Can be solved by the same idea of "1. Two Sum" ( https://leetcode.com/problems/two-sum/ ).
 *  Hash Map:   Runtime - O(N)   Space - O(N)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int front = 0;
        int end = numbers.size() - 1;
        
        while(front < end) {
            if(numbers[front] + numbers[end] > target) {
                end--;
            } else if (numbers[front] + numbers[end] < target) {
                front++;
            } else {
                result.push_back(front + 1);
                result.push_back(end + 1);
                // since the answer is unique, we can return here
                return result;
            }
        }
        
        return result;
    }
};


/*
 *  Two Pointers:   Runtime - O(N)   Space - O(1)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int front = 0;
        int end = numbers.size() - 1;
        
        while(front < end) {
            if(numbers[front] + numbers[end] > target) {
                end--;
            } else if (numbers[front] + numbers[end] < target) {
                front++;
            } else {
                result.push_back(front + 1);
                result.push_back(end + 1);
                // since the answer is unique, we can return here
                return result;
            }
        }
        
        return result;
    }
};