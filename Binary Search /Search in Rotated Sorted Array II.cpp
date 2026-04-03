/*
Problem - Search in Rotated Sorted Array II (has duplicates)
LeetCode - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/

//APPROACH - 1 Brute Force - Linear Search
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
};



//APPROACH - 2 Optimised way - Binary Search
//Time Complexity - O(log n)
//Space Complexity - O(1)

class Solution {
public:

    bool BS(int low, int high, int target, vector<int> &nums){
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return true;

            else if(nums[mid] < target) low = mid + 1;

            else high = mid - 1;
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int mini;

        while(low <= high){
            //skip duplicates
            while(low < high && nums[low] == nums[low + 1]) low++;

            while(low < high && nums[high] == nums[high - 1]) high--; 

            int mid = low + (high - low) / 2;

            if(nums[mid] < nums[high]) high = mid;

            else low = mid + 1;

            mini = high;
        }

        return (BS(0, mini - 1, target, nums)) || (BS(mini, n - 1, target, nums));

    }
};
