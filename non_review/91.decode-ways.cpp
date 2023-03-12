/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (32.23%)
 * Likes:    9551
 * Dislikes: 4197
 * Total Accepted:    980.9K
 * Total Submissions: 3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 * 
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * 
 * 
 * To decode an encoded message, all the digits must be grouped then mapped
 * back into letters using the reverse of the mapping above (there may be
 * multiple ways). For example, "11106" can be mapped into:
 * 
 * 
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 * 
 * 
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
 * into 'F' since "6" is different from "06".
 * 
 * Given a string s containing only digits, return the number of ways to decode
 * it.
 * 
 * The test cases are generated so that the answer fits in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
 * 2 6).
 * 
 * 
 * Example 3:
 * 
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6"
 * is different from "06").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 * 
 * 
 */

// @lc code=start
/*
 * Think :
 * 1 ~ 26
 * e.g. s = 11106
 * 1 -> a ==> 10
 * 11 -> k
 * 110 -> out
 * 
 * 當下合法 = 最後一位數合法(前面不能為0) + 最後兩位數字合法(兩位數應為10 ~ 26) dp[i] = s[i] 當下是否合法
 * ===> dp[i] = dp[i - 1] + dp[i - 2]; 
 * 
 * if
 * 
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), lastDecodeNum = 1, prevNum;
        if(n == 0) return 0;

        // vector<int> dp(n+1);
        // dp[n] = 1; //boundary
        for(int i = n - 1; i >= 0; i--) {
            int cur = s[i] == '0' ? 0 : lastDecodeNum;
            // if(s[i] == '0')
            //     cur = 0;
                // dp[i] = 0;
            // else {
                // dp[i] = dp[i+1];
                if(i < (n - 1) && (s[i]=='1'||s[i]=='2' && s[i+1]<'7'))
                    cur += prevNum;
                    // dp[i] += dp[i+2];
                prevNum = lastDecodeNum;
                lastDecodeNum = cur;
            // }
        }

        // return dp[0];
        return lastDecodeNum;
    }
};
// @lc code=end

