/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (44.86%)
 * Likes:    18840
 * Dislikes: 783
 * Total Accepted:    1.7M
 * Total Submissions: 3.8M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 * 
 */

// @lc code=start
class Solution {
public:

    bool mapDiff(unordered_map<char,int>& ref, unordered_map<char,int>& key){
        for(auto it : key){
            if(ref.find(it.first) == ref.end()){
                return false;
            }else{
                if(ref[it.first] < it.second){
                    return false;
                }
            }
        }
        return true;
    }


    string minWindow(string s, string t) {

        if(s.length() > t.length()){
        }else if(s.length() == t.length()){
            s = s;
            t = t;
            unordered_map<char,int> hasht;
            unordered_map<char,int> hashs;
            
            for(int i=0;i<t.length();i++){
                hasht[t[i]]++;
            }
            for(int i=0;i<s.length();i++){
                hashs[s[i]]++;
            }

            if(mapDiff(hashs,hasht)){
                return s;
            }else{
                return "";
            }
            
        }else{
            return "";
        }

        unordered_map<char,int> hasht;
        unordered_map<char,int> hashs;
        
        for(int i=0;i<t.length();i++){
            hasht[t[i]]++;
        }
        string minString = "";

        int left = 0;
        int right = 0;

        while(right < s.size()){
            hashs[s[right]]++;
            while(mapDiff(hashs,hasht)){
                if(minString == ""){
                    minString = s.substr(left,(right-left+1));
                }else{
                    if(right - left + 1 < minString.length()){
                        minString = s.substr(left,(right-left+1));
                    }
                }
                hashs[s[left]]--;
                if(hashs[s[left]] == 0){
                    hashs.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return minString;  
    }

};
// @lc code=end

