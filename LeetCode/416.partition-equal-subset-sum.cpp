/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (48.37%)
 * Likes:    13226
 * Dislikes: 283
 * Total Accepted:    1.2M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given an integer array nums, return true if you can partition the array into
 * two subsets such that the sum of the elements in both subsets is equal or
 * false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool subsetSumtoX(int n, int k, vector<int> &arr) {
        if (n == 0) return false;
        if (k == 0) return true;
        
        vector<bool> dp(k+1, false), cur(k+1, false);
        
        dp[0] = true;  
        cur[0] = true;
        
        if (arr[0] <= k) {
            dp[arr[0]] = true;
        }
        
        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[target];
                bool take = false;
                if (arr[index] <= target) {
                    take = dp[target - arr[index]];
                }
                cur[target] = take | notTake;
            }
            dp = cur;
        }
        
        return dp[k];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        if (sum % 2 != 0) {
            return false;
        }
        
        return subsetSumtoX(nums.size(), sum / 2, nums);
    }
};
// @lc code=end

