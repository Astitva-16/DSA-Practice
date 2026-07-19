/*3997. Count Dominant Nodes in a Binary Tree
LeetCode link -> https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/
*/

// approach ->
/*
Use postorder DFS (Left → Right → Root) so that the maximum value of both subtrees is known before processing the current node.
Recursively find the maximum value in the left and right subtrees.
If the current node's value is greater than or equal to both subtree maximums, it is a dominant node, so increment the count.
Return the maximum value among the current node, left subtree, and right subtree to the parent.
After the DFS completes, return the final count.

Memory Trick:
Postorder → Get subtree maximum → If node >= leftMax and node >= rightMax, count it → Return subtree maximum.
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

    int maxi(TreeNode* root, int& cnt){

        if(!root) return INT_MIN;

        int leftmax = maxi(root -> left, cnt);
        int rightmax = maxi(root -> right, cnt);

        if(root -> val >= leftmax && root -> val >= rightmax){
            cnt++;
        }

        return max(root -> val, max(leftmax, rightmax));
        
    }

    int countDominantNodes(TreeNode* root) {
        int cnt = 0;

        maxi(root, cnt);

        return cnt;
    }
};
