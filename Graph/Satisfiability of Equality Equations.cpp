/*990. Satisfiability of Equality Equations
LeetCode link -> https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

// approach ->
/*
Initialize a Disjoint Set (DSU) for the 26 lowercase letters.
Traverse all equations:
  If the equation is "==", union the two variables (they must belong to the same set).
Traverse all equations again:
  If the equation is "!=", check whether both variables have the same parent.
If any unequal pair belongs to the same set, return false.
If no contradiction is found, return true.
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
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();

        DisjointSet ds(26);

        for(auto s : equations){
            if(s[1] == '='){
                ds.unionSz(s[0] - 'a', s[3] - 'a');
            }
        }

        for(auto s : equations){
            if(s[1] == '!'){
                int parent0 = ds.findParent(s[0] - 'a');
                int parent3 = ds.findParent(s[3] - 'a');

                if(parent0 == parent3) return false;
            }
        }
        return true;
    }
};
