/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.79%)
 * Likes:    11518
 * Dislikes: 458
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int x = 0; x < board.size(); x++) {
            for(int y = 0; y < board[x].size(); y++) {
                if(existNeighbor(board, x, y, word, 0)) return true;
            }
        }

        return false;
    }

private:
    bool existNeighbor(vector<vector<char>> & board, int x, int y, string word, int findNeighbor) {
        if(findNeighbor == word.length()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[x].size()) return false;
        if(board[x][y] != word[findNeighbor]) return false;
        board[x][y] = '#';
        bool isExistNeighbor = existNeighbor(board, x + 1, y, word, findNeighbor + 1) ||
                               existNeighbor(board, x - 1, y, word, findNeighbor + 1) ||
                               existNeighbor(board, x, y + 1, word, findNeighbor + 1) ||
                               existNeighbor(board, x, y - 1, word, findNeighbor + 1);
        board[x][y] = word[findNeighbor];
        
        return isExistNeighbor;                        
    }
};
// @lc code=end

