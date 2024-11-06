/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (35.62%)
 * Likes:    31563
 * Dislikes: 2954
 * Total Accepted:    4M
 * Total Submissions: 11.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        map<vector<int>,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=(i+1);j<n;j++){
                mpp[{i,j}] = (arr[i] + arr[j]);
            }
        }
        for(int i=0;i<n;i++){
            for(auto it : mpp){
                if((it.first[0] != i) && (it.first[1] != i) && ((it.second) + (arr[i]) == 0)){
                    
                    vector<int> temp = {arr[it.first[0]],arr[it.first[1]],arr[i]};
                    sort(temp.begin(),temp.end());
                    auto it = find(ans.begin(),ans.end(),temp);
                    if(it == ans.end()){
                        // cout<<temp[0]<<"+"<<temp[1]<<"+"<<temp[2]<<"=0";
                        ans.push_back(temp);
                        
                        
                    }
                    // cout<<temp[0]<<"+"<<temp[1]<<"+"<<temp[2]<<"=0"<<endl;
                    // ans.push_back(temp);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
// @lc code=end

