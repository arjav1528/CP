/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (44.14%)
 * Likes:    18203
 * Dislikes: 4627
 * Total Accepted:    3.9M
 * Total Submissions: 8.8M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = INT_MAX;
        // int mini = -1;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size() < min){
                min = strs[i].size();
                // mini = i;  
            }
        }
        string str = "";
        string temp = "";
        if(strs.size()==1){
            return strs[0];
        }
        for(int i=0;i<min;i++){
            for(int j=1;j<strs.size();j++){
                temp = strs[j][i];
                
                if(strs[j][i] == strs[j-1][i]){
                    
                    continue;
                }
                else{
                    return str;
                }
            }
            str += temp;

        }
        return str;

        
    }
};
// @lc code=end

