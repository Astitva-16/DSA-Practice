/*1020. Number of Enclaves
LeetCode link -> https://leetcode.com/problems/number-of-enclaves/
*/

// approach - >
/*
Create a visited matrix to mark land cells connected to the boundary.
Start DFS from all boundary land cells (1) (first row, last row, first column, last column).
During DFS, mark all connected land cells as visited since they can reach the boundary.
After marking all boundary-connected land, traverse the entire grid.
Count all cells that are land (1) but not visited. These are the enclaves.
Return the count.
*/

class Solution {
public:

    int drow[4] = {0, 0, 1, -1};
    int dcol[4] = {1, -1, 0, 0};

    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int n, int m){
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && 
                grid[nrow][ncol] == 1){
                    dfs(nrow, ncol, vis, grid, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){

            if(vis[i][0] == 0 && grid[i][0] == 1){
                dfs(i, 0, vis, grid, n, m);
            }

            if(vis[i][m - 1] == 0 && grid[i][m - 1] == 1){
                dfs(i, m - 1, vis, grid, n, m);
            }

        }

        for(int j = 0; j < m; j++){

            if(vis[0][j] == 0 && grid[0][j] == 1){
                dfs(0, j, vis, grid, n, m);
            }

            if(vis[n - 1][j] == 0 && grid[n - 1][j] == 1){
                dfs(n - 1, j, vis, grid, n, m);
            }

        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
