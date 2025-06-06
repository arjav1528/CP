/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (74.49%)
 * Likes:    19824
 * Dislikes: 469
 * Total Accepted:    2.5M
 * Total Submissions: 3.4M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * 
 * The test cases are generated such that the number of unique combinations
 * that sum up to target is less than 150 combinations for the given input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * All elements of candidates are distinct.
 * 1 <= target <= 40
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void generateSum(int index, vector<vector<int>> &finalAns, vector<int> ds, vector<int> arr, int target){
        if(index == arr.size()){
            if(target == 0){
                finalAns.push_back(ds);
            }
            return;
        }

        if(arr[index] <= target){
            ds.push_back(arr[index]);
            generateSum(index,finalAns,ds,arr,target-arr[index]);
            ds.pop_back();
        }

        generateSum(index+1,finalAns,ds,arr,target);






    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> finalAns;

        vector<int> ds;

        generateSum(0,finalAns,ds,candidates,target);


        return finalAns;
        
            
    }
};
// @lc code=end

