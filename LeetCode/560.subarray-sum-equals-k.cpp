/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.29%)
 * Likes:    22087
 * Dislikes: 689
 * Total Accepted:    1.5M
 * Total Submissions: 3.3M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * subarrays whose sum equals to k.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int start = 0;
        int current = 0;
        int sum = arr[0];
        int count = 0;
        while(current < n){
            if(sum<k){
                current++;
                if(current<n){
                    sum+=arr[current];
                }
                
            }
            else if(sum>k){
                sum-=arr[start];
                start++;
            }
            else{
                count++;
                current++;
                if(current<n){
                    sum+=arr[current];
                }
            }
        }
        return count;
        
    }
};
// @lc code=end

