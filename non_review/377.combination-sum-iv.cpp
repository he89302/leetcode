

/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (52.09%)
 * Likes:    5513
 * Dislikes: 561
 * Total Accepted:    348K
 * Total Submissions: 667.3K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an array of distinct integers nums and a target integer target, return
 * the number of possible combinations that add up to target.
 * 
 * The test cases are generated so that the answer can fit in a 32-bit
 * integer.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3], target = 4
 * Output: 7
 * Explanation:
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * Note that different sequences are counted as different combinations.
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [9], target = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * All the elements of nums are unique.
 * 1 <= target <= 1000
 * 
 * 
 * 
 * Follow up: What if negative numbers are allowed in the given array? How does
 * it change the problem? What limitation we need to add to the question to
 * allow negative numbers?
 * 
 */

// @lc code=start
/*
 * Think : 
 * vector<int> dp(target+1);
 * n = 3
 * {1, 0, 0, 0}
 * 
 * 1 - 1
 * dp[0] + dp[1 - nums[0]] = 1 + 1
 * {1, 2}
 * 
 * 
 * 
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target+1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());

        for(int i = 1; i <= target; i++) {
            for(auto num : nums) {
                if(i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
            cout<< "dp[" + to_string(i) + "] = " + to_string(dp[i]) << endl;
        }

        return dp[target];
    }
};
// @lc code=end

