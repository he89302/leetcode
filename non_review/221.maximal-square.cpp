/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (44.49%)
 * Likes:    8487
 * Dislikes: 181
 * Total Accepted:    562.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 * 
 * 
 * Example 1:
 * 
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * Input: matrix = [["0"]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 * 
 * 
 */
/*
 * 
 * Think : used 
 * 
*/
// @lc code=start
/*
 * Think : 1 1 需要從prev 點(左上) ，確保min(三個方向) + 1 > 1 <=== 代表side 值改變，所以最後result = side * side
 *         1 1
 * 
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size(), maxSide = 0;
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        /*
         *stellari
         *Good O(n) memory solution.
         *A minor optimization could be to use two pointers to pre and cur and only swap those pointers to avoid vector copying.
         *
         *Also, if you think about it, it is actually enough to use one vector only instead of two.
         *The whole purpose of maintaining two arrays is that we want to keep the information of pre[i-1]. 
         *So we just need to use another variable to keep track of its
         * 
        */
        int last_topleft;
        vector<int> currentCol(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int temp = currentCol[j];
                if(matrix[i][j] == '0' || !i || !j) {
                    currentCol[j] = matrix[i][j] - '0';
                } else {
                    currentCol[j] = min(min(last_topleft, currentCol[j]), currentCol[j-1]) + 1;
                    last_topleft = temp;
                }
                maxSide = max(maxSide, currentCol[j]);
                last_topleft = temp;
            }
        }

        return maxSide*maxSide;
    }
};
// @lc code=end

