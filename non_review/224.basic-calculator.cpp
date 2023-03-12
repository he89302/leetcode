/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (41.16%)
 * Likes:    5158
 * Dislikes: 386
 * Total Accepted:    368.2K
 * Total Submissions: 869.5K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 * 
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 * 
 * 
 * Example 1:
 * 
 * Input: s = "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * Input: s = " 2-1 + 2 "
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
 * invalid).
 * '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
 * valid).
 * There will be no two consecutive operators in the input.
 * Every number and running calculation will fit in a signed 32-bit integer.
 * 
 * 
 */

/* Think : 
 * 相關的operator = {"(", ")", "+", "-", "digit"}
 * 用stack 保存順序，遇到 "(" , 將後面遇到的operator and digit 存進Stack, 直到遇到")" 才pop 出來進行operate
*/
// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> record;
        int number = 0, result = 0, sign = 1;

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if(c == '+' || c == '-') {
                result += sign * number;
                number = 0;
                sign = (c == '+' ? 1 : -1);
            } else if(c == '(') {
                record.push(result);
                record.push(sign);
                sign = 1;
                result = 0;
            }  else if(c == ')') {
                result += sign * number;
                number = 0;
                result *= record.top(); record.pop();
                result += record.top(); record.pop();
            }
        }

        result += sign * number;
        return result;
    }
};
// @lc code=end

