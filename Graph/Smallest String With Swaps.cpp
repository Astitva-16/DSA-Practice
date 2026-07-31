/*1202. Smallest String With Swaps
LeetCode link -> https://leetcode.com/problems/smallest-string-with-swaps/
*/

// approach ->
/*
Initialize a Disjoint Set (DSU) for all indices of the string.
Traverse all swap pairs and union the connected indices (they belong to the same component).
Group all indices by their parent (each group represents indices that can be freely swapped).
For each component:
  Collect the characters at those indices.
  Sort the characters in ascending order.
Place the sorted characters back at the component's indices (indices are already in increasing order).
Return the final smallest lexicographical string.
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.size();

        DisjointSet ds(n);

        // Step 1: Build components
        for(auto &p : pairs){
            ds.unionSz(p[0], p[1]);
        }

        // Step 2: Group indices by parent
        unordered_map<int, vector<int>> groups;

        for(int i = 0; i < n; i++){
            groups[ds.findParent(i)].push_back(i);
        }

        string ans = s;

        // Step 3: Sort characters inside each component
        for(auto &it : groups){

            vector<int> indices = it.second;
            vector<char> chars;

            for(int idx : indices){
                chars.push_back(s[idx]);
            }

            sort(chars.begin(), chars.end());

            for(int i = 0; i < indices.size(); i++){
                ans[indices[i]] = chars[i];
            }
        }

        return ans;
    }
};
