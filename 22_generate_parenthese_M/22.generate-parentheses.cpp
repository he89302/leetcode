/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (71.84%)
 * Likes:    17054
 * Dislikes: 681
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
/*
Think : 
revursive
n = 1 () 1
n = 2 ()(), (()) 2
n = 3 ()(()), (())(), ((())), ()()(), (()()) 5
n = 4 ()()()(), (()()()), ()()(()), (()())(), ...

*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking(res, "", n, n);
        return res;
    }
private:
    void backtracking(vector<string>& res, string partial, int remainLeftBrackets, int remainRightBrackets) {
        if(remainLeftBrackets == 0 && remainRightBrackets == 0) {
            res.push_back(partial);
            return;
        }

        if(remainLeftBrackets > 0)
            backtracking(res, partial + "(", remainLeftBrackets - 1, remainRightBrackets);
        if(remainRightBrackets > remainLeftBrackets)
            backtracking(res, partial + ")", remainLeftBrackets, remainRightBrackets - 1);
    }
};
// @lc code=end

