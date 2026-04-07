/*
Problem - Last Day Where You Can Still Cross
LeetCode - https://leetcode.com/problems/last-day-where-you-can-still-cross/
*/

//APPROACH - 1 Brute Force -> For each day from day = 1 to day = cells.size, try if we can cross of not.
//Time Complexity - O((row * col)^2)
//Space Complexity - O(row * col)

class Solution {
public:

    bool dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c){

        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || c < 0 ||  r >= row || c >= col || grid[r][c] == 1 || vis[r][c]) return false;

        if(r == row - 1) return true;

        vis[r][c] = 1;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];

            if(dfs(grid, vis, newr, newc)) return true;
        }

        return false;
    }

    bool canCross(vector<vector<int>>& cells, int row, int col, int day){

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for(int i = 0; i < day; i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            grid[r][c] = 1;
        }

        vector<vector<int>> vis(row, vector<int>(col, 0));

        for(int c = 0; c < col; c++){
            if(grid[0][c] == 0){
                if(dfs(grid, vis, 0, c)) return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int n = cells.size();

        for(int day = 1; day <= n; day++){
            
            if(!canCross(cells, row, col, day)) return day - 1;
        }

        return n;
    }
};



//APPROACH - 2 Optimised Way -> Binary Search between day 1 and day n.
//Time Complexity - O(row * col * log(row*col))
//Space Complexity - O(row * col)

class Solution {
public:

    bool dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c){

        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || c < 0 ||  r >= row || c >= col || grid[r][c] == 1 || vis[r][c]) return false;

        if(r == row - 1) return true;

        vis[r][c] = 1;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];

            if(dfs(grid, vis, newr, newc)) return true;
        }

        return false;
    }

    bool canCross(vector<vector<int>>& cells, int row, int col, int day){

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for(int i = 0; i < day; i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            grid[r][c] = 1;
        }

        vector<vector<int>> vis(row, vector<int>(col, 0));

        for(int c = 0; c < col; c++){
            if(grid[0][c] == 0){
                if(dfs(grid, vis, 0, c)) return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int n = cells.size();

        int low = 1, high = n, ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canCross(cells, row, col, mid)){
                ans = mid;
                low = mid + 1;
            }

            else high = mid - 1;
        }

        return ans;
    }
};
