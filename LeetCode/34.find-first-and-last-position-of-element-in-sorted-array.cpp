#include<bits/stdc++.h>
#include<vector>
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (45.42%)
 * Likes:    20949
 * Dislikes: 546
 * Total Accepted:    2.3M
 * Total Submissions: 5.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        vector<int> ans;
        int p;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] ==target){
                ans.push_back(mid);
                if(arr[mid-1]==target){
                    // ans.push_back(arr[low];
                    low = (mid-1);
                    ans.push_back(arr[low];
                }
                if(arr[mid+1] = target){
                    high = (mid+1);
                    ans.push_back(arr[high];
                }
            }
            else if(arr[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        // return {-1};

        
    }
};
// @lc code=end

