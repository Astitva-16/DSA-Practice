/*547. Number of Provinces
LeetCode link -> https://leetcode.com/problems/number-of-provinces/
*/

//approach ->
/*
Convert the adjacency matrix into an adjacency list by adding an edge between i and j whenever isConnected[i][j] == 1 and i != j.
Create a visited array to keep track of visited cities.
Traverse all cities one by one.
If a city is not visited, it means a new province is found:
  Increment the province count.
  Start a DFS from that city to mark all connected cities as visited.
After visiting all cities, return the province count.
*/

class Solution {
public:

    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node] = true;

        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj);
            }
        }

        return cnt;
    }
};
