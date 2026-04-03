/*
Problem - Kth Missing Positive Number
LeetCode - https://leetcode.com/problems/kth-missing-positive-number/
*/

//APPRAOCH - 1 Brute Force -> Start from number 1, keep checking each number and count missing ones until the kth missing number is found.
//Time Complexity - O(k + n)
//Space Complexity - O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int dig = 1, i = 0;

        while(i < n && k > 0){
            if(arr[i] == dig){
                i++;
            }

            else{
                k--;
            }

            dig++;
        }

        while(k--) dig++;

        return dig - 1;
    }
};



//APPRAOCH - 2 Optimised way -> Binary Search and check how many numbers are missing till mid
//Time Complexity - O(k + n)
//Space Complexity - O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
      
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int missing_till_mid = arr[mid] - (mid + 1);

            if(missing_till_mid < k) low = mid + 1;

            else high = mid - 1;
        }

        return low + k;
    }
};
