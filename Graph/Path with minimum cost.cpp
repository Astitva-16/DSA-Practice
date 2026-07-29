/* 1631. Path With Minimum Effort
LeetCode link -> https://leetcode.com/problems/path-with-minimum-effort/
*/

// approach - 
/*
Treat each cell as a graph node and movement is allowed in 4 directions.
Create an ans matrix to store the minimum effort required to reach each cell. Initialize all with INT_MAX and set ans[0][0] = 0.
Use a min-heap (priority queue) storing {effort, {x, y}}. Push the starting cell (0,0).
While the priority queue is not empty:
  Pop the cell with the minimum current effort.
  If the popped effort is greater than the stored effort, skip it.
For each of the 4 neighboring cells:
  Calculate absDiff = abs(height difference).
  The effort to reach the neighbor is max(currentEffort, absDiff) because the path effort is the maximum edge difference encountered.
  If this effort is smaller than the stored effort, update it and push the neighbor into the priority queue.
After all cells are processed, return the effort stored at the bottom-right cell.
*/

class Solution {
  public:
    
    typedef pair<int, pair<int, int>> p;
    
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        
        priority_queue<p, vector<p>, greater<p>> pq;
        
        ans[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int d = top.first;
            auto cord = top.second;
            
            int x = cord.first;
            int y = cord.second;
            
            if(d > ans[x][y]) continue;
            
            for(auto dir : direction){
                int newx = x + dir[0];
                int newy = y + dir[1];
                
                if(newx >= 0 && newy >= 0 && newx < n && newy < m){
                    int absDiff = abs(mat[newx][newy] - mat[x][y]);
                    int maxdiff = max(d, absDiff);
                    
                    if(ans[newx][newy] > maxdiff){
                        ans[newx][newy] = maxdiff;
                        pq.push({maxdiff, {newx, newy}});
                    }
                }
            }
        }
        
        return ans[n-1][m-1];
        
    }
};
