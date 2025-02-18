/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (48.31%)
 * Likes:    8204
 * Dislikes: 514
 * Total Accepted:    886.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * Given the roots of two binary trees root and subRoot, return true if there
 * is a subtree of root with the same structure and node values of subRoot and
 * false otherwise.
 * 
 * A subtree of a binary tree tree is a tree that consists of a node in tree
 * and all of this node's descendants. The tree tree could also be considered
 * as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the root tree is in the range [1, 2000].
 * The number of nodes in the subRoot tree is in the range [1, 1000].
 * -10^4 <= root.val <= 10^4
 * -10^4 <= subRoot.val <= 10^4
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

    bool isSame(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL and t2 == NULL) return true;
        if(t1==NULL or t2==NULL){
            return false;
        }
        if(t1->val != t2->val) return false;
        return (isSame(t1->left , t2->left) and isSame(t1->right,t2->right));
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root ==NULL and subRoot == NULL) return true;
        if(root == NULL or subRoot ==NULL) return false;
        if(isSame(root, subRoot)){
            return true;
        }
        return (isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot));
    }
};
// @lc code=end

