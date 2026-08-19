/*1547. Minimum Cost to Cut a Stick
LeetCode link -> https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/

// RECURSION ->
/*
Add the two boundaries:

cuts.push_back(n);
cuts.insert(cuts.begin(), 0);

So cuts[0] = 0 and cuts[m+1] = n.

Sort cuts because cuts can be given in any order.
solve(i,j) = minimum cost to perform all cuts from cuts[i] to cuts[j].

Base case:

if(i > j) return 0;

No cuts left → no cost.

Try every cut ind between i and j as the first cut:

for(int ind = i; ind <= j; ind++)
If ind is chosen first:
  Left part → solve(i, ind-1)
  Right part → solve(ind+1, j)
  
  Current cut cost = length of the current stick:
  
  cuts[j+1] - cuts[i-1]

Total:

cost = left + right + cuts[j+1] - cuts[i-1];
Try every possible first cut and take the minimum.
*/
class Solution {
public:

    int solve(int i, int j, vector<int>& cuts){
        if(i > j) return 0;

        int ans = INT_MAX;

        for(int ind = i; ind <= j; ind++){

            int left = solve(i, ind - 1, cuts);
            int right = solve(ind + 1, j, cuts);

            int cost = cuts[j + 1] - cuts[i - 1] + left + right;

            ans = min(ans, cost);
        }

        return ans;
    }

    int minCost(int n, vector<int>& cuts) {

        int m = cuts.size();
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        return solve(1, m, cuts);
    }
};




// MEMOIZATION ->
/*
Add boundaries 0 and n to cuts and sort it.
  cuts[0] = 0
  cuts[m+1] = n
solve(i,j) = minimum cost to perform all cuts from cuts[i] to cuts[j].

Base case:

if(i > j) return 0;

No cuts remain → cost 0.

dp[i][j] stores the minimum cost for the interval i...j, avoiding repeated calculations.

Try every cut ind as the first cut:

for(int ind = i; ind <= j; ind++)

For each possible first cut:

left  = solve(i, ind - 1)
right = solve(ind + 1, j)
cost  = cuts[j+1] - cuts[i-1] + left + right

Take the minimum over all possible ind and store:

dp[i][j] = min(dp[i][j], cost);

Start with:

solve(1, m)

because 0 and n are just boundaries, not actual cuts.
*/
class Solution {
public:

    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for(int ind = i; ind <= j; ind++){

            int left = solve(i, ind - 1, cuts, dp);
            int right = solve(ind + 1, j, cuts, dp);

            int cost = cuts[j + 1] - cuts[i - 1] + left + right;

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        int m = cuts.size();
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));

        return solve(1, m, cuts, dp);
    }
};




// TABULATION ->
/*
Add boundaries:

cuts[0] = 0
cuts[m+1] = n

and sort the cuts.

Define:

dp[i][j]

= minimum cost to perform all cuts from cuts[i] to cuts[j].

Base case:

dp[i][j] = 0   // when i > j

This is already handled because the DP table is initialized with 0.

Why do we fill i from m → 1?
Because:

dp[i][j]

depends on:

dp[i][ind-1]
dp[ind+1][j]

So smaller intervals must already be available.

For every interval [i,j], try every possible first cut:

for(int ind = i; ind <= j; ind++)

Calculate:

left  = dp[i][ind-1];
right = dp[ind+1][j];


cost = cuts[j+1] - cuts[i-1] + left + right;

Take the minimum:

dp[i][j] = min(dp[i][j], cost);

Finally:

return dp[1][m];

gives the minimum cost to perform all actual cuts.
*/
class Solution {
public:

    int minCost(int n, vector<int>& cuts) {

        int m = cuts.size();
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        for(int i = m; i >= 1; i--){
            for(int j = 1; j <= m; j++){

                if(i > j) continue;

                int ans = INT_MAX;

                for(int ind = i; ind <= j; ind++){

                    int left = dp[i][ind - 1];
                    int right = dp[ind + 1][j];

                    int cost = cuts[j + 1] - cuts[i - 1] + left + right;

                    ans = min(ans, cost);
                }

                dp[i][j] = ans;  
            }
        }

        return dp[1][m];

    }
};
