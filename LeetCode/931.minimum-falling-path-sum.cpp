/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (61.56%)
 * Likes:    6664
 * Dislikes: 165
 * Total Accepted:    550.1K
 * Total Submissions: 893.6K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 * 
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is shown.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> dp(n,0), cur(n,0);

        dp = matrix[0];
        int s;
        int r;
        int l;

        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                s = matrix[i][j] + dp[j];
                r = (j<=matrix.size()-2) ? matrix[i][j] + dp[j+1] : INT_MAX;
                l = (j>=1) ? matrix[i][j] + dp[j-1] : INT_MAX;

                cur[j] = min(s,min(l,r));

            }
            dp = cur;
        }

        return *min_element(dp.begin(),dp.end());
        
    }
};
// @lc code=end

