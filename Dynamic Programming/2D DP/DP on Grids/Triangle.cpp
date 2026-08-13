/*120. Triangle
Leetcode link -> https://leetcode.com/problems/triangle/
*/

// RECURSION ->
/*
Start from the top (0,0) and reach any element in the last row.
If we reach the last row, return triangle[i][j].
From each element, there are 2 choices:
  Down → (i+1, j)
  Diagonal → (i+1, j+1)
Recursively calculate both paths and take the minimum.
Add the current value:
triangle[i][j] + min(down, diag).
Return the result from (0,0).
*/
class Solution {
public:

    int solve(int i, int j, int n, vector<vector<int>>& triangle){
        if(i == n - 1) return triangle[n - 1][j];

        if(i >= n || j >= n) return INT_MAX;

        int down = solve(i + 1, j, n, triangle);
        int diag = solve(i + 1, j + 1, n, triangle);

        return triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        return solve(0, 0, n, triangle);
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i][j] stores the minimum path sum from (i,j) to the last row.
If i == n-1, return triangle[i][j] because we reached the last row.
If the state is already calculated, return dp[i][j].
From (i,j), try two choices:
  Down → (i+1, j)
  Diagonal → (i+1, j+1)
Take the minimum of both paths and add the current value:
dp[i][j] = triangle[i][j] + min(down, diag).
Return dp[0][0].
*/
class Solution {
public:

    int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == n - 1) return triangle[n - 1][j];

        if(i >= n || j >= n) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i + 1, j, n, triangle, dp);
        int diag = solve(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, 0, n, triangle, dp);
    }
};




// TABULATION ->
/*
Create dp[i][j] = minimum path sum from (i,j) to the last row.
Initialize the last row of dp with the values of the triangle because those cells are already at the destination level.
Traverse from bottom to top (i = n-2 → 0).
For every cell (i,j), calculate:
  down = dp[i+1][j]
  diag = dp[i+1][j+1]
Store:
dp[i][j] = triangle[i][j] + min(down, diag).
Finally, dp[0][0] contains the minimum path sum.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; i++){
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }

        return dp[0][0];
    }
};
