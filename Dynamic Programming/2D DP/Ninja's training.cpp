/* Ninja's Training
GFG link -> https://www.geeksforgeeks.org/problems/geeks-training/1
*/

// RECURSION ->
/*
solve(day, last_task) = maximum points from day onward, where last_task is the activity done on the previous day.
If day == n, return 0 because all days are completed.
For the current day, try all 3 activities.
Skip the activity if act == last_task (same activity cannot be done on consecutive days).
Otherwise, calculate mat[day][act] + solve(day + 1, act).
Take the maximum among all valid activities.
Start with last_task = 3 because initially no activity is performed.
*/
class Solution {
  public:
  
    int solve(int day, int last_task, vector<vector<int>>& mat, int n){
        
        if(day == n) return 0;
        
        int ans = 0;
        
        for(int act = 0; act < 3; act++){
            
            if(act != last_task){
                
                int points = mat[day][act] + solve(day + 1, act, mat, n);
                
                ans = max(ans, points);
            }
        }
        
        return ans;
    }
  
    int maximumPoints(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        return solve(0, 3, mat, n);
        
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[day][last_task] stores the maximum points from day onward when last_task was done the previous day.
If day == n, return 0.
If the state is already calculated, return dp[day][last_task].
Try all 3 activities and skip the one equal to last_task.
For every valid activity:
points = mat[day][act] + solve(day + 1, act).
Store the maximum in dp[day][last_task].
Start with last_task = 3 because initially no activity was performed.
*/
class Solution {
  public:
  
    int solve(int day, int last_task, vector<vector<int>>& mat, int n, vector<vector<int>>& dp){
        
        if(day == n) return 0;
        
        if(dp[day][last_task] != -1) return dp[day][last_task];
        
        int ans = 0;
        
        for(int act = 0; act < 3; act++){
            
            if(act != last_task){
                
                int points = mat[day][act] + solve(day + 1, act, mat, n, dp);
                
                ans = max(ans, points);
            }
        }
        
        return dp[day][last_task] = ans;
    }
  
    int maximumPoints(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        return solve(0, 3, mat, n, dp);
        
    }
};
