/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (80.43%)
 * Likes:    18126
 * Dislikes: 304
 * Total Accepted:    2.5M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> finalList;
    vector<int> ls;

    for(int i=0;i<pow(2,nums.size());i++){

        ls = {};
        for(int j=0;j<nums.size();j++){
            if(i & (1<<j)){
                ls.push_back(nums[j]);
            }
        }

        finalList.push_back(ls);

    }

    return finalList;
        
}
};
// @lc code=end

