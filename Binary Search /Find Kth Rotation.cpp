/*
Problem - Find Kth Rotation
Geeks for Geeks - https://www.geeksforgeeks.org/problems/rotation4723/1
*/

//APPROACH - 1 Brute Force -> Find the index of minimum element and that is the answer
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int findKRotation(vector<int> &nums) {

        int n = nums.size();

        int minValue = nums[0];
        int index = 0;

        for(int i = 1; i < n; i++){

            if(nums[i] < minValue){

                minValue = nums[i];
                index = i;
            }
        }

        return index;
    }
};



//APPROACH - 2 Optimised Way -> Binary search and find the index of minimum value
//Time Complexity - O(log n)
//Space Complexity - O(1)

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        
        int low = 0, high = n - 1;
        
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] < arr[high]) high = mid;
            
            else{
                low = mid + 1;
            }
        }
        
        
        return high;
    }
};
