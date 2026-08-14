/*1277. Count Square Submatrices with All Ones
LeetCode link -> https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

// RECURSION ->
/*
solve(i,j) = number of all-1 squares whose bottom-right corner is (i,j).
If (i,j) is outside the matrix or mat[i][j] == 0, return 0.
If mat[i][j] == 1, calculate the maximum square size ending at (i,j):
  Up → solve(i-1,j)
  Diagonal → solve(i-1,j-1)
  Left → solve(i,j-1)
Current contribution:
1 + min(up, diag, left).
Why does this count squares?
If the maximum square size ending at (i,j) is k, then there are exactly k squares ending at that cell:
  1×1
  2×2
  ...
  k×k
Sum solve(i,j) for every cell to get the total number of squares.
*/
class Solution {
public:

    int solve(int i, int j, int n, int m, vector<vector<int>>& mat){
        if(i >= n || j >= m || i < 0 || j < 0 || mat[i][j] == 0) return 0;

        int up = solve(i - 1, j, n, m, mat);
        int diag = solve(i - 1, j - 1, n, m, mat);
        int left = solve(i, j - 1, n, m, mat);

        return 1 + min({up, diag, left});
    }

    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += solve(i, j, n, m, mat);
            }
        }

        return ans;
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i][j] = maximum size of an all-1 square ending at (i,j).
If (i,j) is outside the matrix or mat[i][j] == 0, return 0.
For a 1, calculate:
  up = solve(i-1, j)
  diag = solve(i-1, j-1)
  left = solve(i, j-1)
Maximum square size:
dp[i][j] = 1 + min(up, diag, left).
If dp[i][j] = k, then there are k squares ending at (i,j) (1×1, 2×2, ..., k×k).
Therefore, sum dp[i][j] for every cell to get the total number of squares.
*/
class Solution {
public:

    int solve(int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i >= n || j >= m || i < 0 || j < 0 || mat[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = solve(i - 1, j, n, m, mat, dp);
        int diag = solve(i - 1, j - 1, n, m, mat, dp);
        int left = solve(i, j - 1, n, m, mat, dp);

        return dp[i][j] = 1 + min({up, diag, left});
    }

    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += solve(i, j, n, m, mat, dp);
            }
        }

        return ans;
    }
};
