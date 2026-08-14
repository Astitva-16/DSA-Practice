/*741. Cherry Pickup
LeetCode link -> https://leetcode.com/problems/cherry-pickup/
*/

// RECURSION ->
/*
Think of the problem as two people going from (0,0) to (n-1,n-1) simultaneously.
State solve(r1,c1,r2) represents both positions; calculate the second column using:
c2 = r1 + c1 - r2 because both have taken the same number of steps.
If either position is out of bounds or on a -1 cell, return INT_MIN (invalid path).
If both reach the destination, return its value.
Collect cherries:
  Same cell → count once.
  Different cells → add both values.
Try all 4 movement combinations:
  Both Down
  First Down, Second Right
  First Right, Second Down
  Both Right
Add current cherries to the best of the 4 choices.
Finally, use max(0, answer) because no valid path means 0.
*/
class Solution {
public:

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2, int n) {

        int c2 = r1 + c1 - r2;

        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;

        if(r1 == n-1 && c1 == n-1) return grid[r1][c1];

        int cherries;

        if(r1 == r2 && c1 == c2) cherries = grid[r1][c1];

        else cherries = grid[r1][c1] + grid[r2][c2];

        int best = max({
            solve(grid, r1+1, c1, r2+1, n),
            solve(grid, r1+1, c1, r2, n),
            solve(grid, r1, c1+1, r2+1, n),
            solve(grid, r1, c1+1, r2, n)
        });

        return cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        return max(0, solve(grid, 0, 0, 0, n));
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization by treating the problem as 2 people moving simultaneously from (0,0) to (n-1,n-1).
State dp[i1][j1][i2] stores the maximum cherries collected when Person 1 is at (i1,j1) and Person 2 is at (i2,j2).
Since both have taken the same number of steps, calculate:
j2 = i1 + j1 - i2.
If either position is out of bounds or on -1, return INT_MIN.
Collect current cherries:
  Same cell → count once.
  Different cells → add both values.
Try all 4 combinations of moves: (Down,Down), (Down,Right), (Right,Down), (Right,Right).
Store the best result in dp[i1][j1][i2].
Return max(0, answer) because no valid path gives 0.
*/
class Solution {
public:

    int solve(vector<vector<int>>& grid, int i1, int j1, int i2, int n, vector<vector<vector<int>>>& dp) {

        int j2 = i1 + j1 - i2;

        if(i1 >= n || j1 >= n || i2 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return INT_MIN;

        if(i1 == n-1 && j1 == n-1) return grid[i1][j1];

        int cherries;

        if(i1 == i2 && j1 == j2) cherries = grid[i1][j1];

        else cherries = grid[i1][j1] + grid[i2][j2];

        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];

        int best = max({
            solve(grid, i1+1, j1, i2+1, n, dp),
            solve(grid, i1+1, j1, i2, n, dp),
            solve(grid, i1, j1+1, i2+1, n, dp),
            solve(grid, i1, j1+1, i2, n, dp)
        });

        return dp[i1][j1][i2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return max(0, solve(grid, 0, 0, 0, n, dp));
    }
};
