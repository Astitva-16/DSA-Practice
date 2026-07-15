/*105. Construct Binary Tree from Preorder and Inorder Traversal
LeetCode link -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

//appraoch
/*
Store each value's index in the inorder array in a hash map for O(1) lookup.
Maintain an index idx for the preorder array. preorder[idx] is always the current root.
Create the root node and find its position in the inorder array using the map.
Elements left of the root in the inorder array belong to the left subtree, and elements right of the root belong to the right subtree.
Recursively build the left subtree first, then the right subtree, while incrementing idx after creating each root.
When start > end, return NULL (base case).
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
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int> &preorder, vector<int>& inorder, int start, int end, int &idx){
        if(start > end) return nullptr;

        int rootVal = preorder[idx];
        int inorderIdx = mp[rootVal];

        idx++;

        TreeNode* root = new TreeNode(rootVal);

        root -> left = solve(preorder, inorder, start, inorderIdx - 1, idx);
        root -> right = solve(preorder, inorder, inorderIdx + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        int idx = 0;

        return solve(preorder, inorder, 0, n - 1, idx);
    }
};
