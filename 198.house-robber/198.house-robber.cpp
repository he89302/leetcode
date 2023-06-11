/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (48.68%)
 * Likes:    15394
 * Dislikes: 301
 * Total Accepted:    1.4M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * [1]
 * [1, 2] A = 1, B = 2
 * [1, 2, 3] A = 1 + 3, B = 2
 * [1, 2, 3, 1] A = 1+3, B = 2 + 1
 * 
 * Example 2:
 * 
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * A = 0, B = 0
 * [2] A = 2, B = 0
 * [2, 7] A = 2, A = max(A, 0+7) B = prevA(2)
 * [2, 7, 9] A = 7, A = max(A, B + 9),
 * 
 *
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int prevA = 0, prevB = 0;

        for(auto num : nums) {
            int temp = prevA;
            prevA = max(prevA, prevB + num);
            prevB = temp;
        }

        return prevA;
    }
};
// @lc code=end

