/*872. Leaf-Similar Trees
LeetCode link -> https://leetcode.com/problems/leaf-similar-trees/
*/

// approach ->
/*
Perform a DFS on both trees.
Whenever a leaf node is found (left == NULL && right == NULL), append its value to a string (or list) in left-to-right order.
Ignore all non-leaf nodes and continue traversing both subtrees.
Repeat the same process for both trees.
Compare the two leaf sequences. If they are equal, return true; otherwise return false.
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

    void inOrder(TreeNode* root, string& s){
        if(!root) return;

        // leaf node
        if(root -> left == nullptr && root -> right == nullptr){
            s += to_string(root -> val) + "_";
            return;
        }

        inOrder(root -> left, s);
        inOrder(root -> right, s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";

        inOrder(root1, s1);
        inOrder(root2, s2);

        return (s1 == s2);
    }
};
