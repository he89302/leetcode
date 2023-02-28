/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.02%)
 * Likes:    17340
 * Dislikes: 508
 * Total Accepted:    938K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * subarrays whose sum equals to k.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n); prefix[0] = nums[0];
        map<int, int> record;
        int ans = 0;

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            if(prefix[i] == k) ans++;
            if(record.find(prefix[i] - k) != record.end())
                ans += record[prefix[i] - k];
            record[prefix[i]]++;
        }

        return ans;
    }
};
// @lc code=end

