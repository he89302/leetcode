/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (46.64%)
 * Likes:    9258
 * Dislikes: 152
 * Total Accepted:    552.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); //knapsack count
        
        if(sum % 2 != 0) return false;

        vector<int> dp(sum/2 + 1, 0);
        dp[0] = true;

        for (auto x : nums) { // iterator knapsack object
            auto dp2 = dp;
            for(int s = 0; s <= sum/2; s++) {
                if(s-x >= 0 && dp2[s-x] == true)
                    dp[s] = true;
            }
        }
        
        return dp[sum/2];
    }
};
// @lc code=end

// [1,5,5,11]
// for every each 1, 5, 5, 11

// 1
// 1, 5 | 5, 11
// 1, 5, 5 | 11
// 5, ... => O(2eN)

//knapsack
//s = subset sum
//dp[s] : whether we can find a subset whose sum equals to s[0 ~ 2e4]
//dp[sum/2] = true

