/*938. Range Sum of BST
LeetCode link -> https://leetcode.com/problems/range-sum-of-bst/
*/

// BRUTE FORCE -> not using BST property
/*
Perform an inorder DFS (Left → Root → Right) on the BST.
Recursively traverse the left subtree.
If the current node's value lies in the range [low, high], add it to sum.
Recursively traverse the right subtree.
After the traversal is complete, return the accumulated sum.
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

    int inOrder(TreeNode* root, int low, int high, int& sum){
        if(root == nullptr) return 0;

        inOrder(root -> left, low, high, sum);

        if(root -> val >= low && root -> val <= high){
            sum += root -> val;
        }

        inOrder(root -> right, low, high, sum);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        return inOrder(root, low, high, sum);
    }
};




// OPTIMAL -> using property of BST i.e. left child is smaller nd right is bigger
/*
If the current node is NULL, return 0.
If the current node's value lies in [low, high], add its value and recursively search both left and right subtrees.
If the current node's value is less than low, skip the left subtree and search only the right subtree (BST property).
If the current node's value is greater than high, skip the right subtree and search only the left subtree.
Return the total sum obtained.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;

        if(root -> val >= low && root -> val <= high){
            return root -> val + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
        }

        if(root -> val < low){
            return rangeSumBST(root -> right, low, high);
        }

        return rangeSumBST(root -> left, low, high);
    }
};
