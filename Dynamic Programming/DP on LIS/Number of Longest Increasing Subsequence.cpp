/*673. Number of Longest Increasing Subsequence
LeetCode link -> https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

// RECUSRION ->
/*
for every index, you calculate both the LIS length and the number of LIS ways ending at that index.

solve(i) returns a pair:
  bestLen → length of the longest increasing subsequence ending at i.
  ways → number of such LIS ending at i.

Initially:

bestLen = 1;
ways = 1;

because nums[i] itself is always an LIS of length 1.

Check every previous index j < i.

If:

nums[j] < nums[i]

then nums[i] can be appended to the LIS ending at j.

If the new length is greater:

len + 1 > bestLen

update:

bestLen = len + 1;
ways = cnt;

We found a better LIS, so discard previous ways.

If the new length is equal:

len + 1 == bestLen

add the number of ways:

ways += cnt;
Finally, iterate over every index and maintain:
  maxLen → global maximum LIS length.
  ans → number of LIS having that maximum length.
*/
class Solution {
public:

    pair<int,int> solve(int i, vector<int>& nums) {

        int bestLen = 1;
        int ways = 1;

        for(int j = 0; j < i; j++) {

            if(nums[j] < nums[i]) {

                auto [len, cnt] = solve(j, nums);

                if(len + 1 > bestLen) {

                    bestLen = len + 1;
                    ways = cnt;

                }
                else if(len + 1 == bestLen) {

                    ways += cnt;
                }
            }
        }

        return {bestLen, ways};
    }

    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        int maxLen = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {

            auto [len, cnt] = solve(i, nums);

            if(len > maxLen) {

                maxLen = len;
                ans = cnt;

            }
            else if(len == maxLen) {

                ans += cnt;
            }
        }

        return ans;
    }
};




// MEMOIZATION ->
/*
solve(i) returns a pair:
  first → length of the longest increasing subsequence ending at i
  second → number of LIS of that length ending at i

Initially for every index:

bestLen = 1;
ways = 1;

because nums[i] itself forms a subsequence of length 1.

Check every previous index j < i.

If:

nums[j] < nums[i]

then we can append nums[i] to an LIS ending at j.

Two cases:

  Found a longer LIS:
  
  if(len + 1 > bestLen)
  
  update both:
  
  bestLen = len + 1;
  ways = cnt;
  
  Found another LIS of the same length:
  
  else if(len + 1 == bestLen)
  
  add its number of ways:
  
  ways += cnt;

Store the result:

dp[i] = {bestLen, ways};

so we don't recalculate solve(i).

In findNumberOfLIS(), maintain:
  maxLen → global longest LIS length.
  totalWays → total number of LIS having that length.
Again:
  Greater length → replace totalWays
  Same length → add to totalWays
*/
class Solution {
public:

    pair<int,int> solve(int i, vector<int>& nums, vector<pair<int,int>>& dp) {

        if(dp[i].first != -1) {
            return dp[i];
        }

        int bestLen = 1;
        int ways = 1;

        for(int j = 0; j < i; j++) {

            if(nums[j] < nums[i]) {

                auto [len, cnt] = solve(j, nums, dp);

                if(len + 1 > bestLen) {

                    bestLen = len + 1;
                    ways = cnt;
                }
                else if(len + 1 == bestLen) {

                    ways += cnt;
                }
            }
        }

        return dp[i] = {bestLen, ways};
    }

    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int,int>> dp(n, {-1, -1});

        int maxLen = 0;
        int totalWays = 0;

        for(int i = 0; i < n; i++) {

            auto [len, cnt] = solve(i, nums, dp);

            if(len > maxLen) {

                maxLen = len;
                totalWays = cnt;
            }
            else if(len == maxLen) {

                totalWays += cnt;
            }
        }

        return totalWays;
    }
};




// TABULATION ->
/*
Maintain two DP arrays:
  length[i] → length of the longest increasing subsequence ending at i.
  count[i] → number of LIS of that length ending at i.

Initialize:

length[i] = 1;
count[i] = 1;

Every individual element is an LIS of length 1.

For every i, check all previous indices j < i.

If:

nums[j] < nums[i]

then nums[i] can extend the LIS ending at j.

If a longer LIS is found:

length[j] + 1 > length[i]

update:

length[i] = length[j] + 1;
count[i] = count[j];

We replace the old ways because we're now using a longer LIS.

If another LIS of the same length is found:

length[j] + 1 == length[i]

add:

count[i] += count[j];
After processing index i, update the global answer:

  If length[i] > maxLen → new longest LIS:
  
  maxLen = length[i];
  answer = count[i];
  
  If length[i] == maxLen → another set of LIS with maximum length:
  
  answer += count[i];
*/
class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> length(n, 1);
        vector<int> count(n, 1);

        int maxLen = 0;
        int answer = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {

                    // Better LIS found
                    if(length[j] + 1 > length[i]) {

                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }

                    // Another LIS of same maximum length
                    else if(length[j] + 1 == length[i]) {

                        count[i] += count[j];
                    }
                }
            }

            // New overall maximum length
            if(length[i] > maxLen) {

                maxLen = length[i];
                answer = count[i];
            }

            // Another ending index with same maximum length
            else if(length[i] == maxLen) {

                answer += count[i];
            }
        }

        return answer;
    }
};
