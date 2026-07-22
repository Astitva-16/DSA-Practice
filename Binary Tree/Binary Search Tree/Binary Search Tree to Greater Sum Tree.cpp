/*1038. Binary Search Tree to Greater Sum Tree
LeetCode link -> https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/

// approach
/*
Perform a reverse inorder traversal (Right → Root → Left) so nodes are visited from largest to smallest.
Maintain a running variable sum to store the sum of all previously visited (greater) nodes.
At each node:
  Add the current node's value to sum.
  Update the node's value to sum.
Continue the traversal for the left subtree.
After the traversal, every node contains the sum of all values greater than or equal to itself.
*/

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

    void solve(TreeNode* root, int& sum){
        if(!root) return;

        solve(root -> right, sum);

        sum += root -> val;
        root -> val = sum;
        
        solve(root -> left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;

        solve(root, sum);

        return root;
    }
};
