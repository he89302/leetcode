/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (40.68%)
 * Likes:    14095
 * Dislikes: 612
 * Total Accepted:    956.6K
 * Total Submissions: 2.3M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 * 
 * table = [A : 1] [B : 1] [C : 1]
 * InputS = [ADOBECODEBANC] left = 0 , right = 1...5  => count = 6
 *                          left = 1 , right = 
 * 
 * Example 2:
 * 
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * 
 * Example 3:
 * 
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        
        for(auto c : t) {
            table[c]++;
        }

        int end = 0, meet_t = t.size(), minLen = INT_MAX, start = 0, minStart = 0;

        while(end < s.size()) {
            if(table[s[end]] > 0)
                meet_t--;
            table[s[end]]--; // no trigger agsin in this turn

            end++; // next meet s char
            while(meet_t == 0) {
                // compare min lenght of validation substring
                if(end - start < minLen) {
                    minLen = end - start;
                    minStart = start;
                }

                //recover check now start index of char whether in table, continus next round windows
                table[s[start]]++;
                if(table[s[start]] > 0)
                    meet_t++;
                start++;
            }
        }

        if(minLen != INT_MAX) return s.substr(minStart, minLen);
        return "";
    }
};
// @lc code=end

