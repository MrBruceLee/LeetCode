/*
 *  Binary Search - runtime: O(log(N))
 */


class Solution {
public:
    bool isPerfectSquare(int num) {
        int front = 0;
        int end = num;
        
        while(front <= end) {
            double mid = (end - front) / 2 + front;
            double factor = (double)num / mid;
            
            if(factor == mid) {
                return true;
            } else if (factor < mid) {
                end = mid - 1;
            } else {
                front = mid + 1;
            }
        }
        
        return false;
    }
};



/*
 *  runtime: O(sqrt(N))
 *  sqrt(N) is worse than log(N), but better than N
 */


class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 1; i <= num / i; i++) {
            if(i*i == num) {
                return true;
            }
        }
        return false;
    }
};