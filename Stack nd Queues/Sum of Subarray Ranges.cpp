/*2104. Sum of Subarray Ranges
LeetCode link -> https://leetcode.com/problems/sum-of-subarray-ranges/
*/

// stack appraoch - Monotonic stack se har element ka contributions find karo as max aur as min.

                // Sum of Subarray Minimums wala logic use karke 'min_sum' nikalo.
                // Same logic reverse karke (Next Greater Left/Right) 'max_sum' nikalo.
                // Max_sum calculate karne ke liye stack monotonic decreasing rakho.
                // Min_sum calculate karne ke liye stack monotonic increasing rakho.
                // Final result = max_sum - min_sum.

class Solution {
public:
    typedef long long ll;

    vector<int> PreviousSmaller(vector<int> arr, int n) {
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> NextSmaller(vector<int> arr, int n) {
        stack<int> st;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> PreviousGreater(vector<int> arr, int n) {
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> NextGreater(vector<int> arr, int n) {
        stack<int> st;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> PSL = PreviousSmaller(nums, n);
        vector<int> NSR = NextSmaller(nums, n);

        vector<int> PGL = PreviousGreater(nums, n);
        vector<int> NGR = NextGreater(nums, n);

        ll minSum = 0;
        ll maxSum = 0;

        for (int i = 0; i < n; i++) {

            ll left1 = i - PSL[i];
            ll right1 = NSR[i] - i;

            ll totalWays1 = (left1 * right1);

            minSum += nums[i] * totalWays1;

            ll left2 = i - PGL[i];
            ll right2 = NGR[i] - i;

            ll totalWays2 = (left2 * right2);

            maxSum += nums[i] * totalWays2;
        }

        return maxSum - minSum;
    }
};
