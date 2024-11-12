/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.57%)
 * Likes:    12450
 * Dislikes: 414
 * Total Accepted:    4.1M
 * Total Submissions: 6.3M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * 
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * 
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string str, string t) {
        if(str.size() != t.size()){
            return false;
        }
        map<char,int> mpp1;
        map<char,int> mpp2;
        for(int i=0;i<s.size();i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        auto it1 = mpp1.begin();
        auto it2 = mpp2.begin();
        while((it1 != mpp1.end()) && (it2 != mpp2.end())){
            if((it1->first == it2->first) && (it1->second == it2->second)){
                it1++;
                it2++;
                continue;
            }
            else{
                return false;
            }
    
        }
        return true;
        
    }
};
// @lc code=end

