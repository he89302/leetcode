/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (44.17%)
 * Likes:    6279
 * Dislikes: 303
 * Total Accepted:    340K
 * Total Submissions: 767.1K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * Example 1:
 * 
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * Example 2:
 * 
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 * 
 * 
 */

// @lc code=start
class Solution {
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0)
                    q.emplace(i, j);
                else
                    mat[i][j] = -1;
            }
        }
        
        while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for(int i = 0; i < dir.size(); i++) {
                int x = row + dir[i].first;
                int y = col + dir[i].second;

                if(x < 0 || x == mat.size() || y < 0 || y == mat[0].size() || mat[x][y] != -1) continue;
                mat[x][y] = mat[row][col] + 1;
                q.emplace(x, y);
            }
        }

        return mat;
    }
};
// @lc code=end

