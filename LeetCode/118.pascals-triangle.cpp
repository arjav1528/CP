#include<bits/stdc++.h>
/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (75.66%)
 * Likes:    13179
 * Dislikes: 474
 * Total Accepted:    1.9M
 * Total Submissions: 2.5M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numRows <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==1){
            ans.push_back({1});
        }
        else if(numRows==2){
            ans.push_back({1});
            ans.push_back({1,1});
        }
        else{
            ans.push_back({1});
            ans.push_back({1,1});
            for(int i=3;i<=numRows;i++){
                vector<int> temp(i,1);
                for(int j=1;j<=(i-2);j++){
                    temp[j] = ans[ans.size()-1][j-1] + ans[ans.size()-1][j];
                }
            ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
// @lc code=end

