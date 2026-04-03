/*
Problem - Find Minimum in Rotated Sorted Array
LeetCode - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

//APPROACH - 1 Brute Force -> Linear Search
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int mini = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            mini = min(mini, nums[i]);
        }

        return mini;
    }
};



//APPROACH - 2 Optimised Way -> Binary Search
//Time Complexity - O(log n)
//Space Complexity - O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};
