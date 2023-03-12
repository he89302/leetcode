/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (61.17%)
 * Likes:    9226
 * Dislikes: 551
 * Total Accepted:    887K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 * 
 * 
 * Example 1:
 * 
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 * 
 * 
 * Example 2:
 * 
 * Input: root = [1,null,3]
 * Output: [1,3]
 * 
 * 
 * Example 3:
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 100].
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
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            while (size > 0)
            {
                size--;
                TreeNode* node = q.front(); q.pop();
                if(size == 0)
                    res.push_back(node->val);
                
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
        }

        return res;
    }
};
// @lc code=end

