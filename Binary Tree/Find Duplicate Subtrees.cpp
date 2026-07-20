/*652. Find Duplicate Subtrees
LeetCode link -> https://leetcode.com/problems/find-duplicate-subtrees/
*/

// approach ->
/*
Use postorder DFS (Left → Right → Root) to serialize every subtree.
For each node, create a unique string:
  rootValue,leftSubtree,rightSubtree
  Use "N" for NULL nodes.
Store each subtree serialization in a hash map with its frequency.
If a serialization is seen for the second time (mp[s] == 1), add the current root to the answer.
Increment the frequency of the serialization and return it to the parent.
After DFS, return all collected duplicate subtree roots.
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

    string getSubTreeString(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& mp){

        if(!root) return "N";

        string s = to_string(root -> val) + "," + getSubTreeString(root -> left, res, mp) + "," + 
                                                    getSubTreeString(root -> right, res, mp);

        if(mp[s] == 1){
            res.push_back(root);
        }

        mp[s]++;

        return s;

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;

        vector<TreeNode*> res;

        getSubTreeString(root, res, mp);

        return res;
    }
};
