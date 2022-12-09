/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (56.85%)
 * Likes:    6511
 * Dislikes: 302
 * Total Accepted:    508.4K
 * Total Submissions: 893.6K
 * Testcase Example:  '["i","love","leetcode","i","love","coding"]\n2'
 *
 * Given an array of strings words and an integer k, return the k most frequent
 * strings.
 * 
 * Return the answer sorted by the frequency from highest to lowest. Sort the
 * words with the same frequency by their lexicographical order.
 * 
 * 
 * Example 1:
 * 
 * Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 * Output: ["i","love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * Example 2:
 * 
 * Input: words =
 * ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 * Output: ["the","is","sunny","day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 500
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * k is in the range [1, The number of unique words[i]]
 * 
 * 
 * 
 * Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
 * 
 */

// @lc code=start
class myComparator {
  public:
    bool operator() (const pair<string, int> &p1, const pair<string, int> &p2) {
      if(p1.second == p2.second) return p1.first < p2.first;
      
      return p1.second > p2.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> record;
        priority_queue<pair<string, int>, vector<pair<string, int>>, myComparator> q;
        vector<string> res(k);

        for (size_t i = 0; i < words.size(); i++) {
            record[words[i]]++;
        }

        for(auto it : record) {
            q.push(it);

            if(q.size() > k) {
                q.pop();
            }
        }

        int m = k - 1;
        while(q.size() > 0) {
            res[m--] = q.top().first;
            q.pop();
        }

        return res;
    }
};
// @lc code=end

