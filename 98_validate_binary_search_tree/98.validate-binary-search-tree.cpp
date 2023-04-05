/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (31.96%)
 * Likes:    14279
 * Dislikes: 1167
 * Total Accepted:    1.9M
 * Total Submissions: 5.9M
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 * 
 * A valid BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: root = [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is
 * 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, long left, long right) {
        // int a = left;
        // int b = right;
        if(root == nullptr) return true;
        else if(root->val >= right || root->val <= left) return false;
        // cout<< "root val : " + to_string(root->val) + " left : " << to_string(a) + " and right : " + to_string(b) << "\n";
        else
        return isValidBST(root->left, left, root->val) &&
               isValidBST(root->right, root->val, right);
    }
};
// @lc code=end

