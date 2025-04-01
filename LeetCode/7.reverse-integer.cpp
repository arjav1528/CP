/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (29.96%)
 * Likes:    13958
 * Dislikes: 13744
 * Total Accepted:    3.9M
 * Total Submissions: 13.1M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 120
 * Output: 21
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int reverse(long long x) {
        if(x >= INT_MAX || x< INT_MIN){
            return 0;
        }else{
            bool neg = false;
            if(x < 0){
                x *= -1;
                neg = true;


            }
            long long num = 0;
            long long temp = x;
            while(temp > 0){
                int rem = temp%10;
                if(10*num > INT_MAX){
                    return 0;
                }
                num = 10*num + rem;
                temp = temp/10;
                
            }
            if(neg){
                return num*-1;
            }else{
                return num;
            }
        }
        
    }
};
// @lc code=end

