/*
Problem - Find First and Last Position of Element in Sorted Array
Leetcode - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

*/

//APPROACH - 1 Brute force -> Linear Search
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = -1, endingPosition = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                startingPosition = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == target) {
                endingPosition = i;
                break;
            }
        }
        return {startingPosition, endingPosition};
    }
};



//APPROACH - 2 Optimised Way -> Binary Search
//Time Complexity - O(log n)
//Space Complexity - O(1)

class Solution {
public:
    int first_occur(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target){
                first = mid;
                high = mid - 1;
            }

            else if (nums[mid] < target)
                low = mid + 1;

            else {
                high = mid - 1;
            }
        }

        return first;
    }

    int last_occur(vector<int>& nums, int n, int target) {
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target){
                last = mid;
                low = mid + 1;
            }

            else if (nums[mid] < target)
                low = mid + 1;

            else {
                high = mid - 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = first_occur(nums, n, target);
        int last = last_occur(nums, n, target);

        return {first, last};
    }
};
