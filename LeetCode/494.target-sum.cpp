/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (50.69%)
 * Likes:    11839
 * Dislikes: 392
 * Total Accepted:    887.6K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given an integer array nums and an integer target.
 * 
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the
 * integers.
 * 
 * 
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1".
 * 
 * 
 * Return the number of different expressions that you can build, which
 * evaluates to target.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be
 * target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], target = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int zeroCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
            if(nums[i] == 0) zeroCount++;
        }
        
        if(abs(target) > totalSum) return 0;
        
        if((totalSum - target) % 2 != 0) return 0;
        
        int sum = (totalSum + target) / 2;
        if(sum < 0) return 0;
        
        vector<int> nonZeroNums;
        for(int num : nums) {
            if(num != 0) nonZeroNums.push_back(num);
        }
        
        int n = nonZeroNums.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        
        prev[0] = 1;
        
        if(n > 0 && nonZeroNums[0] <= sum) {
            prev[nonZeroNums[0]] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= sum; j++) {
                int notTake = prev[j];
                int take = 0;
                if(nonZeroNums[i] <= j) {
                    take = prev[j - nonZeroNums[i]];
                }
                curr[j] = notTake + take;
            }
            prev = curr;
        }
        
        return prev[sum] * (1 << zeroCount);
    }
};
// @lc code=end

