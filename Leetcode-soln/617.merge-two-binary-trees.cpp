/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (79.03%)
 * Likes:    8774
 * Dislikes: 301
 * Total Accepted:    782.1K
 * Total Submissions: 989.7K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * You are given two binary trees root1 and root2.
 * 
 * Imagine that when you put one of them to cover the other, some nodes of the
 * two trees are overlapped while the others are not. You need to merge the two
 * trees into a new binary tree. The merge rule is that if two nodes overlap,
 * then sum node values up as the new value of the merged node. Otherwise, the
 * NOT null node will be used as the node of the new tree.
 * 
 * Return the merged tree.
 * 
 * Note: The merging process must start from the root nodes of both trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * Output: [3,4,5,5,4,null,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [1], root2 = [1,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in both trees is in the range [0, 2000].
 * -10^4 <= Node.val <= 10^4
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL and root2 == NULL) return NULL;
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};
// @lc code=end

