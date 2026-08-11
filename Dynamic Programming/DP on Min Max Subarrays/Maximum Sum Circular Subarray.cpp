/*918. Maximum Sum Circular Subarray
LeetCode link -> https://leetcode.com/problems/maximum-sum-circular-subarray/
*/

// Kadene's approach
/*
Calculate the total sum of the array.
Find the maximum subarray sum using Kadane's algorithm → maxsum.
Find the minimum subarray sum using Kadane's algorithm → minsum.
For a circular subarray, the maximum sum is:
  total_sum - minsum (remove the minimum-sum middle part).
The answer is the maximum of:
  Normal maximum subarray → maxsum
  Circular maximum subarray → total_sum - minsum
If maxsum <= 0, all elements are negative, so return maxsum directly to avoid incorrectly returning 0.
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;

        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        int maxsum = nums[0];
        int minsum = nums[0];
        int currsum = nums[0];

        for(int i = 1; i < n; i++){
            currsum = max(currsum + nums[i], nums[i]);
            maxsum = max(currsum, maxsum);
        }

        currsum = nums[0];

        for(int i = 1; i < n; i++){
            currsum = min(currsum + nums[i], nums[i]);
            minsum = min(currsum, minsum);
        }

        return (maxsum > 0) ? max(maxsum, (total_sum - minsum)) : maxsum;
    }
};




// DP approach
/*
Maintain two DP arrays:
  maxdp[i] = maximum subarray sum ending at i.
  mindp[i] = minimum subarray sum ending at i.
Initialize both with nums[0], and calculate total_sum.
For every index:
  maxdp[i] = max(nums[i], nums[i] + maxdp[i-1])
  mindp[i] = min(nums[i], nums[i] + mindp[i-1])
Keep track of overall maxsum and minsum.
Normal maximum = maxsum.
Circular maximum = total_sum - minsum.
If maxsum <= 0, all elements are negative → return maxsum; otherwise return max(maxsum, total_sum - minsum).
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxdp(n);
        vector<int> mindp(n);

        maxdp[0] = nums[0];
        mindp[0] = nums[0];
        int total_sum = nums[0];

        int maxsum = nums[0];
        int minsum = nums[0];

        for(int i = 1; i < n; i++){
            maxdp[i] = max(nums[i], nums[i] + maxdp[i - 1]);

            mindp[i] = min(nums[i], nums[i] + mindp[i - 1]);

            total_sum += nums[i];

            maxsum = max(maxsum, maxdp[i]);
            minsum = min(minsum, mindp[i]);
        }

        return (maxsum > 0) ? max(maxsum, (total_sum - minsum)) : maxsum;

    }
};
