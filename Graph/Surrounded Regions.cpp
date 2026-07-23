/*130. Surrounded Regions
LeetCode link -> https://leetcode.com/problems/surrounded-regions/
*/

// approach ->
/*
Create a visited matrix to mark safe 'O' cells.
Start DFS from all boundary 'O' cells (first row, last row, first column, last column).
During DFS, mark all connected 'O' cells as visited because they cannot be surrounded.
After marking all safe regions, traverse the entire board.
If a cell is 'O' and not visited, it is completely surrounded, so change it to 'X'.
Leave all visited 'O' cells unchanged.
*/

class Solution {
public:

    int drow[4] = {0, 0, -1, 1};
    int dcol[4] = {-1, 1, 0, 0};

    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board, int n, int m){
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){

            if(vis[i][0] == 0 && board[i][0] == 'O'){
                dfs(i, 0, vis, board, n, m);
            }

            if(vis[i][m - 1] == 0 && board[i][m - 1] == 'O'){
                dfs(i, m - 1, vis, board, n, m);
            }
        }

        for(int j = 0; j < m; j++){

            if(vis[0][j] == 0 && board[0][j] == 'O'){
                dfs(0, j, vis, board, n, m);
            }

            if(vis[n - 1][j] == 0 && board[n - 1][j] == 'O'){
                dfs(n - 1, j, vis, board, n, m);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
