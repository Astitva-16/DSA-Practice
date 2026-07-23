/*542. 01 Matrix
LeetCode link -> https://leetcode.com/problems/01-matrix/
*/

// approcah ->
/*
Push all cells containing 0 into the queue with distance = 0 and mark them as visited.
Start multi-source BFS, treating all 0s as starting points.
For each cell popped from the queue:
  Store its current distance in the dist matrix.
  Visit all 4 adjacent cells (up, down, left, right).
  If a neighbor is inside the grid and not visited, mark it visited and push it into the queue with distance + 1.
Continue until the queue becomes empty.
Return the dist matrix, where each cell contains the distance to the nearest 0.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int drow[] = {0, 0, -1, 1};
        int dcol[] = {-1, 1, 0, 0};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;

            q.pop();

            dist[r][c] = steps;
            
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return dist;
    }
};
