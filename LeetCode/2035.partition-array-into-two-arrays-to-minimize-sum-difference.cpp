/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 *
 * https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
 *
 * algorithms
 * Hard (21.68%)
 * Likes:    3413
 * Dislikes: 224
 * Total Accepted:    41.4K
 * Total Submissions: 190.8K
 * Testcase Example:  '[3,9,7,3]'
 *
 * You are given an integer array nums of 2 * n integers. You need to partition
 * nums into two arrays of length n to minimize the absolute difference of the
 * sums of the arrays. To partition nums, put each element of nums into one of
 * the two arrays.
 * 
 * Return the minimum possible absolute difference.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,9,7,3]
 * Output: 2
 * Explanation: One optimal partition is: [3,9] and [7,3].
 * The absolute difference between the sums of the arrays is abs((3 + 9) - (7 +
 * 3)) = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-36,36]
 * Output: 72
 * Explanation: One optimal partition is: [-36] and [36].
 * The absolute difference between the sums of the arrays is abs((-36) - (36))
 * = 72.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,-1,0,4,-2,-9]
 * Output: 0
 * Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
 * The absolute difference between the sums of the arrays is abs((2 + 4 + -9) -
 * (-1 + 0 + -2)) = 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 15
 * nums.length == 2 * n
 * -10^7 <= nums[i] <= 10^7
 * 
 * 
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        
        long long total = 0;
        for (int num : nums) {
            total += num;
        }
        
        vector<vector<int>> firstHalf(n + 1);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int size = __builtin_popcount(mask);
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }
            firstHalf[size].push_back(sum);
        }
        
        for (int i = 0; i <= n; ++i) {
            sort(firstHalf[i].begin(), firstHalf[i].end());
        }
        
        int minDiff = INT_MAX;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int size = __builtin_popcount(mask);
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += nums[i + n];
                }
            }
            
            auto& candidates = firstHalf[n - size];
            
            long long target = (total - 2 * sum) / 2;
            
            auto it = lower_bound(candidates.begin(), candidates.end(), target);
            
            if (it != candidates.end()) {
                int currentDiff = static_cast<int>(abs(total - 2LL * (sum + *it)));
                minDiff = min(minDiff, currentDiff);
            }
            
            if (it != candidates.begin()) {
                --it;
                int currentDiff = static_cast<int>(abs(total - 2LL * (sum + *it)));
                minDiff = min(minDiff, currentDiff);
            }
        }
        
        return minDiff;
    }
};
// @lc code=end

