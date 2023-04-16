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
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n));
        return lps(s, 0, s.length() - 1, memo);
    }

    int lps(string s, int left, int right, vector<vector<int>>& memo) {
        if(memo[left][right] != 0)
            return memo[left][right];
        
        if(left < 0 || right == s.length() || left > right)
            return 0;
        
        if(left == right)
            return 1;

        if(s[left] == s[right])
            memo[left][right] = lps(s, left + 1, right - 1, memo) + 2;
        else
            memo[left][right] = max(lps(s, left + 1, right, memo), lps(s, left, right - 1, memo));
        return memo[left][right];
    }
};
// @lc code=end

