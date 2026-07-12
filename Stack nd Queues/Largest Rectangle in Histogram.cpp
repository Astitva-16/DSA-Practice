/*84. Largest Rectangle in Histogram
LeetCode Link -> https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

/* 
Approach: Monotonic Stack (NSL and NSR).
Short Logic: Har bar (bar) ke liye left aur right smaller limits dhoond kar maximum area calculate karo.

Do arrays (leftSmall aur rightSmall) banao indices store karne ke liye.
Monotonic stack use karke har index ke liye NSL aur NSR find karo.
Har index 'i' ke liye width = (rightSmall[i] - leftSmall[i] + 1) calculate karo.
Area = height[i] * width nikalo.
Poore array mein jo max area mile usse return karo.
Indices handling ke waqt boundary conditions ka dhyan rakho.

*/

class Solution {
public:
    vector<int> PreviousSmaller(vector<int>& heights, int n){
        stack<int> st;
        vector<int> res(n);

        for(int i = 0; i < n; i++){

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            res[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return res;
    }

    vector<int> NextSmaller(vector<int>& heights, int n){
        stack<int> st;
        vector<int> res(n);

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            res[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> PSL = PreviousSmaller(heights, n);
        vector<int> NSR = NextSmaller(heights, n);

        int maxi = 0;

        for(int i = 0; i < n; i++){

            int width = NSR[i] - PSL[i] - 1;

            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};


