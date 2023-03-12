/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (58.78%)
 * Likes:    24749
 * Dislikes: 345
 * Total Accepted:    1.4M
 * Total Submissions: 2.4M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * 
 * Example 1:
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 * 
 * current num < next large num
 * []
 * 
 * Example 2:
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMaxHight = height[left], rightMaxHeight = height[right];
        int waterArea = 0;

        while (left < right)
        {
            if(height[left] < height[right]) {
                leftMaxHight = max(leftMaxHight, height[++left]);
                waterArea += leftMaxHight - height[left];
            } else {
                rightMaxHeight = max(rightMaxHeight, height[--right]);
                waterArea += rightMaxHeight - height[right];
            }
        }
        return waterArea;
    }
};
// @lc code=end

