/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (59.15%)
 * Likes:    10006
 * Dislikes: 577
 * Total Accepted:    985.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 * 
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<int> dp = {triangle[0][0]};

        for(int i=1;i<triangle.size();i++){
            vector<int> temp(i+1,0);

            for(int j=0;j<i+1;j++){
                if(j == 0){
                    temp[j] = triangle[i][j] + dp[j];
                }else if(j==i){
                    temp[j] = triangle[i][j] + dp[j-1];
                }else{
                    temp[j] = triangle[i][j] + min(dp[j],dp[j-1]);
                }
            }

            dp = temp;
        }

        return *min_element(dp.begin(),dp.end());
            
    }
};
// @lc code=end

