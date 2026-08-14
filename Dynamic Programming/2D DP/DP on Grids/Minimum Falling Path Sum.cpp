/*931. Minimum Falling Path Sum
LeetCode link-> https://leetcode.com/problems/minimum-falling-path-sum/
*/

// RECURSION ->
/*
solve(i,j) = minimum falling path sum starting from (i,j).
If j goes outside the matrix, return INT_MAX (invalid path).
If we reach the last row, return mat[i][j].
From each cell, try 3 possible moves:
  Down → (i+1,j)
  Down-Left → (i+1,j-1)
  Down-Right → (i+1,j+1)
Take the minimum of these three paths and add the current cell:
mat[i][j] + min(down, downLeft, downRight).
Try starting from every column in the first row and return the minimum result.
*/
class Solution {
public:

    int solve(int i, int j, int n, vector<vector<int>>& mat){
        if(i < 0 || i >= n || j < 0 || j >= n) return INT_MAX;

        if(i == n - 1) return mat[i][j];

        int down = solve(i + 1, j, n, mat);
        int dow_left = solve(i + 1, j - 1, n, mat);
        int dow_right = solve(i + 1, j + 1, n, mat);

        return mat[i][j] + min({down, dow_left, dow_right});
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int ans = INT_MAX;

        for(int j = 0; j < n; j++){
            ans = min(ans, solve(0, j, n, mat));
        }

        return ans;
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i][j] = minimum falling path sum starting from (i,j).
If (i,j) is outside the matrix, return INT_MAX because it is an invalid path.
If i == n-1, return mat[i][j] because we reached the last row.
If dp[i][j] is already calculated, return it.
From each cell, try 3 moves:
  Down → (i+1,j)
  Down-Left → (i+1,j-1)
  Down-Right → (i+1,j+1)
Store:
dp[i][j] = mat[i][j] + min(down, downLeft, downRight).
Try every column in the first row and take the minimum.
*/
class Solution {
public:

    int solve(int i, int j, int n, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i < 0 || i >= n || j < 0 || j >= n) return INT_MAX;

        if(i == n - 1) return mat[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i + 1, j, n, mat, dp);
        int dow_left = solve(i + 1, j - 1, n, mat, dp);
        int dow_right = solve(i + 1, j + 1, n, mat, dp);

        return dp[i][j] = mat[i][j] + min({down, dow_left, dow_right});
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; j++){
            ans = min(ans, solve(0, j, n, mat, dp));
        }

        return ans;
    }
};




// TABULATION ->
/*
Create dp[i][j] = minimum falling path sum starting from (i,j).
Initialize the last row:
dp[n-1][j] = mat[n-1][j].
Traverse bottom-up from i = n-2 to 0.
For every cell, consider 3 possible moves:
  Down → dp[i+1][j]
  Down-Left → dp[i+1][j-1] if j > 0
  Down-Right → dp[i+1][j+1] if j < n-1
Calculate:
dp[i][j] = mat[i][j] + min(down, downLeft, downRight).
The path can start from any column in the first row, so return:
min(dp[0][j]).
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for(int j = 0; j < n; j++){
            dp[n - 1][j] = mat[n - 1][j];
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){

                int down = dp[i + 1][j];

                int dow_left = INT_MAX;
                int dow_right = INT_MAX;

                if(j > 0) dow_left = dp[i + 1][j - 1];

                if(j < n - 1) dow_right = dp[i + 1][j + 1];

                dp[i][j] = mat[i][j] + min({down, dow_left, dow_right});
            }
        }

        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};
