/*
 * @lc app=leetcode id=1922 lang=cpp
 *
 * [1922] Count Good Numbers
 *
 * https://leetcode.com/problems/count-good-numbers/description/
 *
 * algorithms
 * Medium (47.33%)
 * Likes:    1564
 * Dislikes: 464
 * Total Accepted:    90.9K
 * Total Submissions: 192K
 * Testcase Example:  '1'
 *
 * A digit string is good if the digits (0-indexed) at even indices are even
 * and the digits at odd indices are prime (2, 3, 5, or 7).
 * 
 * 
 * For example, "2582" is good because the digits (2 and 8) at even positions
 * are even and the digits (5 and 2) at odd positions are prime. However,
 * "3245" is not good because 3 is at an even index but is not even.
 * 
 * 
 * Given an integer n, return the total number of good digit strings of length
 * n. Since the answer may be large, return it modulo 10^9 + 7.
 * 
 * A digit string is a string consisting of digits 0 through 9 that may contain
 * leading zeros.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 5
 * Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4
 * Output: 400
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 50
 * Output: 564908303
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^15
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int M = 1e9 + 7;
    long long power(long long b,long long e,long long ans){
        if(e==0){
            return ans;
        }
        if(e&1){
            return power(b,e-1,(ans*b)%M);
        }
        else{
            return power((b*b)%M,e/2,ans);
        }
    }
    int countGoodNumbers(long long n) {
        long long temp = power(20,n/2,1);
        return (n&1) ? (temp*5)%M : temp;        
        
    }
};
// @lc code=end

