/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (42.13%)
 * Likes:    13225
 * Dislikes: 185
 * Total Accepted:    629.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 * 
 * 
 * Example 1:
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 * 
 * 
 * Example 2:
 * 
 * Input: heights = [2,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 * 
 * 
 */
/*
 * Think : heap -> queue [2,1,5,6,2,3]
 * | 2 | 1 | 5 | 6 |
 * maxArea = 2 -> 5 -> 10
 * left_boundary < currentHight => left_boundary = currentHeight and pop() queue
 * calc maxArea : left_side >= right_side -> left_sied * (right size - left size - 1)
 *
 * 
 * 
*/
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> leftSides;
        int maxArea = 0;

        for(int side = 0; side <= heights.size(); side++) {

            int currentHigh = side == heights.size() ? 0 : heights[side];
            while(!leftSides.empty() && currentHigh < heights[leftSides.top()]) {
                int heightIndex = leftSides.top(); leftSides.pop();
                int width = leftSides.empty() ? side : side - leftSides.top() - 1;
                int currentArea = heights[heightIndex] * width;
                maxArea = max(currentArea, maxArea);
            }

            leftSides.push(side);
        }

        return maxArea;
    }
};
// @lc code=end

