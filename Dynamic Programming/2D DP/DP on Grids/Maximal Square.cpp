/*221. Maximal Square
LeetCode link -> https://leetcode.com/problems/maximal-square/
*/

// RECURSION ->
/*
solve(i,j) = maximum side length of a square of 1s ending at (i,j).
If (i,j) is outside the matrix or mat[i][j] == '0', return 0.
For a 1, calculate the three required neighboring squares:
  Up → solve(i-1,j)
  Left → solve(i,j-1)
  Diagonal → solve(i-1,j-1)
Current square size = 1 + min(up, left, diag) because all three neighboring squares must support the same square size.
Check every cell and store the maximum side length in ans.
Return ans × ans because the problem asks for the area.
*/
class Solution {
public:

    int solve(int i, int j, int n, int m, vector<vector<char>>& mat){
        if(i < 0 || j < 0) return 0;

        if(mat[i][j] == '0') return 0;

        int up = solve(i - 1, j, n, m, mat);
        int left = solve(i, j - 1, n, m, mat);
        int diag = solve(i - 1, j - 1, n, m, mat);

        return 1 + min({up, left, diag});
    }

    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, solve(i, j, n, m, mat));
            }
        }

        return ans * ans;
    }
};




// MEMOIZATION ->
/*
dp[i][j] = maximum side length of a square of 1s ending at (i,j).
If (i,j) is outside the matrix or mat[i][j] == '0', return 0.
For a 1, check three neighboring squares:
  Up → solve(i-1,j)
  Left → solve(i,j-1)
  Diagonal → solve(i-1,j-1)
Current square size:
dp[i][j] = 1 + min(up, left, diag)
Check every cell and keep the maximum side length in ans.
Return ans² because the question asks for area.
*/
class Solution {
public:

    int solve(int i, int j, int n, int m, vector<vector<char>>& mat, vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;

        if(mat[i][j] == '0') return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = solve(i - 1, j, n, m, mat, dp);
        int left = solve(i, j - 1, n, m, mat, dp);
        int diag = solve(i - 1, j - 1, n, m, mat, dp);

        return dp[i][j] = 1 + min({up, left, diag});
    }

    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, solve(i, j, n, m, mat, dp));
            }
        }

        return ans * ans;
    }
};
