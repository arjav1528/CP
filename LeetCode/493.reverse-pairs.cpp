/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (31.24%)
 * Likes:    6303
 * Dislikes: 274
 * Total Accepted:    217.4K
 * Total Submissions: 695.6K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an integer array arr, return the number of reverse pairs in the
 * array.
 * 
 * A reverse pair is a pair (i, j) where:
 * 
 * 
 * 0 <= i < j < arr.length and
 * arr[i] > 2 * arr[j].
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,3,2,3,1]
 * Output: 2
 * Explanation: The reverse pairs are:
 * (1, 4) --> arr[1] = 3, arr[4] = 1, 3 > 2 * 1
 * (3, 4) --> arr[3] = 3, arr[4] = 1, 3 > 2 * 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,4,3,5,1]
 * Output: 3
 * Explanation: The reverse pairs are:
 * (1, 4) --> arr[1] = 4, arr[4] = 1, 4 > 2 * 1
 * (2, 4) --> arr[2] = 3, arr[4] = 1, 3 > 2 * 1
 * (3, 4) --> arr[3] = 5, arr[4] = 1, 5 > 2 * 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * -2^31 <= arr[i] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int count = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=(i+1);j<arr.size();j++){
                if(((long long)arr[i])>((2*(long long)arr[j]))){
                    count++;
                }
            }
        }
        return count;
        
    }
};
// @lc code=end

