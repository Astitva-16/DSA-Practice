/*907. Sum of Subarray Minimums
LeetCode link -> https://leetcode.com/problems/sum-of-subarray-minimums/
*/

/*stack approach -  Har element ke liye wo range dhoondo jisme wo minimum hai, phir counts multiply karo.
                    NSL aur NSR arrays calculate karo monotonic stack se (indices store karo).
                    NSL: Har element ke left mein pehla smaller element ka index.
                    NSR: Har element ke right mein pehla smaller element ka index.
                    Har index 'i' ke liye, left distance = i - NSL[i] aur right distance = NSR[i] - i.
                    Total subarrays jinka minimum array[i] hai = (left * right).
                    Result = Sum of (array[i] * left * right) compute karo.
*/

class Solution {
public:

    typedef long long ll;

    int MOD = 1e9 + 7;

    vector<int> NextSmallerLeft(vector<int> arr, int n){
        stack<int> st;

        vector<int> res(n);

        for(int i = 0; i < n; i++){
            if(st.empty()){
                res[i] = -1;
            }

            else{
                while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

                res[i] = st.empty() ? -1 : st.top();
            }

            st.push(i);
        }

        return res;
    }

    vector<int> NextSmallerRight(vector<int> arr, int n){
        stack<int> st;

        vector<int> res(n);

       for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                res[i] = n;
            }

            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }

                res[i] = st.empty() ? n : st.top();
            }

            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = NextSmallerLeft(arr, n);
        vector<int> NSR = NextSmallerRight(arr, n);

        ll sum = 0;

        for(int i = 0; i < n; i++){
            int left = i - NSL[i];
            int right = NSR[i] - i;

            ll totalWays = (left * right);

            ll totalSum = (arr[i] * totalWays);

            sum = (sum + totalSum) % MOD;
        }

        return sum;
    }
};
