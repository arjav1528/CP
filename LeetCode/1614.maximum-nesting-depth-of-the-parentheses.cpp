/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 *
 * https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
 *
 * algorithms
 * Easy (84.01%)
 * Likes:    2507
 * Dislikes: 508
 * Total Accepted:    386.4K
 * Total Submissions: 459.9K
 * Testcase Example:  '"(1+(2*3)+((8)/4))+1"'
 *
 * Given a valid parentheses string s, return the nesting depth of s. The
 * nesting depth is the maximum number of nested parentheses.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(1+(2*3)+((8)/4))+1"
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * Digit 8 is inside of 3 nested parentheses in the string.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "(1)+((2))+(((3)))"
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * Digit 3 is inside of 3 nested parentheses in the string.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "()(())((()()))"
 * 
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and
 * ')'.
 * It is guaranteed that parentheses expression s is a VPS.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int balance = 0;
        int max_balance = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                balance++;
            }
            else if(s[i]==')'){
                balance--;
            }
            max_balance = balance>max_balance ? balance : max_balance;
        }
        return max_balance;
        
    }
};
// @lc code=end

