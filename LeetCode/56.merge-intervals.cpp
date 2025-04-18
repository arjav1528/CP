/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (48.15%)
 * Likes:    22575
 * Dislikes: 809
 * Total Accepted:    2.7M
 * Total Submissions: 5.7M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> final = {intervals[0]};
        for(int i=1;i<(intervals.size());i++){
            if(intervals[i][0] <= final[(final.size() -1)][1]){
                final[final.size()-1][0] = min(intervals[i][0],final[final.size()-1][0]);
                final[final.size()-1][1] = max(intervals[i][1],final[final.size()-1][1]);
            }
            else{
                final.push_back(intervals[i]);
            }
        }
        return final;
        
    }
};
// @lc code=end

