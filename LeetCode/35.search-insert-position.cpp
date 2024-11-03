/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (47.49%)
 * Likes:    16591
 * Dislikes: 772
 * Total Accepted:    3.3M
 * Total Submissions: 7M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,3,5,6], target = 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,3,5,6], target = 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [1,3,5,6], target = 7
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * -10^4 <= arr[i] <= 10^4
 * arr contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        int upperBound = arr.size();
        int index = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid] > target){
                upperBound = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return upperBound;
        
    }
};
// @lc code=end

