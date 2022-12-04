/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (53.98%)
 * Likes:    5863
 * Dislikes: 1111
 * Total Accepted:    321K
 * Total Submissions: 593.2K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 * 
 * The island is partitioned into a grid of square cells. You are given an m x
 * n integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 * 
 * The island receives a lot of rain, and the rain water can flow to
 * neighboring cells directly north, south, east, and west if the neighboring
 * cell's height is less than or equal to the current cell's height. Water can
 * flow from any cell adjacent to an ocean into the ocean.
 * 
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 * 
 * 
 * Example 1:
 * 
 * Input: heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * Explanation: The following cells can flow to the Pacific and Atlantic
 * oceans, as shown below:
 * [0,4]: [0,4] -> Pacific Ocean 
 * [0,4] -> Atlantic Ocean
 * [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
 * [1,3] -> [1,4] -> Atlantic Ocean
 * [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
 * [1,4] -> Atlantic Ocean
 * [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
 * [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
 * [3,0]: [3,0] -> Pacific Ocean 
 * [3,0] -> [4,0] -> Atlantic Ocean
 * [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
 * [3,1] -> [4,1] -> Atlantic Ocean
 * [4,0]: [4,0] -> Pacific Ocean 
 * ⁠      [4,0] -> Atlantic Ocean
 * Note that there are other possible paths for these cells to flow to the
 * Pacific and Atlantic oceans.
 * 
 * 
 * Example 2:
 * 
 * Input: heights = [[1]]
 * Output: [[0,0]]
 * Explanation: The water can flow from the only cell to the Pacific and
 * Atlantic oceans.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if(m <= 0 || n <= 0) return {};

        vector<vector<int>> result;

        auto pacificVisited = vector<vector<int>>(m, vector<int>(n, 0));
        auto atlanticVisited = vector<vector<int>>(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            dfs(i, 0, heights, pacificVisited);
        
        for(int j = 0; j < n; j++)
            dfs(0, j, heights, pacificVisited);

        for(int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atlanticVisited);

        for(int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atlanticVisited);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        
        return result;
    }

private:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& sea) {
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        sea[i][j] = 1;

        for(int k = 0; k < dir.size(); k++) {
            int x = i + dir[k].first;
            int y = j + dir[k].second;

            if(x < 0 || x == heights.size() || y < 0 || y == heights[0].size()) continue;
            if(sea[x][y] == 1) continue;
            if(heights[x][y] < heights[i][j]) continue;
            dfs(x, y, heights, sea);
        }
    }
};
// @lc code=end

