/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (76.66%)
 * Likes:    13487
 * Dislikes: 791
 * Total Accepted:    2.6M
 * Total Submissions: 3.4M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
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
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        // iterative Code:
        stack<TreeNode*> s;
        TreeNode* currentNode;
        vector<int>ans;
        currentNode = root;
        while(true){
            if(currentNode!=NULL){ // traverse to the leftmost node
                s.push(currentNode);
                currentNode=currentNode->left;
            }
            else if(s.empty()){ // if empty meaning no more node left
                return ans;
            }
            else{// if currentNode=NULL means reached leaf node and time to go to previous node
                ans.push_back(s.top()->val);
                currentNode= s.top()->right;
                s.pop();

            }
        }
    }
};
// @lc code=end

