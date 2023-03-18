/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.82%)
 * Likes:    32726
 * Dislikes: 1427
 * Total Accepted:    4.3M
 * Total Submissions: 12.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> record;
        int length = 0, leftIndex = 0;

        for(int rightIndex = 0; rightIndex < s.length(); rightIndex++) {
            if(record.find(s[rightIndex]) != record.end()) {
                leftIndex = max(leftIndex, record[s[rightIndex]] + 1);
            }
            record[s[rightIndex]] = rightIndex;
            length = max(length, rightIndex - leftIndex + 1);
        }

        return length;
    }
};
// @lc code=end

