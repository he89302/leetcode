/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currCombination;
        combination(candidates, target, currCombination, 0, 0, res);
        return res;
    }
private:
    void combination(vector<int>& candidates, int target, vector<int> currCombination, int currSum, int currIndex, vector<vector<int>>& res) {
        if(currSum > target) return;
        if(currSum == target) {
            res.push_back(currCombination);
            return;
        }
        
        for(int i = currIndex; i < candidates.size(); i++) {
            currCombination.push_back(candidates[i]);
            currSum += candidates[i];
            combination(candidates, target, currCombination, currSum, i, res);
            currCombination.pop_back();
            currSum -= candidates[i];
        }
    } 
};
// @lc code=end

