/*53. Maximum Subarray
LeetCode link -> https://leetcode.com/problems/maximum-subarray
*/

// Approach -> DP
/*
Create dp[i] = maximum sum of a subarray ending at index i.
Initialize dp[0] = nums[0] and ans = nums[0].
For every i from 1 to n-1, choose:
  Start new subarray: nums[i]
  Extend previous subarray: dp[i-1] + nums[i]
Store the maximum:
dp[i] = max(nums[i], dp[i-1] + nums[i]).
Update ans with the maximum dp[i].
Return ans.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);

        dp[0] = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};




// Approach -> Kadane's Algorithm)
/*
Maintain current = sum of the current subarray and maxsum = maximum sum found so far.
Traverse the array and add each element to current.
Update maxsum = max(maxsum, current).
If current < 0, reset current = 0 because a negative sum can only reduce any future subarray sum.
Continue until the array ends and return maxsum.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int currsum = 0, maxsum = INT_MIN;

        for(int i = 0; i < n; i++){
            currsum += nums[i];

            maxsum = max(currsum, maxsum);

            if(currsum < 0) currsum = 0;
        }

        return maxsum;
    }
};
