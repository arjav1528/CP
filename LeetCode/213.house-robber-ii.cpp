/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (43.48%)
 * Likes:    10469
 * Dislikes: 171
 * Total Accepted:    996.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 * 
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int robans(vector<int>& nums) {
        
        vector<int> dp(nums.size(),0);

        dp[0] = nums[0];
        int pick = -1;
        int notpick = -1;

        for(int i=1;i<nums.size();i++){
          pick = nums[i];
          if(i>1){
            pick+=dp[i-2];
          }
          notpick = dp[i-1];

          dp[i] = max(pick,notpick);
        }


        return dp[nums.size()-1];
        
    }
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];

        int num = nums[nums.size()-1];
        nums.pop_back();
        
        int ans1 = robans(nums);

        nums.push_back(num);

        nums.erase(nums.begin());

        int ans2 = robans(nums);

        return max(ans1,ans2);
        
    }
};
// @lc code=end

