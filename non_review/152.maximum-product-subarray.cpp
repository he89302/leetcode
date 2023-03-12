/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (34.91%)
 * Likes:    14464
 * Dislikes: 422
 * Total Accepted:    910.2K
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a subarray that has the largest product,
 * and return the product.
 * 
 * The test cases are generated so that the answer will fit in a 32-bit
 * integer.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<long> minDp(nums.size());
        vector<long> maxDp(nums.size());
        minDp[0] = nums[0];
        maxDp[0] = nums[0];
        long maxNum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            minDp[i] = min(min(minDp[i - 1] * (long)nums[i], maxDp[i - 1] * (long)nums[i]), (long)nums[i]);
            maxDp[i] = max(max(minDp[i - 1] * (long)nums[i], maxDp[i - 1] * (long)nums[i]), (long)nums[i]);
            maxNum = max(maxNum, maxDp[i]);
        }

        return maxNum;
    }
};
// @lc code=end

