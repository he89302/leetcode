/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (57.53%)
 * Likes:    9966
 * Dislikes: 442
 * Total Accepted:    596.3K
 * Total Submissions: 1M
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 * 
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * 
 * 
 * Example 2:
 * 
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * 
 * condition : match [ push in stack, and ] pop and cal composing string
 * condition : match digit and calc the num for repeat
 * 
 * 3 '[' 2 ']' ']'
 * 
 * match ']', use 2 as repeat c -> string is "cc"
 * match ']', use 3 as repeat "a" + "cc" is "accaccacc" 
 * 
 * stack : 3 a 2 c
 * 
 * Example 3:
 * 
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        string repeatNum = "";
        stack<string> st; 

        for(auto c : s) {
            if(c == '[') {
                st.push(res);
                st.push(repeatNum);
                res = "";
                repeatNum = "";
            } else if(c == ']') {
                string k = st.top(); st.pop();
                string prev = st.top(); st.pop();
                res = prev + nTimesString(res, stoi(k));
            } else {
                if(isdigit(c)) {
                    repeatNum += c;
                } else {
                    res += c;
                }
            }
        }

        return res;
    }

    string nTimesString(string s, int n) {
        string ans = "";
        for (int i = 0; i < n; i++) ans += s;
        return ans;
    }
};
// @lc code=end

