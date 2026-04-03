/*
Problem - Search a 2D Matrix
LeetCode - https://leetcode.com/problems/search-a-2d-matrix/description/
*/

//APPROACH - 1 Brute Force -> Search the whole matrix
//Time Complexity - O(n*m)
//Space Complexity - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};



//APPROACH - 2 Optimised Way -> Binary Search
//Time Complexity - O(log(n*m))
//Space Complexity - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int low = 0, high = (m * n) - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(matrix[mid / n][mid % n] > target) high = mid - 1;

            else if(matrix[mid / n][mid % n] < target) low = mid + 1;

            else return true;
        }

        return false;
    }
};
