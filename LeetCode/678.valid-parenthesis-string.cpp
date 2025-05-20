/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (38.81%)
 * Likes:    6527
 * Dislikes: 204
 * Total Accepted:    468.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing only three types of characters: '(', ')' and
 * '*', return true if s is valid.
 * 
 * The following rules define a valid string:
 * 
 * 
 * Any left parenthesis '(' must have a corresponding right parenthesis
 * ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis
 * '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis
 * ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string "".
 * 
 * 
 * 
 * Example 1:
 * Input: s = "()"
 * Output: true
 * Example 2:
 * Input: s = "(*)"
 * Output: true
 * Example 3:
 * Input: s = "(*))"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s[i] is '(', ')' or '*'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                cmax++;
                cmin++;
            }else if(s[i] == ')'){
                cmax--;
                cmin--;
            }else{
                cmin--;
                cmax++;
            }

            if(cmin<0){
                cmin=0;
            }
            if(cmax < 0){
                return false;
            }
        }

        if(cmin <= 0 && 0 <= cmax){
            return true;
        }else{
            return false;
        }
            
    }
};
// @lc code=end

