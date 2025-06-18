/*
 * @lc app=leetcode id=931 lang=java
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
    public int minFallingPathSum(int[][] matrix) {
        
        int n = matrix.length;
        int[] dp = new int[n];
        int[] cur = new int[n];
        System.arraycopy(matrix[0], 0, dp, 0, n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int s = matrix[i][j] + dp[j];
                int r = (j < n - 1) ? matrix[i][j] + dp[j + 1] : Integer.MAX_VALUE;
                int l = (j >= 1) ? matrix[i][j] + dp[j - 1] : Integer.MAX_VALUE;
                cur[j] = Math.min(s, Math.min(l, r));
            }
            System.arraycopy(cur, 0, dp, 0, n);
        }
        int minSum = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            minSum = Math.min(minSum, dp[j]);
        }
        return minSum;
    }
}
// @lc code=end

