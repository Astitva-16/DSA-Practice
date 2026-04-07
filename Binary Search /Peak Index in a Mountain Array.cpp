/*
Problem - Peak Index in a Mountain Array
LeetCode - https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

//APPROACH - 1 Brute Force -> Linear Search
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, arr[i]);
        }

        int maxi_idx = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] == maxi) maxi_idx = i;
        }

        return maxi_idx;
    }
};



//APPRAOCH - 2 Optimised Way -> Binary Search
//Time Complexity - O(log n)
//Space Complexity - O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(mid + 1 < n && arr[mid] > arr[mid + 1]){
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }

        return low;
    }
};
