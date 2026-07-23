/*733. Flood Fill
LeetCode link -> https://leetcode.com/problems/flood-fill/ 
*/

//approach -> 
/*
Store the initial color of the starting cell (sr, sc).
If the initial color is already the same as the new color, return the image.
Create a copy of the image (res) and start DFS from (sr, sc).
In DFS:
  If the current cell is inside the grid and its color is the initial color, change it to the new color.
  Recursively visit all 4 adjacent cells (up, down, left, right).
Continue until all connected cells with the initial color are recolored.
Return the modified image.
*/

class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& res, int iniColor, int n, int m){

        if(sr >= 0 && sc >= 0 && sr < n && sc < m && res[sr][sc] == iniColor){

            res[sr][sc] = color;

            dfs(image, sr+1, sc, color, res, iniColor, n, m);
            dfs(image, sr-1, sc, color, res, iniColor, n, m);
            dfs(image, sr, sc+1, color, res, iniColor, n, m);
            dfs(image, sr, sc-1, color, res, iniColor, n, m);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> res = image;

        int iniColor = image[sr][sc];

        if(iniColor == color) return image;

        dfs(image, sr, sc, color, res, iniColor, n, m);

        return res;
    }
};
