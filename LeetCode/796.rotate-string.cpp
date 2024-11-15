 /*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 *
 * https://leetcode.com/problems/rotate-string/description/
 *
 * algorithms
 * Easy (63.08%)
 * Likes:    4200
 * Dislikes: 286
 * Total Accepted:    518.1K
 * Total Submissions: 821.3K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * Given two strings s and goal, return true if and only if s can become goal
 * after some number of shifts on s.
 * 
 * A shift on s consists of moving the leftmost character of s to the rightmost
 * position.
 * 
 * 
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 * 
 * 
 * 
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        string str = s + s;
        return (str.find(goal)<str.length());
        
    }
};
// @lc code=end

