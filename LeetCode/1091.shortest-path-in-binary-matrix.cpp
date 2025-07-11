/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (49.78%)
 * Likes:    7039
 * Dislikes: 267
 * Total Accepted:    697.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * Given an n x n binary matrix grid, return the length of the shortest clear
 * path in the matrix. If there is no clear path, return -1.
 * 
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0,
 * 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
 * 
 * 
 * All the visited cells of the path are 0.
 * All the adjacent cells of the path are 8-directionally connected (i.e., they
 * are different and they share an edge or a corner).
 * 
 * 
 * The length of a clear path is the number of visited cells of this path.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1],[1,0]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }
        
        if(n == 1 && m == 1) {
            return 1;
        }

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1; 

        vector<int> delRow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> delCol = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, int>> q; 
        q.push({0, 0});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                grid[nrow][ncol] == 0 && dist[row][col] + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        return dist[n-1][m-1] == 1e9 ? -1 : dist[n-1][m-1];
    }
};
// @lc code=end

