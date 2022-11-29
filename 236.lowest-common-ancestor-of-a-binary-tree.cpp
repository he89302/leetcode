/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (57.95%)
 * Likes:    12810
 * Dislikes: 312
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 * 
 * 
 * Example 1:
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * 
 * Example 2:
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * Example 3:
 * 
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pRecord;
        vector<TreeNode*> qRecord;
        TreeNode* res;
        bool r = false;

        r = DFS(root, p, pRecord);
        r = DFS(root, q, qRecord);

        int i = pRecord.size() - 1;
        int j = qRecord.size() - 1;

        while(i >= 0 && j >= 0) {
            if(pRecord[i] == qRecord[j])
                res = pRecord[i];
            i--;
            j--;
        }

        return res;
    }

private:
    bool DFS(TreeNode* tree, TreeNode* node, vector<TreeNode*>& record) {
        if(tree == nullptr) return false;

        if(tree == node || DFS(tree->left, node, record) || DFS(tree->right, node, record)) {
            record.push_back(tree);
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

