/*222. Count Complete Tree Nodes
LeetCode link -> https://leetcode.com/problems/count-complete-tree-nodes/
*/

// approach -> 
/*
If the tree is empty, return 0.
Find the leftmost height (lh) by continuously moving to the left child.
Find the rightmost height (rh) by continuously moving to the right child.
If lh == rh, the tree is a perfect binary tree, so directly return 2^lh - 1.
Otherwise, recursively count the nodes in the left and right subtrees and return: 1 + leftCount + rightCount.
Continue until all subtrees are processed.
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

    int getLeftHeight(TreeNode* root){
        TreeNode* temp = root;
        int lh = 0;

        while(temp){
            temp = temp -> left;
            lh++;
        }

        return lh;

    }

    int getRightHeight(TreeNode* root){
        TreeNode* temp = root;
        int rh = 0;

        while(temp){
            temp = temp -> right;
            rh++;
        }

        return rh;

    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if(lh == rh) {//means perfect binary tree 
            return (pow(2, lh) - 1);
        }

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
