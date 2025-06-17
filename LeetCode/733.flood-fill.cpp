/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (66.45%)
 * Likes:    8935
 * Dislikes: 919
 * Total Accepted:    1.2M
 * Total Submissions: 1.8M
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * You are given an image represented by an m x n grid of integers image, where
 * image[i][j] represents the pixel value of the image. You are also given
 * three integers sr, sc, and color. Your task is to perform a flood fill on
 * the image starting from the pixel image[sr][sc].
 * 
 * To perform a flood fill:
 * 
 * 
 * Begin with the starting pixel and change its color to color.
 * Perform the same process for each pixel that is directly adjacent (pixels
 * that share a side with the original pixel, either horizontally or
 * vertically) and shares the same color as the starting pixel.
 * Keep repeating this process by checking neighboring pixels of the updated
 * pixels and modifying their color if it matches the original color of the
 * starting pixel.
 * The process stops when there are no more adjacent pixels of the original
 * color to update.
 * 
 * 
 * Return the modified image after performing the flood fill.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
 * 
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * 
 * Explanation:
 * 
 * 
 * 
 * From the center of the image with position (sr, sc) = (1, 1) (i.e., the red
 * pixel), all pixels connected by a path of the same color as the starting
 * pixel (i.e., the blue pixels) are colored with the new color.
 * 
 * Note the bottom corner is not colored 2, because it is not horizontally or
 * vertically connected to the starting pixel.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
 * 
 * Output: [[0,0,0],[0,0,0]]
 * 
 * Explanation:
 * 
 * The starting pixel is already colored with 0, which is the same as the
 * target color. Therefore, no changes are made to the image.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == image.length
 * n == image[i].length
 * 1 <= m, n <= 50
 * 0 <= image[i][j], color < 2^16
 * 0 <= sr < m
 * 0 <= sc < n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void recurse( int nrow, int ncol, vector<vector<int>> &image, vector<vector<int>> &visible, vector<int> drow, vector<int> dcol,int color, int initial){

        for(int i=0;i<4;i++){
            int r = nrow + drow[i];
            int c = ncol + dcol[i];

            if(r>=0 && r<image.size() && c>=0 && c<image[0].size() && visible[r][c]!=color && image[r][c] == initial){
                image[r][c] = color;
                visible[r][c] = color;
                recurse(r,c,image,visible,drow,dcol,color, initial);
            }

        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visible(image.size(), vector<int> (image[0].size(), 0));
        int initial = image[sr][sc];
        visible[sr][sc] = color;
        image[sr][sc] = color;
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        recurse(sr,sc,image,visible,drow,dcol,color, initial);

        return image;
    }
};

// @lc code=end

