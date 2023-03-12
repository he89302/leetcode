/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (36.65%)
 * Likes:    9789
 * Dislikes: 1760
 * Total Accepted:    880.9K
 * Total Submissions: 2.4M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 * 
 * 
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 * 
 * 
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 * 
 * 
 * Example 1:
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
 * -> "dog" -> cog", which is 5 words long.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 * 
 * 
 */
/* Think : 
 * find endWord whether exist in wordList
 * using BFS to word = beginWord to find a~z permutation to BFS and check is count in wordList and BFS not visited
 * update BFS queue and visited set.
 * */
// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(!count(wordList.begin(), wordList.end(), endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        set<string> visited, wordSet;
        for(auto w : wordList)
            wordSet.insert(w);
        visited.insert(beginWord);
        int changed = 1;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string word = q.front();
                if(word == endWord) return changed;
                q.pop();

                for(int c = 0; c < word.size(); c++) {
                    for (int l = 'a'; l <= 'z'; l++) {
                        string temp;
                        temp = word;
                        temp[c] = l;
                        if(wordSet.count(temp) and !visited.count(temp)) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                    
                }
            }
            ++changed;
        }

        return 0;
    }
};
// @lc code=end

