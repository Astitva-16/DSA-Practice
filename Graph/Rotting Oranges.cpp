/*994. Rotting Oranges
LeetCode link -> https://leetcode.com/problems/rotting-oranges/
*/

// approach ->
/*
Traverse the grid and push all rotten oranges (2) into the queue with time = 0. Mark them as visited.
Start multi-source BFS, where all rotten oranges spread the rot simultaneously.
For each orange popped from the queue:
  Update the maximum time.
  Visit its 4 adjacent cells (up, down, left, right).
  If a neighbor is a fresh orange (1) and not visited, mark it rotten, push it into the queue with time + 1.
After BFS, traverse the grid again.
  If any fresh orange is still unvisited, return -1 (it can never rot).
Otherwise, return the maximum time taken.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int time = 0;
        int drow[] = {0, 0, 1, -1};
        int dcol[] = {-1, 1, 0, 0};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            time = max(t, time);

            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >=0 && nrow < n && ncol < m && vis[nrow][ncol] != 2 && 
                    grid[nrow][ncol] == 1){
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = 2;
                    }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};
