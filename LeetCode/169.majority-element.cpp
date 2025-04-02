/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (65.55%)
 * Likes:    20669
 * Dislikes: 718
 * Total Accepted:    4.1M
 * Total Submissions: 6.2M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;

            if(mpp[nums[i]] > (nums.size()/2)){
                return nums[i];
            }
        }
        return -1;
        
    }
};
// @lc code=end

