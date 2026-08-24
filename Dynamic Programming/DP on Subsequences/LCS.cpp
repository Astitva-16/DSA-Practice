/*300. Longest Increasing Subsequence
LeetCode link -> https://leetcode.com/problems/longest-increasing-subsequence/
*/

// RECURSION ->
/*
solve(i,j) means: LCS find karo s1[i...] aur s2[j...] ke beech.
Agar i >= n ya j >= m, koi string khatam → 0.
Agar s1[i] == s2[j], dono characters match → 1 + solve(i+1,j+1).
Agar match nahi hua, do choices:
s1[i] ko skip → solve(i+1,j)
s2[j] ko skip → solve(i,j+1)
Dono choices ka max lete hain.
longestCommonSubsequence() solve(0,0) se start karta hai.
*/
class Solution {
public:

    int solve(string &s1, string &s2, int i, int j, int n, int m){
        if(i >= n || j >= m) return 0;

        if(s1[i] == s2[j]){
            return 1 + solve(s1, s2, i + 1, j + 1, n, m);
        }

        int include_i = solve(s1, s2, i + 1, j, n, m);
        int include_j = solve(s1, s2, i, j + 1, n, m);

        return max(include_i, include_j);
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        return solve(s1, s2, 0, 0, n, m);
    }
};




// MEMOIZATION ->
/*
dp[i][j] = LCS length for s1[i...] and s2[j...].
memset(dp, -1, ...) → saare states ko initially -1 se fill kar diya.
Agar dp[i][j] != -1 → answer already calculated hai, directly return.
Agar s1[i] == s2[j] → character match:
1 + solve(i+1, j+1).
Agar match nahi:
s1[i] skip → solve(i+1,j)
s2[j] skip → solve(i,j+1)
Dono mein se max answer hai → dp[i][j] mein store.
Main difference: Pehle same states baar-baar calculate ho rahe the → ab dp ki wajah se Memoization (Top-Down DP) ho gayi.
*/
class Solution {
public:

    int dp[1001][1001];

    int solve(string &s1, string &s2, int i, int j, int n, int m){
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1, n, m);
        }

        int include_i = solve(s1, s2, i + 1, j, n, m);
        int include_j = solve(s1, s2, i, j + 1, n, m);

        return dp[i][j] = max(include_i, include_j);
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0, n, m);
    }
};




// BOTTOM UP ->
/*
dp[i][j] = LCS length of first i characters of s1 and first j characters of s2.
dp size (n+1) × (m+1) because 0 characters ka state bhi chahiye.
First row and first column = 0 → agar ek string empty hai, LCS 0.
s1[i-1] == s2[j-1] → characters match:
dp[i][j] = 1 + dp[i-1][j-1].

Match nahi hua → ek character skip karo:

s1 se → dp[i-1][j]
s2 se → dp[i][j-1]

So, max lete hain.

i-1 aur j-1 isliye use kiya because DP table 1-based hai, but strings 0-based hain.
Finally dp[n][m] = complete s1 aur s2 ka LCS.
*/
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) { 
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
        }

        for(int j = 0; j < m + 1; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
