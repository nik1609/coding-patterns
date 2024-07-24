/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (60.99%)
 * Likes:    13859
 * Dislikes: 1018
 * Total Accepted:    1.6M
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, return the length of the diameter of the
 * tree.
 * 
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 * 
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int>heightDiameter(TreeNode *root){
        if(root == NULL) return {0,0};
        pair<int, int> leftHeightDiameter = heightDiameter(root->left);
        pair<int, int> rightHeightDiameter = heightDiameter(root->right);
        pair<int , int> ans;
        ans.first = max(leftHeightDiameter.first, rightHeightDiameter.first)+1;
        ans.second = max(leftHeightDiameter.second, max(rightHeightDiameter.second, leftHeightDiameter.first + rightHeightDiameter.first ));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return heightDiameter(root).second;
    }
};
// @lc code=end

