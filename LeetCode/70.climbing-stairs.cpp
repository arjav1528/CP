/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (53.51%)
 * Likes:    23153
 * Dislikes: 957
 * Total Accepted:    4.2M
 * Total Submissions: 7.9M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    


    int climbStairs(int n) {

        if(n==1) return 1;
        if(n==2) return 2;
        int prev1 = 1;
        int prev2 = 1;
        int num = -1;


        for(int i=2;i<=n;i++){
            num = prev1 + prev2;
            prev2 = prev1;
            prev1 = num;
        }

        return num;

        
            
            
    }
};
// @lc code=end

