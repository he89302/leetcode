/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.41%)
 * Likes:    22569
 * Dislikes: 1302
 * Total Accepted:    2.2M
 * Total Submissions: 6.7M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // Dynamic programing
        // using dp array record substring is palindrome
        int n = s.size();
        string res = "";
        
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        res += s[0];
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                printf("index num i = %d j = %d\n", i, j);
                if(s[i] == s[j]) {
                    if(j - i == 1 || dp[i+1][j-1]) {
                        dp[i][j] = true;
                        
                        if(res.size() < j - i + 1)
                            res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

