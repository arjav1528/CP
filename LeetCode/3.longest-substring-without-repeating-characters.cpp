/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (36.51%)
 * Likes:    41871
 * Dislikes: 2027
 * Total Accepted:    7.4M
 * Total Submissions: 20.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without duplicate
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        int left = 0;
        int right = 0;
        unordered_map<char, int> charMap;
        int maxLen = 0;

        while(right < s.length()) {
            if (charMap.find(s[right]) != charMap.end() && charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }
            
            maxLen = max(maxLen, right - left + 1);
            
            charMap[s[right]] = right;
            
            right++;
        }

        return maxLen;
    }
};
// @lc code=end

