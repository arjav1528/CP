/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (36.08%)
 * Likes:    10219
 * Dislikes: 9869
 * Total Accepted:    2M
 * Total Submissions: 5.5M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * n is an integer.
 * Either x is not zero or n > 0.
 * -10^4 <= x^n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    double fastPow(double x, long n) {
        // Base cases
        if (n == 0) return 1;
        if (n == 1) return x;
        
        // Even power: use square
        if (n % 2 == 0) {
            double half = fastPow(x, n/2);
            return half * half;
        }
        
        // Odd power: x * x^(n-1)
        return x * fastPow(x, n-1);
    }
    
public:
    double myPow(double x, int n) {
        long N = n; // Handle INT_MIN case
        
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        
        return fastPow(x, N);
    }
};
// @lc code=end

