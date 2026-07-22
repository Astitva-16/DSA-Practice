/*200. Number of Islands
Leetcode link -> https://leetcode.com/problems/number-of-islands/
*/

// approach ->
/*
Traverse every cell of the grid.
If a cell contains '1' (land), a new island is found:
  Increment the island count.
  Start a DFS from that cell.
In DFS:
  If the cell is out of bounds or not '1', return.
  Mark the current cell as visited (change '1' to 'V').
  Recursively visit all 4 directions (up, down, left, right).
DFS marks the entire connected island as visited.
After scanning the whole grid, return the island count.
*/

class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;

        grid[i][j] = 'V';

        dfs(i+1, j, grid, n, m);
        dfs(i-1, j, grid, n, m);
        dfs(i, j+1, grid, n, m);
        dfs(i, j-1, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid, n, m);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
