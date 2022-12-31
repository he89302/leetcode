/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (51.42%)
 * Likes:    6937
 * Dislikes: 268
 * Total Accepted:    380.6K
 * Total Submissions: 737.9K
 * Testcase Example:  '"ABAB"\n2'
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 * 
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * Example 2:
 * 
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 * 
 * 
 * Think : sliding window
 * AABABBA
 * using hash table record max number of char
 * if condition : (windows size - record max number of char ) < k
 * else condition left ++ then search again
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, result = 0, maxNum = 0, maxSize = 0;
        unordered_map<int, int> record;

        for(int end = 0; end < s.length(); end++) {
            record[s[end]]++;
            maxNum = max(maxNum, record[s[end]]);

            while(end - left + 1 - maxNum > k) {
                record[s[left]]--;
                left++;
            }

            maxSize = max(maxSize, end - left + 1);
        }

        return maxSize;
    }
};
// @lc code=end

