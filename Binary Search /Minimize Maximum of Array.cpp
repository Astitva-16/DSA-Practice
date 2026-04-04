/*
Problem - Minimize Maximum of Array
LeetCode - https://leetcode.com/problems/minimize-maximum-of-array/
*/

//APPROACH - 1 Brute Force -> Repeatedly move 1 unit from right element to left whenever the right is larger, until the array stabilizes.
//Time Complexity - O(n * max(nums))
//Space Complexity - O(1)

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        bool changed = true;

        while(changed){
            changed = false;

            for(int i = n - 1; i > 0; i--){
                if(nums[i] > nums[i - 1]){
                    nums[i]--;
                    nums[i - 1]++;

                    changed = true;
                }
            }
        }

        return *max_element(nums.begin(), nums.end());
        
    }
};



//APPROACH - 2 Optimised Way -> Binary search on the answer to find the minimum possible maximum value such that excess from left positions can be pushed to the right without exceeding that limit.
//Time Complexity - O(n * log(max(nums)))
//Space Complexity - O(N)

class Solution {
public:

    bool valid(vector<int> &nums, int mid, int n){

        vector<long long> arr(begin(nums), end(nums));

        for(int i = 0; i < n - 1; i++){

            if(arr[i] > mid) return false;

            long long buffer = mid - arr[i];

            arr[i + 1] = arr[i + 1] - buffer;
        }

        return arr[n - 1] <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = *max_element(nums.begin(), nums.end());

        int result = 0;

        while(low <= high){
            
            int mid = low + (high - low) / 2;

            if(valid(nums, mid, n)){
                result = mid;
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }

        return result;
    }
};
