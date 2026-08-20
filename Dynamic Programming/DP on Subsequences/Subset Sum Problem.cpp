/*Subset Sum Problem
GFG link -> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/
*/

// RECUSRION ->
/*
solve(i, sum) means:

Can we form sum using elements from index 0 to i?

Base case 1:

if(sum == 0) return true;

Target 0 can always be formed by taking nothing.

Base case 2:

if(i == 0) return arr[0] == sum;

When only the first element is available, the only possibility is whether arr[0] equals the remaining sum.

At every element arr[i], we have 2 choices.

Take arr[i]:
We can take it only if:

sum >= arr[i]

Then remaining target becomes:

sum - arr[i]

So:

take = solve(i - 1, sum - arr[i], arr);

Don't take arr[i]:
Keep the same target:

not_take = solve(i - 1, sum, arr);

If either choice works, the answer is true:

return take || not_take;

We start from:

solve(n - 1, sum, ...)

because initially we can use all elements.
*/
class Solution {
  public:
  
    bool solve(int i, int sum, int n, vector<int>& arr){
        
        if(sum == 0) return true;
        
        if(i == 0) return (arr[0] == sum);
        
        bool take = false;
        
        if(sum >= arr[i]){
            take = solve(i - 1, sum - arr[i], n, arr);
        }
        
        bool not_take = solve(i - 1, sum, n, arr);
        
        return (take || not_take);
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        
        return solve(n - 1, sum, n, arr);
        
    }
};




// MEMOIZATION ->
/*
Define the DP state:

dp[i][sum]

→ whether it is possible to form sum using elements from 0...i.

Base case:

if(sum == 0) return true;

Target 0 is always possible by selecting nothing.

If only the first element remains:

if(i == 0) return arr[0] == sum;

Before calculating the state, check if it was already solved:

if(dp[i][sum] != -1)
    return dp[i][sum];
At every element arr[i], there are two choices.

Take arr[i] if it doesn't exceed the remaining target:

if(sum >= arr[i])
    take = solve(i-1, sum-arr[i], ...);

Don't take arr[i]:

not_take = solve(i-1, sum, ...);

If either choice can form the target:

take || not_take

Store the result:

dp[i][sum] = take || not_take;
Start from:
solve(n-1, sum, ...)

because initially all elements are available.
*/
class Solution {
  public:
  
    bool solve(int i, int sum, int n, vector<int>& arr, vector<vector<int>>& dp){
        
        if(sum == 0) return true;
        
        if(i == 0) return (arr[0] == sum);
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool take = false;
        
        if(sum >= arr[i]){
            take = solve(i - 1, sum - arr[i], n, arr, dp);
        }
        
        bool not_take = solve(i - 1, sum, n, arr, dp);
        
        return dp[i][sum] = (take || not_take);
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        return solve(n - 1, sum, n, arr, dp);
        
    }
};




// TABULATION ->
/*
Define:

dp[i][j]

→ whether we can form sum j using elements from index 0...i.

Create a n × (sum+1) DP table:

vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

Base case: sum = 0

for(int i = 0; i < n; i++)
    dp[i][0] = true;

Because sum 0 can always be formed by taking nothing.

Base case: only arr[0] available

dp[0][arr[0]] = true;

We can form arr[0] by taking the first element.

Start from i = 1 because row 0 is already initialized.
For every element arr[i] and every target sum j, we have 2 choices.

Take arr[i] if:

j >= arr[i]

Then the remaining sum is:

j - arr[i]

So:

take = dp[i-1][j-arr[i]];

Don't take arr[i]:

not_take = dp[i-1][j];

If either choice works:

dp[i][j] = take || not_take;
Finally:
return dp[n-1][sum];

This tells us whether the required sum can be formed using all n elements.
*/
class Solution {
  public:

    bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        dp[0][arr[0]] = true;
        
        for(int i = 1; i < n; i++){
            
            for(int j = 1; j <= sum; j++){
                
                bool take = false;
        
                if(j >= arr[i]){
                    take = dp[i - 1][j - arr[i]];
                }
                
                bool not_take = dp[i - 1][j];
                
                dp[i][j] = (take || not_take);
            }
        }
        
        return dp[n - 1][sum];
        
    }
};
