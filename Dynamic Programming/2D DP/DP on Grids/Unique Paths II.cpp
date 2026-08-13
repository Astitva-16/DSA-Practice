/*63. Unique Paths II
LeetCode link -> https://leetcode.com/problems/unique-paths-ii/
*/

// RECURSION ->
/*
Start from (0,0) and try to reach (n-1,m-1).
If the current cell is an obstacle (1) or outside the grid, return 0.
If we reach the destination, return 1.
From each valid cell, try both directions:
  Down → solve(i+1, j)
  Right → solve(i, j+1)
Add both results because they represent all possible paths.
If the destination itself is an obstacle, directly return 0.
*/
class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& mat, int n, int m){
        if(i == n - 1 && j == m - 1) return 1;

        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != 0) return 0;

        int right = solve(i + 1, j, mat, n, m);
        int down = solve(i, j + 1, mat, n, m);

        return right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if(mat[n - 1][m - 1] != 0) return 0;

        return solve(0, 0, mat, n, m);
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i][j] stores the number of valid paths from (i,j) to the destination.
If the cell is outside the grid or an obstacle (1), return 0.
If we reach the destination, return 1.
If dp[i][j] is already calculated, return it.
From each valid cell, try:
  Down → solve(i+1, j)
  Right → solve(i, j+1)
Store right + down in dp[i][j].
If the destination is an obstacle, directly return 0.
*/
class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& mat, int n, int m, vector<vector<int>>& dp){
        if(i == n - 1 && j == m - 1) return 1;

        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i + 1, j, mat, n, m, dp);
        int down = solve(i, j + 1, mat, n, m, dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if(mat[n - 1][m - 1] != 0) return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, mat, n, m, dp);
    }
};
