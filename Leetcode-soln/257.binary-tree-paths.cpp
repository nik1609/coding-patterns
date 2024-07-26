/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (64.23%)
 * Likes:    6576
 * Dislikes: 298
 * Total Accepted:    749.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any
 * order.
 * 
 * A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: ["1"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 100].
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
    void helper(TreeNode* root, string path, vector<string>&ans){
        if(root==NULL){
            return ;
        }
        if(path.size()){
            path+="->";
          
        }
        path+=to_string(root->val);
        if(root->left==NULL and root->right==NULL){
            ans.push_back(path);
            return;
        }
        helper(root->left, path, ans);
        helper(root->right, path, ans);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path;
        helper(root, path, ans);
        return ans;
       

    }
};
// @lc code=end

