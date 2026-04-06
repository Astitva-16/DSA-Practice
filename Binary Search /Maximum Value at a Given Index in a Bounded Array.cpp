/*
Problem - Maximum Value at a Given Index in a Bounded Array
LeetCode - https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
*/

//APPROACH - 1 Brute Force -> For each possible value of index, check if the condition satisfies or not.
//Time Complexity - O(n * maxSum)
//Space Complexity - O(1)

class Solution {
public:

    typedef long long ll;

    int maxValue(int n, int index, int maxSum) {

        int ans = 1;

        for(int val = 1; val <= maxSum; val++){
            ll sum = val;

            //left side
            int curr = val - 1;

            for(int i = index - 1; i >= 0; i--){
                sum += max(curr, 1);
                curr--;
            }

            //right side
            curr = val - 1;

            for(int i = index + 1; i < n; i++){
                sum += max(curr, 1);
                curr--;
            }

            if(sum <= maxSum) ans = val;

            else break;
        }

        return ans;
    }
};



//APPROACH - 2 Binary Search -> Taking range from 1 to maxSum, if mid satisfies the condition, go right and vice versa.
//Time Complexity - O(log maxSum)
//Space Complexity - O(1)

class Solution {
public:

    typedef long long ll;

    int maxValue(int n, int index, int maxSum) {

        int emptyR = n - index - 1; //empty place right side
        int emptyL = index;

        int low = 1, high = maxSum;
        ll ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            ll leftsum = 0, rightsum = 0, el = mid - 1;

            //right side
            if(emptyR <= el){
                rightsum = ((el * (el + 1)) / 2) - (((el - emptyR) * (el - emptyR + 1)) / 2);
            }
            else{
                rightsum = ((el * (el + 1)) / 2) + (emptyR - el);
            }


            //left side
            if(emptyL <= el){
                leftsum = ((el * (el + 1)) / 2) - (((el - emptyL) * (el - emptyL + 1)) / 2);
            }
            else{
                leftsum = ((el * (el + 1)) / 2) + (emptyL - el);
            }

            ll sum = leftsum + rightsum + mid;

            if(sum <= maxSum){
                low = mid + 1;
                ans = mid;
            }

            else high = mid - 1;

        }

        return ans;
    }
};
