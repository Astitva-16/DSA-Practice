/*
Problem - Search in Rotated Sorted Array
LeetCode - https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

//APPROACH - 1 Brute Force - Linear Search
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        for(int i = 0; i < n; i++){

            if(nums[i] == target)
                return i;
        }

        return -1;
    }
};



//APPROACH - 2 Optimised Way - Binary Search
//Time Complexity - O(log n)
//Space Complexity - O(1)

class Solution {
public:

    int bs(int low, int high, int target, vector<int>& nums){

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        int mini;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] < nums[high]) high = mid;

            else low = mid + 1;

            mini = mid;
        }

        int ans = bs(0, mini - 1, target, nums);
        if(ans != -1) return ans;

        else ans = bs(mini, n - 1, target, nums);

        return ans;
    }
};
