/*91. Decode Ways
LeetCode link -> https://leetcode.com/problems/decode-ways
*/

// RECURSION ->
/*
Start recursion from index 0.
If i == n, return 1 (a valid decoding is formed).
If the current character is '0', return 0 because '0' cannot be decoded alone.
Choice 1: Decode only the current digit and recurse for i + 1.
Choice 2: If the next two digits form a valid number (10–26), decode them together and recurse for i + 2.
Return the sum of both choices.
*/
class Solution {
public:

    int solve(int i, int n, string& s){
        if(i == n) return 1;

        if(s[i] == '0') return 0;

        int only_ith_char = solve(i + 1, n, s);
        int ith_nd_i_plus_oneth_char = 0;

        if(i + 1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')){
                ith_nd_i_plus_oneth_char = solve(i + 2, n, s);
            }
        }

        return only_ith_char + ith_nd_i_plus_oneth_char;

    }

    int numDecodings(string s) {
        int n = s.size();

        return solve(0, n, s);
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i] stores the number of ways to decode the substring starting from index i.
If i == n, return 1 (a valid decoding is formed).
If s[i] == '0', return 0 because '0' cannot be decoded alone.
If dp[i] is already computed, return it.
Choice 1: Decode the current digit and recurse for i + 1.
Choice 2: If the next two digits form a valid number (10–26), recurse for i + 2.
Store and return:
  dp[i] = waysFromOneDigit + waysFromTwoDigits.
*/
class Solution {
public:

    int solve(int i, int n, string& s, vector<int>& dp){
        if(i == n) return 1;

        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int only_ith_char = solve(i + 1, n, s, dp);
        int ith_nd_i_plus_oneth_char = 0;

        if(i + 1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')){
                ith_nd_i_plus_oneth_char = solve(i + 2, n, s, dp);
            }
        }

        return dp[i] = only_ith_char + ith_nd_i_plus_oneth_char;

    }

    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, n, s, dp);
    }
};




// TABULATION / BOTTOM-UP
/*
Create a dp array where dp[i] stores the number of ways to decode the substring starting from index i.
Initialize:
  dp[n] = 1 (empty string has one valid decoding).
Traverse the string from right to left.
If s[i] == '0', set dp[i] = 0 since '0' cannot be decoded alone.
Otherwise:
  Decode one digit: dp[i] = dp[i + 1].
  Decode two digits: If 10–26 is valid, add dp[i + 2].
Return dp[0], which gives the total number of decoding ways.
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--){

            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            dp[i] = dp[i + 1];

            if((i + 1) < n && (s[i] == '1' || ((s[i] == '2') && s[i + 1] <= '6'))){
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};
