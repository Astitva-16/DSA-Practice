/*199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/
*/

// approach - 
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
