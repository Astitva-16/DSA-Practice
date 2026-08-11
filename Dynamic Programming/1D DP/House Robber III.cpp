/*337. House Robber III
Leetcode link -> https://leetcode.com/problems/house-robber-iii
*/

// RECURSION ->
/*
At every tree node, there are 2 choices: rob or skip the current node.
Rob current node: Add root->val, but you cannot rob its children, so take the maximum from its grandchildren.
Skip current node: You can freely rob its children, so calculate solve(root->left) + solve(root->right).
Return the maximum of rob and skip.
Base case: if root == NULL, return 0.
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

    int solve(TreeNode* root){
        if(!root) return 0;

        int rob = root -> val;

        if(root -> left){
            rob += solve(root -> left -> left);
            rob += solve(root -> left -> right);
        }

        if(root -> right){
            rob += solve(root -> right -> left);
            rob += solve(root -> right -> right);
        }

        int skip = solve(root -> left) + solve(root -> right);

        return max(rob, skip);
    }

    int rob(TreeNode* root) {
        return solve(root);
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[root] stores the maximum money that can be robbed from the subtree rooted at root.
At each node, make 2 choices:
  Rob current: take root->val + maximum from its grandchildren.
  Skip current: take maximum from its left and right children.
If the result for the current node is already in dp, return it to avoid recalculating the subtree.
Store max(rob, skip) in dp[root].
Return the result for the root.
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

    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root) return 0;

        if(dp.count(root)) return dp[root];

        int rob = root -> val;

        if(root -> left){
            rob += solve(root -> left -> left, dp);
            rob += solve(root -> left -> right, dp);
        }

        if(root -> right){
            rob += solve(root -> right -> left, dp);
            rob += solve(root -> right -> right, dp);
        }

        int skip = solve(root -> left, dp) + solve(root -> right, dp);

        return dp[root] = max(rob, skip);
    }

    int rob(TreeNode* root) {

        unordered_map<TreeNode*, int> dp;

        return solve(root, dp);
    }
};




// TABULATION /BOTTOM-UP ->
/*
For every node, return a pair {steal, skip}:
  steal = maximum money if we rob this node.
  skip = maximum money if we don't rob this node.
Recursively calculate the pair for the left and right children.
If we steal current node, we cannot steal its children:
  steal = root->val + left.skip + right.skip
If we skip current node, we can either steal or skip each child:
  skip = max(left.steal, left.skip) + max(right.steal, right.skip)
Return {steal, skip} for the current node.
At the root, return max(steal, skip).
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

    typedef pair<int, int> p;

    p solve(TreeNode* root){
        if(!root) return {0, 0};

        p left = solve(root -> left);
        p right = solve(root -> right);

        int steal = root -> val + left.second + right.second;

        int skip = max(left.first , left.second) + max(right.first, right.second);

        return {steal, skip};
    }

    int rob(TreeNode* root) {
        p ans = solve(root);

        return max(ans.first, ans.second);
    }
};
