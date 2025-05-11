/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 *
 * https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
 *
 * algorithms
 * Medium (72.97%)
 * Likes:    4046
 * Dislikes: 71
 * Total Accepted:    323.9K
 * Total Submissions: 443.3K
 * Testcase Example:  '"abcabc"'
 *
 * Given a string s consisting only of characters a, b and c.
 * 
 * Return the number of substrings containing at least one occurrence of all
 * these characters a, b and c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabc"
 * Output: 10
 * Explanation: The substrings containing at least one occurrence of the
 * characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab",
 * "bcabc", "cab", "cabc" and "abc" (again). 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaacb"
 * Output: 3
 * Explanation: The substrings containing at least one occurrence of the
 * characters a, b and c are "aaacb", "aacb" and "acb". 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abc"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= s.length <= 5 x 10^4
 * s only consists of a, b or c characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> hashMap(3,-1);

        int count = 0;

        for(int i=0;i<s.length();i++){
            hashMap[s[i] - 'a'] = i;

            if(hashMap[0] != -1 && hashMap[1] != -1 && hashMap[2] != -1){
                count += 1 + min(hashMap[0],min(hashMap[1],hashMap[2]));
            }
        }

        return count;

        
    }
};
// @lc code=end

