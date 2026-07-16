/*1110. Delete Nodes And Return Forest
LeetCode link -> https://leetcode.com/problems/delete-nodes-and-return-forest/
*/

// approach
/*
Store all values to be deleted in an unordered_set for O(1) lookup.
Perform a postorder DFS (Left → Right → Root) so children are processed before their parent.
Recursively update the left and right child pointers after processing their subtrees.
If the current node's value is in the delete set:
If its left child exists, add it to the result (it becomes a new tree root).
If its right child exists, add it to the result.
Return NULL to delete the current node from its parent.
If the current node is not deleted, simply return it.
After DFS, if the original root was not deleted, add it to the result.
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

    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& res){
        if(!root) return nullptr;

        root -> left = deleteHelper(root -> left, st, res);
        root -> right = deleteHelper(root -> right, st, res);

        if(st.find(root -> val) != st.end()){

            if(root -> left != nullptr) res.push_back(root -> left);

            if(root -> right != nullptr) res.push_back(root -> right);

            return nullptr;
        }

        else{
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;

        unordered_set<int> st;

        for(auto& it : to_delete){
            st.insert(it);
        }

        deleteHelper(root, st, res);

        if(st.find(root -> val) == st.end()){
            res.push_back(root);
        }

        return res;
    }
};
