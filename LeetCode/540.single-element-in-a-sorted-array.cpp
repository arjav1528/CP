/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (59.28%)
 * Likes:    11494
 * Dislikes: 201
 * Total Accepted:    769.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 * 
 * Return the single element that appears only once.
 * 
 * Your solution must run in O(log n) time and O(1) space.
 * 
 * 
 * Example 1:
 * Input: arr = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * Example 2:
 * Input: arr = [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
    if(arr.size()==1){
        return arr[0];
    }
    else if(arr[0] != arr[1]){
        return arr[0];
    }
    else if(arr[arr.size()-1] != arr[arr.size()-2]){
        return arr[arr.size()-1];
    }
    else{
        int high = arr.size()-2;
        int low = 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
                return arr[mid];
            }
            else{
                if(mid%2==0){
                    if(arr[mid]==arr[mid+1]){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                else{
                    if(arr[mid]==arr[mid+1]){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }
                }
            }
        }
    }
    return -1;
        
    }
    
};
// @lc code=end

