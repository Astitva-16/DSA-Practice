/*85. Maximal Rectangle
LeetCode link -> https://leetcode.com/problems/maximal-rectangle/
*/

/*
Approach: Histogram logic on each row.
Short Logic: Har row ko histogram maan kar 'Largest Rectangle in Histogram' wala formula lagao.

Ek height vector (size M) banao jise 0 se initialize karo.
Matrix ki har row ko traverse karo.
Agar matrix[i][j] == '1' hai toh height[j]++ karo, warna height[j] = 0 set karo.
Har row ke update hone ke baad current height vector par 'Largest Rectangle in Histogram' function call karo.
Sare rows mein se jo maximum rectangle area milega wahi final answer hai.
*/

class Solution {
public:
    vector<int> PreviousSmaller(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            res[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return res;
    }

    vector<int> NextSmaller(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i])
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

        for (int i = 0; i < n; i++) {

            int width = NSR[i] - PSL[i] - 1;

            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();

        int m = matrix[0].size();

        vector<int> heights(m, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '1')
                    heights[j]++;

                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};
