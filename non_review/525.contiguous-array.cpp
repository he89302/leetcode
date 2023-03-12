/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (46.81%)
 * Likes:    6039
 * Dislikes: 242
 * Total Accepted:    286.4K
 * Total Submissions: 611.4K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array nums, return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with an equal number
 * of 0 and 1.
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * Input = [0,0,0,1,1,1,1]
 * output = 6
 * [0, 0, 0, 1, 1, 1]
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> record;
        int preSum = 0, res = 0;
        record[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                preSum += 1;
            else
                preSum -= 1;

            if(record.find(preSum) != record.end())
                res = max(res, i - record[preSum]);
            else 
                record[preSum] = i;
        }

        return res;
    }
};
// @lc code=end

