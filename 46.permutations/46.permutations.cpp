/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currInsert;
        backTrack(res, currInsert, nums);
        return res;
    }
private:
    void backTrack(vector<vector<int>>& res, vector<int>& currInsert, vector<int>& nums) {
        if(currInsert.size() == nums.size()) {
            res.push_back(currInsert);
        } else {
            for(int i = 0; i < nums.size(); i++) {
                if(std::find(currInsert.begin(), currInsert.end(), nums[i]) != currInsert.end()) continue;
                currInsert.push_back(nums[i]);
                backTrack(res, currInsert, nums);
                currInsert.pop_back();
            }
        }
    }
};
// @lc code=end

