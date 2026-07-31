/*1319. Number of Operations to Make Network Connected
LeetCode link -> https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

// approach ->
/*
Initialize a Disjoint Set (DSU) where every computer is its own parent.
Traverse all connections:
  If both computers already have the same parent, it's an extra edge.
  Otherwise, union them.
After processing all edges, count the number of connected components (nodes that are their own parent).
To connect all components, the required number of cables is components - 1.
If the number of extra edges ≥ required cables, return components - 1; otherwise return -1.
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);

        int extraEdge = 0;
        for(auto& edge : connections){
            int u = edge[0];
            int v = edge[1];

            if(ds.findParent(u) == ds.findParent(v)){
                extraEdge++;
            }

            else ds.unionSz(u, v);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i){
                components++;
            }
        }

        int reqCompo = components - 1;

        return (extraEdge >= reqCompo) ? reqCompo : -1;
    }
};
