/*403. Frog Jump
LeetCode link -> https://leetcode.com/problems/frog-jump/
*/

// RECURSION ->
/*
Store every stone position → index in a hash map for O(1) lookup.
Start recursion from the first stone with the previous jump length 0.
If the current stone is the last stone, return true.
From the previous jump k, try the next possible jumps:
  k - 1, k, k + 1 (only if > 0).
For each valid jump:
  Compute the next stone position: currentStone + nextJump.
  If that stone exists, recursively try jumping from it.
If any recursive call reaches the last stone, return true; otherwise return false.
*/

class Solution {
public:

    bool solve(vector<int>& stones, unordered_map<int, int>& mp, int curr_stone_idx, int prevJump, int n){

        if(curr_stone_idx == n - 1) return true;

        bool res = false;

        for(int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++){

            if(nextJump > 0){
                
                int next_stone = stones[curr_stone_idx] + nextJump;

                if(mp.find(next_stone) != mp.end()){

                    res = res || solve(stones, mp, mp[next_stone], nextJump, n);
                }
            }
        }

        return res;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }

        return solve(stones, mp, 0, 0, n);
    }
};



// MEMOIZATION ->
/*
Store every stone position → index in a hash map for O(1) lookup.
Use DFS + Memoization, where dp[i][k] stores whether the frog can reach the last stone from stone i with previous jump k.
If the current stone is the last stone, return true.
If dp[i][k] is already computed, return it.
Try the next possible jumps:
  k - 1, k, k + 1 (only if > 0).
For each valid jump:
  Compute the next stone position.
  If that stone exists, recursively check from that stone.
Store and return the result in dp[i][k].
*/

class Solution {
public:

    bool solve(vector<int>& stones, unordered_map<int, int>& mp, int curr_stone_idx, int prevJump, int n,
                vector<vector<int>>& dp){

        if(curr_stone_idx == n - 1) return true;

        if(dp[curr_stone_idx][prevJump] != -1){
            return dp[curr_stone_idx][prevJump];
        }

        bool res = false;

        for(int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++){

            if(nextJump > 0){
                
                int next_stone = stones[curr_stone_idx] + nextJump;

                if(mp.find(next_stone) != mp.end()){

                    res = res || solve(stones, mp, mp[next_stone], nextJump, n, dp);
                }
            }
        }

        return dp[curr_stone_idx][prevJump] = res;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(stones, mp, 0, 0, n, dp);
    }
};
