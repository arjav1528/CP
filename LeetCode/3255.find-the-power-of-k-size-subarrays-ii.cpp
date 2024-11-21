/*
 * @lc app=leetcode id=3255 lang=cpp
 *
 * [3255] Find the Power of K-Size Subarrays II
 *
 * https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/description/
 *
 * algorithms
 * Medium (26.90%)
 * Likes:    119
 * Dislikes: 9
 * Total Accepted:    25.3K
 * Total Submissions: 92.6K
 * Testcase Example:  '[1,2,3,4,3,2,5]\n3'
 *
 * You are given an array of integers arr of length n and a positive integer
 * k.
 * 
 * The power of an array is defined as:
 * 
 * 
 * Its maximum element if all of its elements are consecutive and sorted in
 * ascending order.
 * -1 otherwise.
 * 
 * 
 * You need to find the power of all subarrays of arr of size k.
 * 
 * Return an integer array results of size n - k + 1, where results[i] is the
 * power of arr[i..(i + k - 1)].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2,3,4,3,2,5], k = 3
 * 
 * Output: [3,4,-1,-1,-1]
 * 
 * Explanation:
 * 
 * There are 5 subarrays of arr of size 3:
 * 
 * 
 * [1, 2, 3] with the maximum element 3.
 * [2, 3, 4] with the maximum element 4.
 * [3, 4, 3] whose elements are not consecutive.
 * [4, 3, 2] whose elements are not sorted.
 * [3, 2, 5] whose elements are not consecutive.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,2,2,2,2], k = 4
 * 
 * Output: [-1,-1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [3,2,3,2,3,2], k = 2
 * 
 * Output: [-1,3,-1,3,-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n == arr.length <= 10^5
 * 1 <= arr[i] <= 10^6
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        int count = 0;
        
        
    }
};
// @lc code=end

