/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (41.51%)
 * Likes:    14917
 * Dislikes: 345
 * Total Accepted:    1.3M
 * Total Submissions: 3.1M
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
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * dp function = min(dp[n - k_1], dp[n - k_2], dp[n - k_3], ... dp[0]) + 1 | k_index is coins num(1~12)
 * 
 * amount = 11 coins = [1, 2, 5] 
 *| 0 | 1(1) | 1(2) | 2(1,2) | 2(2,2) | 1(5) | 2(1,5) | 2(2,5) | 3(1,2,5) | 3(2,2,5) | 2(5,5) | 3(5,5,1) |  |
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
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;
        std::sort(std::begin(coins), std::end(coins));

        for(int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
            for(int coin : coins) {
                if(i - coin < 0) break;
                if(dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                // cout << "dp [ " + to_string(i) + " ] = " + to_string(dp[i]) + "\n"; 
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];

    }
};
// @lc code=end

