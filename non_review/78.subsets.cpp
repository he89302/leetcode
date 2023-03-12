/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (73.86%)
 * Likes:    12697
 * Dislikes: 181
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currCombination;
        backTrack(nums, currCombination, res, 0);
        return res;
    }

private:
    void backTrack(vector<int> &nums, vector<int> currCombination, vector<vector<int>> &res, int index) {
        res.push_back(currCombination);

        for(int i = index; i < nums.size(); i++) {
            currCombination.push_back(nums[i]);
            backTrack(nums, currCombination, res, i + 1);
            currCombination.pop_back();
        }
    }
};
// @lc code=end

