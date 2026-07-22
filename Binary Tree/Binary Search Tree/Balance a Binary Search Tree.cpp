/*1382. Balance a Binary Search Tree
LeetCode link -> https://leetcode.com/problems/balance-a-binary-search-tree/
*/

// approach ->
/*
Perform an inorder traversal to store all node values in a sorted vector (since inorder of a BST is sorted).
Use the sorted vector to construct a balanced BST.
Pick the middle element as the root.
Recursively build the left subtree from the left half and the right subtree from the right half.
Return the newly constructed balanced BST.
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

    void inOrder(TreeNode* root, vector<int>& vec){
        if(!root) return;

        inOrder(root -> left, vec);
        
        vec.push_back(root -> val);

        inOrder(root -> right, vec);
    }

    TreeNode* construct(int low, int high, vector<int>& vec){
        if(low > high) return nullptr;

        int mid = low + (high - low) / 2;

        TreeNode* root = new TreeNode(vec[mid]);

        root -> left = construct(low, mid - 1, vec);
        root -> right = construct(mid + 1, high, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;

        inOrder(root, vec);

        int low = 0, high = vec.size() - 1;

        return construct(low, high, vec);
    }
};
