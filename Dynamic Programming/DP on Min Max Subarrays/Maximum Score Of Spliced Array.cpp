/*2321. Maximum Score Of Spliced Array
LeetCode link -> https://leetcode.com/problems/maximum-score-of-spliced-array/
*/

// APPROACH -> Kadenes DP
/*
We want to swap one continuous subarray between nums1 and nums2.
To maximize nums1, calculate the difference array:
  dp[i] = nums2[i] - nums1[i]
  → this tells how much nums1 gains if index i is swapped.
Find the maximum subarray sum of this difference array using Kadane's algorithm. This gives the best continuous range to swap.
Track the start and end indices of that maximum-sum subarray.
Swap nums1[start...end] with nums2[start...end], then calculate the resulting sum.
Repeat the same process in reverse (nums2, nums1) to find the best possible sum for nums2.
Return the maximum of both results.
*/
class Solution {
public:

    int solve(vector<int> nums1, vector<int> nums2) {

        int n = nums1.size();

        vector<int> dp(n);

        for(int i = 0; i < n; i++) {
            dp[i] = nums2[i] - nums1[i];
        }

        vector<int> maxdp(n);

        maxdp[0] = dp[0];

        int start = 0;
        int end = 0;
        int tempStart = 0;

        int maxSum = maxdp[0];

        for(int i = 1; i < n; i++) {

            if(dp[i] > maxdp[i-1] + dp[i]) {

                maxdp[i] = dp[i];
                tempStart = i;

            }
            else {

                maxdp[i] = maxdp[i-1] + dp[i];
            }

            if(maxdp[i] > maxSum) {

                maxSum = maxdp[i];

                start = tempStart;
                end = i;
            }
        }

        for(int i = start; i <= end; i++) {
            swap(nums1[i], nums2[i]);
        }

        int sum = 0;

        for(int x : nums1) {
            sum += x;
        }

        return sum;
    }


    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {

        int ans1 = solve(nums1, nums2);
        int ans2 = solve(nums2, nums1);

        return max(ans1, ans2);
    }
};
