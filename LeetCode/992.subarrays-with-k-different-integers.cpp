/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 *
 * https://leetcode.com/problems/subarrays-with-k-different-integers/description/
 *
 * algorithms
 * Hard (65.33%)
 * Likes:    6438
 * Dislikes: 106
 * Total Accepted:    287.1K
 * Total Submissions: 438.4K
 * Testcase Example:  '[1,2,1,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the number of good
 * subarrays of nums.
 * 
 * A good array is an array where the number of different integers in that
 * array is exactly k.
 * 
 * 
 * For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
 * 
 * 
 * A subarray is a contiguous part of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,1,2,3], k = 2
 * Output: 7
 * Explanation: Subarrays formed with exactly 2 different integers: [1,2],
 * [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,4], k = 3
 * Output: 3
 * Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
 * [2,1,3], [1,3,4].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i], k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    int helloWorld(vector<int>& nums, int k) {
        
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int,int> mpp;

        while(right < nums.size()){
            mpp[nums[right]]++;

            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }

            count += right - left + 1;
            right++;

        }

        return count;
        
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return helloWorld(nums,k) - helloWorld(nums,k-1);
        
        
    }
};
// @lc code=end

