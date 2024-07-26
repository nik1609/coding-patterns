/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (58.45%)
 * Likes:    4385
 * Dislikes: 227
 * Total Accepted:    400.7K
 * Total Submissions: 685.6K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum absolute
 * difference between the values of any two different nodes in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,2,6,1,3]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 10^4].
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * Note: This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    

    int helperMin(TreeNode* root, int value){
        if(root==NULL) return value;
        int diff = abs(value-root->val);
        if(root->left) diff=min(diff,helperMin(root->left,value));
        if(root->right) diff=min(diff,helperMin(root->right, value));
        return diff;

    }

    int getMinimumDifference(TreeNode* root) {
        int rtl = INT_MAX;
        int rtr = INT_MAX;
        int lt =INT_MAX;
        int rt = INT_MAX;
        if(root->left) {
            lt = getMinimumDifference(root->left);
            rtl = helperMin(root->left,root->val);
        }
        if(root->right) {
            rt = getMinimumDifference(root->right);
            rtr = helperMin(root->right,root->val);
        }
        return min(rtl, min(rtr, min(lt,rt)));
        
    }
};
// @lc code=end

