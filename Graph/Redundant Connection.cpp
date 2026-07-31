/*684. Redundant Connection
LeetCode link -> https://leetcode.com/problems/redundant-connection/
*/

// approach ->
/*
Initialize a Disjoint Set (DSU) where every node is its own parent.
Traverse each edge (u, v) one by one.
Before performing the union, check if u and v already have the same parent.
If they do, adding this edge creates a cycle, so this is the redundant edge. Return it.
Otherwise, union the two nodes using Union by Size.
If no redundant edge is found, return an empty vector.
*/

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;   // initialize size
        }
    }


    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }


    void unionSz(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u == v) return;


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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        DisjointSet ds(n + 1);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(ds.findParent(u) == ds.findParent(v)) return edge;

            ds.unionSz(u, v);
        }

        return {};
    }
};
