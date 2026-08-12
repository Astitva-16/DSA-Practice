/*1749. Maximum Absolute Sum of Any Subarray
LeetCode link -> https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
*/

// APPROACH -> kadenes
/*
We need both the maximum subarray sum and minimum subarray sum.
Maintain:
  currmax → maximum subarray sum ending at current index.
  currmin → minimum subarray sum ending at current index.
For every element:
  currmax = max(nums[i], currmax + nums[i])
  currmin = min(nums[i], currmin + nums[i])
Track the overall maxsum and minsum.
The answer is the larger of:
  maxsum → largest positive subarray sum.
  abs(minsum) → largest negative subarray magnitude.
*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currmax = nums[0];
        int currmin = nums[0];
        int maxsum = nums[0];
        int minsum = nums[0];

        for(int i = 1; i < n; i++){
            currmax = max(nums[i], currmax + nums[i]);
            currmin = min(nums[i], currmin + nums[i]);

            maxsum = max(maxsum, currmax);
            minsum = min(minsum, currmin);
        }

        return max(maxsum, abs(minsum));
    }
};




// APPROACH -> DP
/*
Maintain two DP arrays:
  maxdp[i] → maximum subarray sum ending at index i.
  mindp[i] → minimum subarray sum ending at index i.
Initialize both with nums[0].
For each index:
  maxdp[i] = max(nums[i], maxdp[i-1] + nums[i])
  mindp[i] = min(nums[i], mindp[i-1] + nums[i])
Track the overall maxsum and minsum.
The maximum absolute subarray sum is:
  max(maxsum, abs(minsum)).
*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxdp(n);
        vector<int> mindp(n);

        maxdp[0] = nums[0];
        mindp[0] = nums[0];

        int maxsum = nums[0];
        int minsum = nums[0];

        for(int i = 1; i < n; i++) {

            maxdp[i] = max(
                nums[i],
                maxdp[i-1] + nums[i]
            );

            mindp[i] = min(
                nums[i],
                mindp[i-1] + nums[i]
            );

            maxsum = max(maxsum, maxdp[i]);
            minsum = min(minsum, mindp[i]);
        }

        return max(maxsum, abs(minsum));
    }
};
