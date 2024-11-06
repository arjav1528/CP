#include<bits/stdc++.h>
#include <map>
#include <vector>
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (47.56%)
 * Likes:    20551
 * Dislikes: 1060
 * Total Accepted:    2.1M
 * Total Submissions: 4.5M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size() ==1){
            return 1;
        }
        else{
            sort(nums.begin(),nums.end());
            int max_count = 0;
            int count = 1;
            for(int i=0;i<(nums.size()-1);i++){
                if((nums[i]+1) == (nums[i+1])){
                    count++;
                }
                else if(nums[i]==nums[i+1]){
                    // continue;
                }
                else{
                    count = 1;
                }


                if(count>max_count){
                    max_count = count;
                }

            }
            return max_count;
            }
        
    }
};
// @lc code=end

