/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (64.08%)
 * Likes:    4046
 * Dislikes: 137
 * Total Accepted:    184.4K
 * Total Submissions: 274.9K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 * 
 * Return the number of closed islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation: 
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        for( int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0){
                    res += dfs(grid, i, j) ? 1 : 0;
                }
            }
        }

        return res;
    }

private:
    bool dfs(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
        {
            return false;
        }
        if(grid[row][col] == 1)
        {
            return true;
        }
       
        grid[row][col] = 1;
        /* IMPORTANT NOTE: 
        WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
        BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
        HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
        */

        bool d1 = dfs(grid, row + 1, col);
        bool d3 = dfs(grid, row, col + 1);
        bool d2 = dfs(grid, row - 1, col);
        bool d4 = dfs(grid, row, col - 1);

        return d1 && d2 && d3 && d4;
    }
};
// @lc code=end

