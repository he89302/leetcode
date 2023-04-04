/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2405] Optimal Partition of String
 *
 * https://leetcode.com/problems/optimal-partition-of-string/description/
 *
 * algorithms
 * Medium (75.13%)
 * Likes:    1153
 * Dislikes: 54
 * Total Accepted:    64.7K
 * Total Submissions: 81.9K
 * Testcase Example:  '"abacaba"'
 *
 * Given a string s, partition the string into one or more substrings such that
 * the characters in each substring are unique. That is, no letter appears in a
 * single substring more than once.
 * 
 * Return the minimum number of substrings in such a partition.
 * 
 * Note that each character should belong to exactly one substring in a
 * partition.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "abacaba"
 * Output: 4
 * Explanation:
 * Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
 * It can be shown that 4 is the minimum number of substrings needed.
 * 
 * 
 * Example 2:
 * 
 * Input: s = "ssssss"
 * Output: 6
 * Explanation:
 * The only valid partition is ("s","s","s","s","s","s").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only English lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int partitionString(string s) {
        set<char> cs;
        int res = 1;

        for(auto c : s) {
            if(cs.count(c)) {
                res += 1;
                cs.clear();
            }
            cs.emplace(c);
        }

        return res;
    }
};
// @lc code=end

