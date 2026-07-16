/*958. Check Completeness of a Binary Tree
LeetCode link -> https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/

//BFS
/*
Start level order traversal (BFS) using a queue and push the root.
Maintain a boolean pastNULLseen = false.
While the queue is not empty:
If the current node is NULL, set pastNULLseen = true.
Otherwise, if pastNULLseen is already true, return false because a non-null node appeared after a null node.
Push the current node's left and right children into the queue (even if they are NULL).
If the traversal finishes without finding a non-null node after a null node, return true.
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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;

        q.push(root);

        bool pastNULLseen = false; // kya hmne past me koi null node dekha h?

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr){
                pastNULLseen = true;
            }
            
            else{
                if(pastNULLseen == true) return false;
            
                q.push(node -> left);
                q.push(node -> right);
            }

        }

        return true;
    }
};




//DFS
/*
Count the total number of nodes in the tree.
Start a DFS from the root with index 1 (like array representation of a binary tree).
For every node:
Left child gets index 2 * i.
Right child gets index 2 * i + 1.
If a node is NULL, return true (base case).
If the current node's index becomes greater than totalNodes, return false because a complete binary tree cannot have gaps.
Recursively check both left and right subtrees. The tree is complete only if both return true.
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

    int countNodes(TreeNode* root){
        if(!root) return 0;

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }

    bool dfs(TreeNode* root, int i, int totalNodes){
        if(root == nullptr) return true;

        if(i > totalNodes) return false;

        return dfs(root -> left, 2*i, totalNodes) && dfs(root -> right, 2*i + 1, totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);

        int i = 1;
        return dfs(root, i, totalNodes);
    }
};
