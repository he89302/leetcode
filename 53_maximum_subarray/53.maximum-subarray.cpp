/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (50.05%)
 * Likes:    27095
 * Dislikes: 1213
 * Total Accepted:    2.9M
 * Total Submissions: 5.8M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the subarray which has the largest sum and
 * return its sum.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         vector<int> dp(nums.size());
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }

        return *max_element(dp.begin(), dp.end());
    }

};
// @lc code=end