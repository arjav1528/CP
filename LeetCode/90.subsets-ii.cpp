/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.35%)
 * Likes:    10302
 * Dislikes: 363
 * Total Accepted:    1.2M
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void recurse(vector<int> nums,int index, vector<int> &ls, vector<vector<int>> &finalList){
        finalList.push_back(ls);

        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i] == nums[i-1]){
                continue;
            }else{
                ls.push_back(nums[i]);
                recurse(nums,i+1,ls,finalList);
                ls.pop_back();
            }

        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> finalList;
        vector<int> ls;

        recurse(nums,0,ls,finalList);

        return finalList;

        
    }
};
// @lc code=end

