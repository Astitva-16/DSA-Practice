/*Matrix Chain Multiplication
GFG link -> https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/
*/

// RECURSION ->
/*
arr represents matrix dimensions:
  Matrix i = arr[i-1] × arr[i].
  For arr = {10, 20, 30, 40}, matrices are 10×20, 20×30, 30×40.
solve(i,j) = minimum multiplication cost for matrices i through j.

Base case:

if(i == j) return 0;

A single matrix needs no multiplication.

Try every possible partition:

for(int k = i; k < j; k++)

Split into:

  Left → matrices i...k
  Right → matrices k+1...j

Cost of multiplying the two resulting matrices:

arr[i-1] * arr[k] * arr[j]

Total cost:

left + right + cost
Take the minimum over every possible k.
*/
class Solution {
  public:
  
    int solve(int i, int j, vector<int>& arr, int n){
        
        if(i == j) return 0;
        
        int ans = INT_MAX;
        
        for(int k = i; k < j; k++){
            
            int left = solve(i, k, arr, n);
            
            int right = solve(k + 1, j, arr, n);
            
            int cost = arr[i - 1] * arr[k] * arr[j];
            
            int total = left + right + cost;
            
            ans = min(ans, total);
        }
        
        return ans;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        
        return solve(1, n - 1, arr, n);
        
    }
};




// MEMOIZATION ->
/*
solve(i,j) = minimum multiplication cost for matrices i...j.

Base case:

if(i == j) return 0;

A single matrix requires no multiplication.

dp[i][j] stores the answer for the range i...j, avoiding repeated calculations.

Try every possible partition:

for(int k = i; k < j; k++)

Split into:

  Left → i...k
  Right → k+1...j

Calculate:

left = solve(i, k)
right = solve(k+1, j)
cost = arr[i-1] * arr[k] * arr[j]

Total:

total = left + right + cost

Take the minimum over all k and store it:

dp[i][j] = min(total)
Start with solve(1, n-1) because matrices are numbered from 1 to n-1.
*/
class Solution {
  public:
  
    int solve(int i, int j, vector<int>& arr, int n, vector<vector<int>>& dp){
        
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k = i; k < j; k++){
            
            int left = solve(i, k, arr, n, dp);
            
            int right = solve(k + 1, j, arr, n, dp);
            
            int cost = arr[i - 1] * arr[k] * arr[j];
            
            int total = left + right + cost;
            
            ans = min(ans, total);
        }
        
        return dp[i][j] = ans;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(1, n - 1, arr, n, dp);
        
    }
};




// TABULATION ->
/*
dp[i][j] = minimum multiplication cost for matrices i...j.

Base case is already handled because:

dp[i][i] = 0;

A single matrix requires no multiplication.

We fill the table by increasing chain length because dp[i][j] depends on smaller ranges.

Start with:

len = 2

because a chain of 1 matrix needs no multiplication.

For every range [i...j], try every possible partition k:

k = i ... j-1

Cost for a partition:

dp[i][k] + dp[k+1][j]
+ arr[i-1] * arr[k] * arr[j]

Take the minimum over all possible k:

dp[i][j] = min(dp[i][j], cost);

Finally:

dp[1][n-1]

contains the minimum cost for multiplying all matrices.
*/
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int len = 2; len <= n; len++){
            
            for(int i = 1; i + len - 1 <= n - 1; i++){
                
                int j = i + len - 1;
                
                dp[i][j] = INT_MAX;
                
                for(int k = i; k < j; k++){
                    
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][n - 1];
        
    }
};
