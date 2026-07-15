/*199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/
*/

// approach - BFS
/*Root ko queue me daal kar level order traversal (BFS) start karo.
Har level ke liye n = q.size() lo.
n nodes process karo:
Front node nikalo.
Left aur right child ko queue me push karo.
node ko current node se update karte raho.
Inner loop ke baad node last processed node hoga, jo us level ka rightmost node hai. Iska value answer me store karo.
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            TreeNode* node = nullptr;

            while(n--){
                node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);

                if(node -> right) q.push(node -> right);
            }
            ans.push_back(node -> val);
        }

        return ans;
    }
};




// appraoch - DFS
/*
Start a preorder DFS from the root with level = 1.
Visit the right child first, then the left child.
If ans.size() < level, it means this is the first node visited at that level, so add its value to ans.
Continue the recursion for the right and left subtrees.
Since the right subtree is visited first, the first node encountered at each level is the rightmost visible node.
Return ans.
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

    void preorder(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;

        if(ans.size() < level){
            ans.push_back(root -> val);
        }

        preorder(root -> right, level + 1, ans);
        preorder(root -> left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        preorder(root, 1, ans);

        return ans;
    }
};
