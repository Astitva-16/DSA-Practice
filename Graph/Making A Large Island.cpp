/*827. Making A Large Island
LeetCode link -> https://leetcode.com/problems/making-a-large-island/
*/

// approach ->
/*
Initialize a Disjoint Set (DSU) for all n × n cells.
Traverse the grid and union all adjacent 1s to form connected island components.
For every cell containing 0:
  Check its 4 neighbors.
  Collect the unique parent components of neighboring 1s (using a set to avoid duplicates).
  Island size = 1 + sum(size of all unique neighboring components).
  Update the maximum island size.
If the grid already contains all 1s, return the size of the largest existing component.
Return the maximum island size found.
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

    bool isValid(int row, int col, int n){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        // Step 1: Connect all adjacent 1's
        for(int row = 0; row < n; row++){

            for(int col = 0; col < n; col++){

                if(grid[row][col] == 0) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++){

                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1){

                        int nodeNo = row * n + col;
                        int adjNode = newRow * n + newCol;

                        ds.unionSz(nodeNo, adjNode);
                    }
                }
            }
        }

        // Step 2: Try converting every 0 into 1
        int maxi = 0;

        for(int row = 0; row < n; row++){

            for(int col = 0; col < n; col++){

                if(grid[row][col] == 1) continue;

                set<int> components;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++){

                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1){

                        int parent = ds.findParent(newRow * n + newCol);

                        components.insert(parent);
                    }
                }

                int sizeTotal = 1;

                for(auto parent : components){
                    sizeTotal += ds.size[parent];
                }

                maxi = max(maxi, sizeTotal);
            }
        }

        // Step 3: If grid is already full of 1's
        for(int cell = 0; cell < n * n; cell++){
            maxi = max(maxi, ds.size[ds.findParent(cell)]);
        }

        return maxi;
    }
};
