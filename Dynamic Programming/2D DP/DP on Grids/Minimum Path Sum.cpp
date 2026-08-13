/*64. Minimum Path Sum
LeetCode link -> https://leetcode.com/problems/minimum-path-sum/
*/

// RECURSION ->
/*
Start from (0,0) and reach (n-1,m-1).
If we reach the destination, return its value grid[i][j].
If we go outside the grid, return INT_MAX so that invalid paths are never selected.
From each cell, try:
  Down → solve(i+1, j)
  Right → solve(i, j+1)
Take the minimum of both paths and add the current cell's value:
grid[i][j] + min(right, down).
*/
class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i == n - 1 && j == m - 1) return grid[i][j];

        if(i < 0 || j < 0 || i >= n || j >= m) return INT_MAX;

        int right = solve(i + 1, j, grid, n, m);
        int down = solve(i, j + 1, grid, n, m);

        return grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return solve(0, 0, grid, n, m);
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i][j] stores the minimum path sum from (i,j) to the destination.
If (i,j) is the destination, return grid[i][j].
If outside the grid, return INT_MAX so that path is ignored.
If dp[i][j] is already calculated, return it.
From each cell, try:
  Down → solve(i+1, j)
  Right → solve(i, j+1)
Take the minimum and add the current cell:
dp[i][j] = grid[i][j] + min(right, down).
Return dp[0][0].
*/
class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp){
        if(i == n - 1 && j == m - 1) return grid[i][j];

        if(i < 0 || j < 0 || i >= n || j >= m) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i + 1, j, grid, n, m, dp);
        int down = solve(i, j + 1, grid, n, m, dp);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, grid, n, m, dp);
    }
};
