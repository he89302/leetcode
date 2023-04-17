/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (60.97%)
 * Likes:    8119
 * Dislikes: 304
 * Total Accepted:    378.9K
 * Total Submissions: 614K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * 
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "bbbab"
 * Output: 4
 * Explanation: One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * 
 * Input: s = "cbbd"
 * Output: 2
 * Explanation: One possible longest palindromic subsequence is "bb".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        cout<< "n : " << to_string(n) << "\n";
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                // cout << " i : " << to_string(i) << ", j = " << to_string(j) << "\n";
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }

    // int longestPalindromeSubseq(string s, int l, int r, vector<vector<int>>& mem) {
    //     if(l==r) return 1;
    //     if(l>r) return 0;
    //     if(mem[l][r]) return mem[l][r];
    //     return mem[l][r] = s[l]==s[r] ? 2 + longestPalindromeSubseq(l+1,r-1, s,mem) : 
    //         max(longestPalindromeSubseq(l+1,r, s,mem),longestPalindromeSubseq(l,r-1, s,mem)); 
    // }
};
// @lc code=end

