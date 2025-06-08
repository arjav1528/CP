/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 *
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (72.33%)
 * Likes:    5322
 * Dislikes: 70
 * Total Accepted:    237.1K
 * Total Submissions: 327.8K
 * Testcase Example:  '"zzazz"'
 *
 * Given a string s. In one step you can insert any character at any index of
 * the string.
 * 
 * Return the minimum number of steps to make s palindrome.
 * 
 * A Palindrome String is one that reads the same backward as well as
 * forward.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we do not need any
 * insertions.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
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
    int minInsertions(string s) {

        return s.size()- longestPalindromeSubseq(s);
        
    }
};
// @lc code=end

