/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (56.80%)
 * Likes:    7985
 * Dislikes: 879
 * Total Accepted:    1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * Input: board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 * 
 * 
 */

// @lc code=start
/*
 * Think : using row and column and block 去encode 所有可能性，加入set 中，
           如果加入的途中發生錯誤(!set.emplace return iterator and second is not true)
 *         就表示為inValid Sudoku
 * 舉例 example 2. board[0][0] = 8 ==> 所以知道 "8 in row 0", "8 in col 0", "8 in block 0-0"
 *     所以當有相同8 出現在同一3x3 矩陣蒔 會得到 board[2][2] = 8 ==> "8 in row 2", "8 in col 2", "8 in block 0-0"
 *     最後一組重複，所以Return false
 * 這邊還有人使用cartor pair (https://en.wikipedia.org/wiki/Pairing_function)
 * :The Cantor pairing function assigns one natural number to each pair of natural numbers
 * 
 * 所以我也可以根據Cantor pair function 去encode 出一個新的int 取代row, col, and block
 * 
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> record;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                string num{board[i][j]};
                if(num != ".") {
                    if(!record.emplace(num + " in row " + to_string(i)).second ||
                       !record.emplace(num + " in col " + to_string(j)).second || 
                       !record.emplace(num + " in block " + to_string(i / 3) + "-" + to_string(j / 3)).second) {
                            return false;
                       }
                }
            }
        }

        return true;
    }
private:
    int cantor(int x, int y) {
        return ((x + y) * (x + y + 1)) / 2 + y;
    }
};
// @lc code=end

