/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (48.95%)
 * Likes:    9155
 * Dislikes: 283
 * Total Accepted:    637.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * 
 * Example 2:
 * 
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> anagrams(26, 0);
        vector<int> substring(26, 0);

        if(s.size() < p.size()) return{};

        for(int i = 0; i < p.size(); i++){
            substring[p[i] - 'a']++;
            anagrams[s[i] - 'a']++;
        }

        if(substring == anagrams) result.push_back(0);

        for(int right = p.length(); right < s.length(); right++) {
            for(int i = 0; i < anagrams.size(); i++) {
                printf("%c : %d, ", i + 0x61, anagrams[i]);
            }
            printf("\n");

            int left = right - p.length();
            anagrams[s[right] - 'a']++;
            anagrams[s[left] - 'a']--;

            if(anagrams == substring)
                result.push_back(left + 1);
        }

        return result;
    }
};
// @lc code=end

