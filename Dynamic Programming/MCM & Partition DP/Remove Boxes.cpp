/*546. Remove Boxes
LeetCode link -> https://leetcode.com/problems/remove-boxes/
*/

// RECURSION ->
/*
The main difficulty is that removing a group gives groupSize² points, so sometimes it's better to wait and merge same-colored boxes.
solve(i, j, k) means:
maximum points from boxes[i...j], assuming there are already k boxes of the same color as boxes[i] attached to its left.

First, merge consecutive same-colored boxes:

while(i < j && boxes[i] == boxes[i+1]) {
    i++;
    k++;
}

Now boxes[i] represents a group of size k+1.

Option 1 — Remove the current group now:

(k+1) * (k+1)
+ solve(i+1, j, 0)

We remove the current group and start fresh from i+1.

Option 2 — Merge with a future same-colored box:

Find some m > i such that:

boxes[m] == boxes[i]

First remove everything between them:

solve(i+1, m-1, 0)

Then boxes[m] becomes adjacent to the current group, so we carry the extra box:

solve(m, j, k+1)
Take the maximum of both choices.
*/
class Solution {
public:

    int solve(int i, int j, int k, vector<int>& boxes) {

        if(i > j)
            return 0;

        // Merge consecutive same-colored boxes
        while(i < j && boxes[i] == boxes[i + 1]) {
            i++;
            k++;
        }

        // Option 1: remove current group
        int ans =
            (k + 1) * (k + 1)
            + solve(i + 1, j, 0, boxes);

        // Option 2: merge boxes[l] with a future same-coiored box
        for(int m = i + 1; m <= j; m++) {

            if(boxes[m] == boxes[i]) {

                int total =
                    solve(i + 1, m - 1, 0, boxes)
                    +
                    solve(m, j, k + 1, boxes);

                ans = max(ans, total);
            }
        }

        return ans;
    }

    int removeBoxes(vector<int>& boxes) {

        int n = boxes.size();

        return solve(0, n - 1, 0, boxes);
    }
};




// MEMOIZATION ->
/*
The state is:

dp[i][j][k]

where:

  i = starting index of current interval.
  j = ending index.
  k = number of extra boxes of the same color as boxes[i] already attached to the left.

Base case:

if(i > j) return 0;

If the state is already calculated:

if(dp[i][j][k] != -1)
    return dp[i][j][k];

First merge consecutive same-colored boxes:

while(i < j && boxes[i] == boxes[i+1]) {
    i++;
    k++;
}

So the current group size becomes k + 1.

Option 1 — Remove current group immediately:

(k+1)² + solve(i+1, j, 0)

Option 2 — Merge with a future same-colored box:
Find m > i where:

boxes[m] == boxes[i]

First remove the boxes between them:

solve(i+1, m-1, 0)

Then merge the current group with boxes[m]:

solve(m, j, k+1)
Take the maximum of both choices.

Store:

dp[i][j][k] = ans;
*/
class Solution {
public:

    int solve(int i, int j, int k, vector<int>& boxes, vector<vector<vector<int>>>& dp) {

        if(i > j) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        // Merge consecutive same-colored boxes
        while(i < j && boxes[i] == boxes[i + 1]) {
            i++;
            k++;
        }

        // Option 1: remove current group
        int ans =
            (k + 1) * (k + 1)
            + solve(i + 1, j, 0, boxes, dp);

        // Option 2: merge boxes[l] with a future same-coiored box
        for(int m = i + 1; m <= j; m++) {

            if(boxes[m] == boxes[i]) {

                int total =
                    solve(i + 1, m - 1, 0, boxes, dp)
                    +
                    solve(m, j, k + 1, boxes, dp);

                ans = max(ans, total);
            }
        }

        return dp[i][j][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {

        int n = boxes.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return solve(0, n - 1, 0, boxes, dp);
    }
};




// TABULATION ->
/*
Create a 3D DP array:

dp[i][j][k]

where:

  i = starting index of the interval.
  j = ending index of the interval.
  k = number of extra boxes of the same color as boxes[i] attached to its left.
dp[i][j][k] stores the maximum points that can be obtained from boxes[i...j].

Fill the DP table using increasing interval length:

len = 1 → n

because smaller intervals are needed to calculate larger intervals.

For every interval [i,j], try every possible value of k from n-1 down to 0.

Option 1: Remove boxes[i] and its k attached boxes immediately.

(k + 1) * (k + 1)

Then solve the remaining interval:

dp[i+1][j][0]

Option 2: Merge boxes[i] with a future box of the same color.
Find every m such that:

boxes[m] == boxes[i]

First remove all boxes between i and m:

dp[i+1][m-1][0]

Then merge boxes[i] with boxes[m]. Since one more same-colored box is attached, use:

dp[m][j][k+1]

For every possible m, calculate:

left + right

and take the maximum.

Store the best result:
dp[i][j][k] = ans;
Finally return:
dp[0][n-1][0]

because initially we have the entire array and no extra boxes attached.
*/
class Solution {
public:

    int removeBoxes(vector<int>& boxes) {

        int n = boxes.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));

        // length = size of current interval
        for(int len = 1; len <= n; len++) {

            for(int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                // k in decreasing order because
                // dp[x][j][k+1] is required
                for(int k = n - 1; k >= 0; k--) {

                    // Option 1:
                    // Remove boxes[i] along with k attached boxes

                    int ans = (k + 1) * (k + 1);

                    if(i + 1 <= j) {
                        ans += dp[i + 1][j][0];
                    }

                    // Option 2:
                    // Merge boxes[i] with a future
                    // box having the same color

                    for(int m = i + 1; m <= j; m++) {

                        if(boxes[m] == boxes[i]) {

                            int left = 0;

                            if(i + 1 <= m - 1) {
                                left = dp[i + 1][m - 1][0];
                            }

                            int right = dp[m][j][k + 1];

                            ans = max(ans, left + right);
                        }
                    }

                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[0][n - 1][0];
    }
};
