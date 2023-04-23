/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (52.88%)
 * Likes:    10219
 * Dislikes: 341
 * Total Accepted:    591.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 * 
 * 
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 * 
 * 
 * Example 1:
 * 
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 * 
 * 
 * Example 3:
 * 
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir={-1,0,1,0,-1};
        int fresh = 0, ans = -1;
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++)
            {
                int orangeState = grid[i][j];
                if(orangeState == 1)
                    fresh++;
                if(orangeState == 2)
                    q.push({i, j});
            }
        }

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto p = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int row = p.first + dir[i];
                    int col = p.second + dir[i + 1];
                    if(row >= 0 and col >= 0 and row < grid.size() and col < grid[0].size() and grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            ans++;
        }

        if(fresh > 0) return -1;
        if(ans == -1) return 0;
        return ans;
    }
};
// @lc code=end

