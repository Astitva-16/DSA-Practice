/*62. Unique Paths
Leetcode link -> https://leetcode.com/problems/unique-paths/
*/

// RECURSION ->
/*
Start from the top-left (0,0) and try to reach the bottom-right (m-1,n-1).
If we reach the destination, return 1 because we found one valid path.
If we go outside the grid, return 0 because that path is invalid.
From every cell, there are only 2 choices:
  Move right → solve(i, j+1)
  Move down → solve(i+1, j)
Add both results because they represent different valid paths.
Return right + down.
*/
class Solution {
public:

    int solve(int i, int j, int m, int n){
        if(i == m - 1 && j == n - 1) return 1;

        if(i < 0 || j < 0 || i >= m || j >= n) return 0;

        int right = solve(i, j + 1, m, n);
        int down = solve(i + 1, j, m, n);

        return right + down;
    }

    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i][j] stores the number of paths from cell (i,j) to the destination.
If (i,j) is the bottom-right cell, return 1 (one valid path).
If the cell is outside the grid, return 0.
If dp[i][j] is already calculated, return it.
From each cell, try:
  Right → solve(i, j+1)
  Down → solve(i+1, j)
Store and return:
dp[i][j] = right + down.
*/
class Solution {
public:

    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m - 1 && j == n - 1) return 1;

        if(i < 0 || j < 0 || i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, m, n, dp);
        int down = solve(i + 1, j, m, n, dp);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, dp);
    }
};
