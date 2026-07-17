/*623. Add One Row to Tree
LeetCode link -> https://leetcode.com/problems/add-one-row-to-tree/
*/

//approach ->
/*
If depth == 1, create a new root with value val and make the original tree its left child.
Otherwise, use DFS to reach all nodes at depth - 1.
When curr == depth - 1:
  Save the original left and right children.
  Create two new nodes with value val.
  Attach the original left subtree to the left of the new left node.
  Attach the original right subtree to the right of the new right node.
For other nodes, recursively process the left and right subtrees.
Return the updated root.
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

    TreeNode* add(TreeNode* root, int val, int depth, int curr){
        if(!root) return nullptr;

        if(curr == depth - 1){
            TreeNode* leftTemp = root -> left;
            TreeNode* rightTemp = root -> right;

            root -> left = new TreeNode(val);
            root -> right = new TreeNode(val);

            root -> left -> left = leftTemp;
            root -> right -> right = rightTemp;

            return root;
        }

        root -> left = add(root -> left, val, depth, curr + 1);
        root -> right = add(root -> right, val, depth, curr + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;

            return newRoot;
        }

        int curr = 1;

        return add(root, val, depth, curr);
    }
};
