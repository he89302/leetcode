/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (66.40%)
 * Likes:    14259
 * Dislikes: 418
 * Total Accepted:    1.8M
 * Total Submissions: 2.8M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */
/*
 * Think : eat -> ate -> tea -> tae 
 * using map <string, int> to record str and group id
 * sort str in strs and check whether is in record
 * in record, add in res.at(group_id).push_back(str)
 * if not update new str to record and push_back(str) in res
 * 
*/
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> record;
        vector<vector<string>> res;

        for(auto str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            auto f = record.find(temp);
            if(f != record.end()) {
                res.at(f->second).push_back(str);
            } else {
                vector<string> sub;
                record.emplace(temp, record.size());
                sub.push_back(str);
                res.push_back(sub);
            }
        }

        return res;
    }
};
// @lc code=end

