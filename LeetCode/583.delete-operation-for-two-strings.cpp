/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (63.64%)
 * Likes:    5972
 * Dislikes: 90
 * Total Accepted:    317K
 * Total Submissions: 498.1K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings word1 and word2, return the minimum number of steps
 * required to make word1 and word2 the same.
 * 
 * In one step, you can delete exactly one character in either string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "sea", word2 = "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "leetcode", word2 = "etco"
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 500
 * word1 and word2 consist of only lowercase English letters.
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
                }else{
                    cur[j] = max(dp[j],cur[j-1]);
                }
            }
            dp = cur;
        }

        return dp[m];
            
    }
    int minDistance(string word1, string word2) {
        int f = longestCommonSubsequence(word1,word2);
        int first = word1.length() - f;
        int second = word2.length() - f;

        return first+second;
        
        
    }
};
// @lc code=end

