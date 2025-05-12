/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.71%)
 * Likes:    22078
 * Dislikes: 1029
 * Total Accepted:    2.3M
 * Total Submissions: 3M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void solve(string op, int open, int close, vector<string> &ans){
        if(open == 0 && close == 0){

            ans.push_back(op);
            return;
        }else if(open == close){
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }else if(open == 0){
            string op1 = op;
            op1.push_back(')');
            solve(op1, open, close-1, ans);
        }else if(close == 0){
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, open-1, close, ans);
            solve(op2, open, close-1, ans);

        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op = "";
        solve(op, open, close, ans);
        return ans;

        
    }
    
};
// @lc code=end

