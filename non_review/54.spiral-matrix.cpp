/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (43.69%)
 * Likes:    9555
 * Dislikes: 945
 * Total Accepted:    900.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * index 0 1 2 3 -> matrix.size(), matrix[0].size()
 * [00] [01] [02] [03] ++y
 * 
 * turn around
 * 
 * [13] [23] [33] ++x
 * 
 * turn around
 * 
 * [32][31][30] --x
 * 
 * turn around
 * 
 * [20][10] --y
 * 
 * iDir = 0 -> 1 -> 2 -> 3 -> 0
 * dirs[0] = 4 -> 3 -> 2 dirs[1] = 3 -> 2 -> 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // four direction
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int expectedRowSpiralLen = matrix.size(), expectedColSpiralLen = matrix[0].size();
        int row = 0, col = -1; //init position
        int iDir = 0; // 


        vector<int> spirals {expectedColSpiralLen, expectedRowSpiralLen - 1};

        while(spirals[iDir % 2]) {
            for(int i = 0; i < spirals[iDir % 2]; ++i) {
                row += dirs[iDir][0];
                col += dirs[iDir][1];
                res.push_back(matrix[row][col]);
            }

            spirals[iDir % 2]--;
            iDir = (iDir + 1) % 4;
        }

        return res;
    }
};
// @lc code=end

