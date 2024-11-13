/*
 * @lc app=leetcode id=1781 lang=cpp
 *
 * [1781] Sum of Beauty of All Substrings
 *
 * https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
 *
 * algorithms
 * Medium (68.44%)
 * Likes:    1190
 * Dislikes: 183
 * Total Accepted:    77.3K
 * Total Submissions: 113K
 * Testcase Example:  '"aabcb"'
 *
 * The beauty of a string is the difference in frequencies between the most
 * frequent and least frequent characters.
 * 
 * 
 * For example, the beauty of "abaacc" is 3 - 1 = 2.
 * 
 * 
 * Given a string s, return the sum of beauty of all of its substrings.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aabcb"
 * Output: 5
 * Explanation: The substrings with non-zero beauty are
 * ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aabcbaa"
 * Output: 17
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <=^ 500
 * s consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int beauty(const std::vector<int> &mapy) {
        int mf = INT_MIN; // max frequency
        int lf = INT_MAX; // min frequency (excluding zeros)
        
        for(int i = 0; i < 26; i++) {
            if(mapy[i] > 0) {
                if(mapy[i] > mf) {
                    mf = mapy[i];
                }
                if(mapy[i] < lf) {
                    lf = mapy[i];
                }
            }
        }
        
        return (mf - lf);
    }

    int beautySum(const std::string &s) {
        int res = 0;
        
        for(int i = 0; i < s.length(); i++) {
            std::vector<int> mapy(26, 0);
            for(int j = i; j < s.length(); j++) {
                mapy[s[j] - 'a']++;
                res += beauty(mapy);
            }
        }
        
        return res;
    }
};
// @lc code=end

