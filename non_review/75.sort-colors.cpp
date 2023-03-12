/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (57.19%)
 * Likes:    13468
 * Dislikes: 488
 * Total Accepted:    1.3M
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 * 
 * You must solve this problem without using the library's sort function.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * 2 0 2 1 1 0
 * [2] [0] 2 1 1 0
 * [0] [2] 2 1 1 0
 * [0] 2 [2] 1 1 0
 * [0] [0] 2 2 1 1
 * One algorithm is to have the top group grow down from the top of the array, 
 * the bottom group grow up from the bottom, 
 * and keep the middle group just above the bottom. 
 * The algorithm indexes three locations, the bottom of the top group, the top of the bottom group, 
 * and the top of the middle group. 
 * 
 * Elements that are yet to be sorted fall between the middle and the top group.[4] At each step, 
 * examine the element just above the middle. If it belongs to the top group, 
 * swap it with the element just below the top. If it belongs in the bottom, 
 * swap it with the element just above the bottom. If it is in the middle, leave it. 
 * Update the appropriate index. Complexity is Θ(n) moves and examinations.[1]
 * 
 * Example 2:
 * 
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is either 0, 1, or 2.
 * 
 * 
 * 
 * Follow up: Could you come up with a one-pass algorithm using only constant
 * extra space?
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k = nums.size() - 1, i = 0, j = 0;
        
        while(j <= k) {
            if(nums[j] < 1) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if(nums[j] > 1) {
                swap(nums[j], nums[k]);
                k--;
            } else {
                j++;
            }
        }
    }
};
// @lc code=end

