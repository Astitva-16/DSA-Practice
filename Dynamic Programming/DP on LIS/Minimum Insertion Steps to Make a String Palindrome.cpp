/*1312. Minimum Insertion Steps to Make a String Palindrome
LeetCode link -> https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

// RECURSION ->
/*
The key idea is to find the Longest Palindromic Subsequence (LPS) of the string.
solve(i, j) = length of the longest palindromic subsequence between indices i and j.
Base cases:
  i > j → 0
  i == j → 1
If s[i] == s[j], both characters can be part of the palindrome:
2 + solve(i+1, j-1).
If s[i] != s[j], we have two choices:
  Remove/skip s[i] → solve(i+1, j)
  Remove/skip s[j] → solve(i, j-1)
  Take the maximum.
Once we know the LPS length, the minimum insertions required are:
n - LPS
*/
class Solution {
public:

    int solve(string& s, int i, int j, int n){

        if(i > j) return 0;

        if(i == j) return 1;

        if(s[i] == s[j]) return 2 + solve(s, i + 1, j - 1, n);

        int take_i = solve(s, i + 1, j, n);
        int take_j = solve(s, i, j - 1, n);

        return max(take_i, take_j);
    }

    int minInsertions(string s) {
        int n = s.size();

        return n - solve(s, 0, n - 1, n);
    }
};




// MEMOIZATION ->
/*
Find the Longest Palindromic Subsequence (LPS) first.
dp[i][j] = length of LPS in substring s[i...j].
Base cases:
  i > j → 0
  i == j → 1
If s[i] == s[j]:
  Both characters can be included:
  dp[i][j] = 2 + dp[i+1][j-1]
If s[i] != s[j]:
  Skip s[i] → dp[i+1][j]
  Skip s[j] → dp[i][j-1]
  Take maximum.
Finally:
Minimum Insertions = n - LPS
*/
class Solution {
public:

    int solve(string& s, int i, int j, int n, vector<vector<int>>& dp){

        if(i > j) return 0;

        if(i == j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = 2 + solve(s, i + 1, j - 1, n, dp);

        int take_i = solve(s, i + 1, j, n, dp);
        int take_j = solve(s, i, j - 1, n, dp);

        return dp[i][j] = max(take_i, take_j);
    }

    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return n - solve(s, 0, n - 1, n, dp);
    }
};
