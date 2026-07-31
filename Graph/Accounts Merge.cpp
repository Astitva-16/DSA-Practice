/*721. Accounts Merge
LeetCode link -> https://leetcode.com/problems/accounts-merge/
*/

// approach ->
/*
Initialize a Disjoint Set (DSU) where each account is its own parent.
Traverse every account and map each email → account index.
  If an email is seen for the first time, store its account index.
  If the email already exists, union the current account with the previous account.
After all unions, group every email under its ultimate parent account.
Sort the emails of each merged account.
Create the final answer by adding:
  Account name (from the parent account).
  All sorted unique emails.
Return all merged accounts.
*/

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSz(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mailToNode;

        // Step 1: Union accounts having common email
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                }
                else {
                    ds.unionSz(i, mailToNode[mail]);
                }
            }
        }

        // Step 2: Store emails of each parent
        vector<vector<string>> mergedMail(n);

        for (auto &it : mailToNode) {

            string mail = it.first;
            int node = it.second;

            int parent = ds.findParent(node);

            mergedMail[parent].push_back(mail);
        }

        // Step 3: Build answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].size() == 0)
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
