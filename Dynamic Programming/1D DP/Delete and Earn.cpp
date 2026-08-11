/*740. Delete and Earn
LeetCode link -> https://leetcode.com/problems/delete-and-earn/
*/

// RECURSION ->
/*
Store the frequency of each number in a map and create a sorted vector v of unique numbers.
At each index i, make 2 choices:
  Skip: don't take v[i] → solve(i+1).
  Pick: earn v[i] * frequency[v[i]].
If v[i+1] == v[i] + 1, picking v[i] means v[i+1] cannot be picked, so jump to i+2.
Otherwise, v[i+1] is not consecutive, so we can continue from i+1.
Return the maximum of skip and pick.
*/
class Solution {
public:

    int solve(int i, map<int, int>& mp, vector<int>& v, int n){
        if(i >= n) return 0;

        int skip = solve(i + 1, mp, v, n);
        int pick = mp[v[i]] * v[i];

        if(i + 1 < n && v[i + 1] == v[i] + 1) {
            pick += solve(i + 2, mp, v, n);
        }
        else {
            pick += solve(i + 1, mp, v, n);
        }

        return max(skip, pick);
    }

    int deleteAndEarn(vector<int>& nums) {

        map<int, int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        vector<int> v;

        for(auto it : mp){
            v.push_back(it.first);
        }

        int n = v.size();

        return solve(0, mp, v, n);
    }
};




// MEMOIZATION ->
/*
Store the frequency of each number in a map and create a sorted vector v containing unique numbers.
Use DFS + Memoization, where dp[i] stores the maximum points obtainable from index i onward.
At each index, make 2 choices:
  Skip: solve(i + 1).
  Pick: earn v[i] * frequency[v[i]].
If v[i+1] == v[i] + 1, picking v[i] means we cannot pick the next number, so move to i+2.
Otherwise, the next number is not consecutive, so we can move to i+1.
Store max(skip, pick) in dp[i] and return it.
*/
class Solution {
public:

    int solve(int i, map<int, int>& mp, vector<int>& v, int n, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int skip = solve(i + 1, mp, v, n, dp);
        int pick = mp[v[i]] * v[i];

        if(i + 1 < n && v[i + 1] == v[i] + 1) {
            pick += solve(i + 2, mp, v, n, dp);
        }
        else {
            pick += solve(i + 1, mp, v, n, dp);
        }

        return max(skip, pick);
    }

    int deleteAndEarn(vector<int>& nums) {

        map<int, int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        vector<int> v;

        for(auto it : mp){
            v.push_back(it.first);
        }

        int n = v.size();

        vector<int> dp(n, -1);

        return solve(0, mp, v, n, dp);
    }
};




// TABULATION / BOTTOM - UP
/*
Store the frequency of each number in a map and create a sorted vector v of unique numbers.
Create dp where dp[i] = maximum points obtainable from index i onward.
Initialize dp[n] = 0 because no elements remain.
Traverse from right to left (i = n-1 → 0).
At each index:
  Skip: dp[i+1]
  Pick: v[i] × frequency[v[i]]
    If next value is consecutive (v[i+1] == v[i]+1), add dp[i+2].
    Otherwise, add dp[i+1].
Store max(skip, pick) in dp[i] and return dp[0].
*/
class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {

        map<int, int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        vector<int> v;

        for(auto it : mp){
            v.push_back(it.first);
        }

        int n = v.size();

        vector<int> dp(n + 1, -1);

        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--){
            
            int skip = dp[i + 1];

            int pick = mp[v[i]] * v[i];

            if(i + 1 < n && v[i + 1] == v[i] + 1) {
                pick += dp[i + 2];
            }
            else {
                pick += dp[i + 1];
            }

            dp[i] = max(skip, pick);
        }

        return dp[0];
    }
};
