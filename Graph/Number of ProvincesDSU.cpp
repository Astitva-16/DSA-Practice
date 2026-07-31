/*547. Number of Provinces
LeetCode link -> https://leetcode.com/problems/number-of-provinces/
*/

// approach ->
/*
Initialize a Disjoint Set (DSU) where every city is its own parent.
Traverse the adjacency matrix.
If isConnected[i][j] == 1, union the two cities (they belong to the same province).
Use Path Compression in findParent() and Union by Size in unionSz() for efficiency.
After processing all connections, count how many nodes are their own parent.
That count is the number of provinces.
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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSet ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionSz(i, j);
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(ds.findParent(i) == i) cnt++;
        }

        return cnt;
        
    }
};
