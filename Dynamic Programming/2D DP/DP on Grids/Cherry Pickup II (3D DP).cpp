/*1463. Cherry Pickup II
LeetCode link -> https://leetcode.com/problems/cherry-pickup-ii/
*/

// RECURSION ->
/*
Two robots start at (0,0) and (0,m-1) and move row by row downward.
solve(i, j1, j2) = maximum chocolates collectable from row i, when robots are at columns j1 and j2.
If either column goes outside the grid, return INT_MIN (invalid move).
Calculate chocolates collected in the current row:
  Same column → count grid[i][j1] once.
  Different columns → count both cells.
If this is the last row, return the current chocolates.
Try all 9 combinations of movements:
  Robot 1: -1, 0, +1
  Robot 2: -1, 0, +1
Take the maximum among all possibilities.
*/
class Solution {
  public:
  
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j1, int j2){
        
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return INT_MIN;
        
        int chocolates;
        
        if(j1 == j2) chocolates = grid[i][j1];
        
        else chocolates = grid[i][j1] + grid[i][j2];
        
        if(i == n - 1) return chocolates;
        
        int ans = INT_MIN;
        
        for(int d1 = -1; d1 <= 1; d1++){
            for(int d2 = -1; d2 <= 1; d2++){
                
                ans = max(ans, chocolates + solve(grid, n, m, i + 1, j1 + d1, j2 + d2));
                
            }
        }
        
        return ans;
    }
  
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        return solve(grid, n, m, 0, 0, m - 1);
        
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i][j1][j2] stores the maximum chocolates collectable from row i when Robot 1 is at j1 and Robot 2 at j2.
If either robot goes out of bounds, return INT_MIN (invalid path).
Calculate current chocolates:
  Same column → count the cell once.
  Different columns → add both cells.
If i == n-1, return the chocolates collected in the last row.
If dp[i][j1][j2] is already computed, return it.
Try all 9 possible combinations of movements (-1, 0, +1 for each robot).
Store the maximum result in dp[i][j1][j2].
*/
class Solution {
  public:
  
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>>& dp){
        
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return INT_MIN;
        
        int chocolates;
        
        if(j1 == j2) chocolates = grid[i][j1];
        
        else chocolates = grid[i][j1] + grid[i][j2];
        
        if(i == n - 1) return chocolates;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int ans = INT_MIN;
        
        for(int d1 = -1; d1 <= 1; d1++){
            for(int d2 = -1; d2 <= 1; d2++){
                
                ans = max(ans, chocolates + solve(grid, n, m, i + 1, j1 + d1, j2 + d2, dp));
                
            }
        }
        
        return dp[i][j1][j2] = ans;
    }
  
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(grid, n, m, 0, 0, m - 1, dp);
        
    }
};
