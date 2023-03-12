/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (38.41%)
 * Likes:    13397
 * Dislikes: 627
 * Total Accepted:    932.9K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3]'
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only appear in
 * the sequence at most once. Note that the path does not need to pass through
 * the root.
 * 
 * The path sum of a path is the sum of the node's values in the path.
 * 
 * Given the root of a binary tree, return the maximum path sum of any
 * non-empty path.
 * 
 * 
 * Example 1:
 * 
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 =
 * 6.
 * 
 * 
 * Example 2:
 * 
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 +
 * 7 = 42.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 3 * 10^4].
 * -1000 <= Node.val <= 1000
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

/*
 * THINK : using binary tree DFS and terminal cond. is root == nullptr return 0
 * left + root + right => all(or partion) binary tree sum of nums
 * calc left sum and right sum 
 * and max(left sum + right sum + root, maxSum)
*/
class Solution {
    int pathSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        calcMaxPathSum(root);
        return pathSum;
    }

private:
    int calcMaxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftSum = max(calcMaxPathSum(root->left), 0);
        int rightSum = max(calcMaxPathSum(root->right), 0);
        pathSum = max(pathSum, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
    }
};
// @lc code=end

