/*
Problem - Single Element in a Sorted Array
LeetCode - https://leetcode.com/problems/single-element-in-a-sorted-array/description/
*/

//APPROACH - 1 Brute Force -> Using Hashmap
//Time Complexity - O(N)
//Space Complexity - O(N)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto num : nums){
            map[num]++;
        }
        for(auto num : map){
            if(num.second == 1) return num.first;
        }
        return -1;
    }
};



//APPROACH - 2 Better Approach -> Linear Search
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i+=2){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};



//APPROACH - 3 Optimised way -> Binary Search
//Time Complexity - O(log n)
//Space Complexity - O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            bool isEven;

            if((high - mid) % 2 == 0) isEven = true;
            else isEven = false;


            if(nums[mid] == nums[mid + 1]){
                if(isEven) low = mid + 2;

                else high = mid - 1;
            }

            else{ // nums[mid] != nums[mid + 1]
                if(isEven) high = mid; // we will search between low and mid as there are even elements between high and mid

                else low = mid + 1;
            }
            
        }
        return nums[high];
    }
};
