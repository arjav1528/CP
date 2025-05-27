/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (57.56%)
 * Likes:    11550
 * Dislikes: 342
 * Total Accepted:    1.4M
 * Total Submissions: 2.4M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void generateSumDuplicatesNotAllowed(int index,vector<vector<int>> &finalAns, vector<int> ds, vector<int> arr, int sum, int target){
        if(index == arr.size()){
            if(sum == target){
                sort(ds.begin(),ds.end());

                for(int i=0;i<finalAns.size();i++){
                    if(finalAns[i] == ds){
                        return;
                    }
                }
                finalAns.push_back(ds);
            }
            return;
        }

        ds.push_back(arr[index]);
        sum+= arr[index];

        generateSumDuplicatesNotAllowed(index+1,finalAns,ds,arr,sum,target);

        sum -= arr[index];
        ds.pop_back();

        generateSumDuplicatesNotAllowed(index+1,finalAns,ds,arr,sum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> finalAns;

        vector<int> ds;

        generateSumDuplicatesNotAllowed(0,finalAns,ds,candidates,0,target);


        return finalAns;


        
    }
};
// @lc code=end

