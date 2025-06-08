/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (64.04%)
 * Likes:    9957
 * Dislikes: 335
 * Total Accepted:    623.7K
 * Total Submissions: 973.9K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * 
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "bbbab"
 * Output: 4
 * Explanation: One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: 2
 * Explanation: One possible longest palindromic subsequence is "bb".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    // return recurse(text1.length()-1,text2.length()-1,text1,text2);
        int m = text1.length();
        int n = text2.length();
        vector<int> dp(m+1,0),cur(m+1,0);
        

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[j-1] == text2[i-1]){
                    cur[j] = 1 + dp[j-1];
                    // ans = ans + text1[j-1];
                }else{
                    cur[j] = max(dp[j],cur[j-1]);
                }
            }
            dp = cur;
        }

        return dp[m];
            
    }

    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(),t.end());

        return longestCommonSubsequence(s,t);
            
            
    }
};
// @lc code=end

