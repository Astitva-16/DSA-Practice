/*113. Path Sum II
LeetCode link -> https://leetcode.com/problems/path-sum-ii/
*/

//approach ->
/*
Use DFS while maintaining:
  sum = current path sum.
  temp = current root-to-node path.
At each node:
  Add the node's value to sum.
  Push the node's value into temp.
If the current node is a leaf:
  If sum == targetSum, add temp to the answer.
  Return.
Recursively explore the left and right subtrees with the updated sum and temp.
After all paths are explored, return the result.
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

    vector<vector<int>> res;

    void fill(TreeNode* root, vector<int> temp, int sum, int& targetSum){
        if(!root) return;

        sum += root -> val;

        temp.push_back(root -> val);

        if(root -> left == nullptr && root -> right == nullptr){
            if(sum == targetSum){
                res.push_back(temp);
            }
            return;
        }

        fill(root -> left, temp, sum, targetSum);
        fill(root -> right, temp, sum, targetSum);

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        vector<int> temp;

        fill(root, temp, sum, targetSum);

        return res;
    }
};
