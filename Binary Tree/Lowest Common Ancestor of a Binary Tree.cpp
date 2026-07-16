/*236. Lowest Common Ancestor of a Binary Tree
LeetCode link -> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

//approach - 
/*
If root == NULL, return NULL.
If the current node is p or q, return the current node.
Recursively search for p and q in the left and right subtrees.
If both left and right return non-NULL, it means p and q are found in different subtrees, so the current node is the LCA.
If only one side returns a non-NULL node, return that node since it is either the LCA or one of the target nodes.
If both sides return NULL, return NULL.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if(left != nullptr && right != nullptr) return root;

        if(left != nullptr) return left;

        return right;
    }
};

