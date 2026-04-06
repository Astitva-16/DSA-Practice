/*
Problem - Minimum Cost to Make Array Equal
LeetCode - https://leetcode.com/problems/minimum-cost-to-make-array-equal/
*/

//APPROACH - 1 Brute Force -> For each value in nums, find cost and check minimum.
//Time Complexity - O(N^2)
//Space Complexity - O(1)

class Solution {
public:
    typedef long long ll;

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        ll ans = LLONG_MAX;

        for(int i = 0; i < n; i++){

            int target = nums[i];

            ll totalCost = 0;

            for(int j = 0; j < n; j++){

                totalCost += (ll)abs(nums[j] - target) * cost[j];

            }

            ans = min(ans, totalCost);
        }

        return ans;
    }
};



//APPROACH - 2 Optimised Way - Binary Search between the min and max element of nums, and check condition for mid & mid + 1;
//Time Complexity - O(n * log n)
//Space Complexity - O(1)

class Solution {
public:
    typedef long long ll;

    ll findcost(vector<int> &nums, vector<int> &cost, int target){
        ll res = 0;

        for(int i = 0; i < nums.size(); i++){
            res += (ll)abs(nums[i] - target) * cost[i];
        }

        return res;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        ll ans = LLONG_MAX;

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            ll cost1 = findcost(nums, cost, mid);
            ll cost2 = findcost(nums, cost, mid + 1);

            ans = min(cost1, cost2);

            if(cost2 > cost1) high = mid - 1;

            else low = mid + 1;
        }

        return ans == LLONG_MAX ? 0 : ans;
    }
};
