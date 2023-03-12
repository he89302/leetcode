/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (60.74%)
 * Likes:    11892
 * Dislikes: 345
 * Total Accepted:    909.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 * 
 * 
 * Example 1:
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * left : preorder_start + 1, preorder_end = inorder[preorder_index]
 * right : inorder_start + 1
 * 
 * Example 2:
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * inorder => find root and 分成left tree, right tree
 * preorder => pre[0] is root
 * 
 * Constraints:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> recordInorder;

        for (int i = 0; i < inorder.size(); i++) {
            recordInorder[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(preorder, 0,
                                   inorder, 0, inorder.size() - 1,
                                   recordInorder);

        return root;
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int preorder_start,
                        vector<int>& inorder, int inorder_start, int inorder_end,
                        unordered_map<int, int>& record) {
                            if(preorder.size() <= preorder_start || inorder_end < inorder_start) return NULL;

                            TreeNode* root = new TreeNode(preorder[preorder_start]);

                            int index = record[preorder[preorder_start]];
                            root->left = buildTree(preorder, preorder_start + 1,
                                                    inorder, inorder_start, index - 1, record);
                            root->right = buildTree(preorder, preorder_start + index - inorder_start + 1,
                                                    inorder, index + 1, inorder_end, record);
                            return root;
                        }
};
// @lc code=end

