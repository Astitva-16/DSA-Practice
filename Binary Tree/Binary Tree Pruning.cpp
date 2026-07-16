/*814. Binary Tree Pruning
LeetCode link -> https://leetcode.com/problems/binary-tree-pruning/
*/

//Brute force
/*
isOnePresent() checks whether a subtree contains at least one node with value 1.
In pruneTree(), first check the left and right subtrees.
If a subtree does not contain any 1, set that child pointer to NULL (prune it).
Recursively prune the remaining left and right subtrees.
After pruning, if the current node is a leaf with value 0, return NULL because it should also be removed.
Otherwise, return the current node.
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

    bool isOnePresent(TreeNode* root){
        if(!root) return false;

        if(root -> val == 1) return true;

        return isOnePresent(root -> left) || isOnePresent(root -> right);
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;

        if(!isOnePresent(root -> left)){
            root -> left = nullptr;
        }

        if(!isOnePresent(root -> right)){
            root -> right = nullptr;
        }

        pruneTree(root -> left);
        pruneTree(root -> right);

        if(root -> left == nullptr && root -> right == nullptr && root -> val == 0) return nullptr;

        return root;
    }
};




// optimal
/*
Use postorder DFS (Left → Right → Root) so children are processed before the parent.
Recursively prune the left subtree and update root->left.
Recursively prune the right subtree and update root->right.
After both children are processed:
If the current node has at least one child or its value is 1, keep the node.
Otherwise, it is a leaf with value 0, so return NULL (prune it).
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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;

        root -> left = pruneTree(root -> left);

        root -> right = pruneTree(root -> right);

        return (root -> left != nullptr || root -> right != nullptr || root -> val == 1) ? root : nullptr;
    }
};
