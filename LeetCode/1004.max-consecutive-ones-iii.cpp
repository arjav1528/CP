/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (65.45%)
 * Likes:    9402
 * Dislikes: 162
 * Total Accepted:    965.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given a binary array nums and an integer k, return the maximum number of
 * consecutive 1's in the array if you can flip at most k 0's.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(k == 0){
            int maxLen = 0;
            int count = 0;

            for(int i=0;i<nums.size();i++){
                if(nums[i] == 0){
                    maxLen = max(maxLen,count);
                    count = 0;
                }else{
                    count++;
                }
            }
            maxLen = max(maxLen,count);

            return maxLen;

        }else{
            int n = k;
            int left = 0;
            int right = 0;
            int maxLen = 0;
            

            while(right < nums.size() && left<=right){
                
                if(nums[right] == 0){
                    if(n>0){
                        maxLen = max(maxLen,right-left+1);
                        n--;
                        right++;
                        continue;
                    }else{
                        if(nums[left] == 0 ){
                            n++;
                        }
                        left++;
                        maxLen = max(maxLen,right-left+1);
                        continue;
                    }

                }else{
                    maxLen = max(maxLen,right-left+1);
                    right++;
                }
            }
            return maxLen;
        }
        
    }
};
// @lc code=end

