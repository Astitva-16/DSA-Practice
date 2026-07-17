/*112. Path Sum
LeetCode link -> https://leetcode.com/problems/path-sum/
*/

// approach ->
/*
Use DFS while maintaining the current path sum.
At each node, add the node's value to sum.
If the current node is a leaf:
  If sum == targetSum, return true.
Otherwise, recursively check the left and right subtrees.
Return true if either subtree has a valid path; otherwise return false.
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

    bool inOrder(TreeNode* root, int sum, int& targetSum){
        if(!root) return false;

        sum += root -> val;

        if(root -> left == nullptr && root -> right == nullptr){
            if(sum == targetSum){
                return true;
            }
        }

        return inOrder(root -> left, sum, targetSum) || inOrder(root -> right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        return inOrder(root, sum, targetSum);
    }
};
