/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (40.97%)
 * Likes:    5865
 * Dislikes: 399
 * Total Accepted:    223.5K
 * Total Submissions: 546.4K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an integer array nums and an integer k, return true if it is possible
 * to divide this array into k non-empty subsets whose sums are all equal.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [4,3,2,3,5,2,1], k = 4, sum = 20, sum/k
 * Output: true
 * Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [1,2,3,4], k = 3
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 16
 * 1 <= nums[i] <= 10^4
 * The frequency of each element is in the range [1, 4].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;

        vector<int> dp(sum/k + 1, 0);

        for(auto x : nums) {
            auto dp2 = dp;
            for(int s = 0; s <= sum/k; s++) {
                if(s-x >= 0 && dp[s-x] == true) {
                    dp[s] = true;
                }
            }
        }

        return dp[sum/k];
    }
};
// @lc code=end

