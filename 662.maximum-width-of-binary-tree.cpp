/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (40.60%)
 * Likes:    6034
 * Dislikes: 842
 * Total Accepted:    231.4K
 * Total Submissions: 569.3K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return the maximum width of the given
 * tree.
 * 
 * The maximum width of a tree is the maximum width among all levels.
 * 
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and rightmost non-null nodes), where the null nodes between the
 * end-nodes that would be present in a complete binary tree extending down to
 * that level are also counted into the length calculation.
 * 
 * It is guaranteed that the answer will in the range of a 32-bit signed
 * integer.
 * 
 * 
 * Example 1:
 * 
 * Input: root = [1,3,2,5,3,null,9]
 * Output: 4
 * Explanation: The maximum width exists in the third level with length 4
 * (5,3,null,9).
 * 
 * 
 * Example 2:
 * 
 * Input: root = [1,3,2,5,null,null,9,6,null,7]
 * Output: 7
 * Explanation: The maximum width exists in the fourth level with length 7
 * (6,null,null,null,null,null,7).
 * 
 * 
 * Example 3:
 * 
 * Input: root = [1,3,2,5]
 * Output: 2
 * Explanation: The maximum width exists in the second level with length 2
 * (3,2).
 * 
 * stack [1] 
 *       [3, 2] max = 2 level = 2
 *       [5, null, 2] max level = 3
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 3000].
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 * 
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, int>> q;
        q.push_back({root, 0});
        int res = 0;

        while(!q.empty()) {
            int count = q.size();
            int start = q.front().second;
            int end = q.back().second;

            res = max(res, end - start + 1);

            while(count > 0){
                pair<TreeNode*, int> temp = q.front();
                // we will use it while inserting it children
                // left child will be 2 * idx + 1;
                // right chils will be 2 * idx + 2;
                int index = temp.second;
                q.pop_front();

                if(temp.first->left != nullptr)
                    q.push_back({temp.first->left, (long long)index * 2 + 1});

                if(temp.first->right != nullptr)
                    q.push_back({temp.first->right, (long long)index *2 + 2});
                count--;
            }
        }

        return res;
    }
};
// @lc code=end

