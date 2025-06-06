/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.40%)
 * Likes:    19913
 * Dislikes: 500
 * Total Accepted:    2.3M
 * Total Submissions: 5M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 * 
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0),cur(amount+1,0);
        int take,notTake;

        if(amount == 0) return 0;

        for(int T=0;T<=amount;T++){
            if(T%coins[0] == 0){
                dp[T] = T/coins[0];
            }else{
                dp[T] = INT_MAX-1;
            }
        }


        for(int i=1;i<coins.size();i++){
            for(int T=0;T<=amount;T++){
                notTake = dp[T];

                take = INT_MAX-1;

                if(coins[i] <= T){
                    take = 1 + cur[T-coins[i]];
                }

                cur[T] = min(take,notTake);
            }

            dp = cur;
        }

        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
            
    }
};
// @lc code=end

