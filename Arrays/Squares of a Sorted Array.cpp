/*977. Squares of a Sorted Array
LeetCode link -> https://leetcode.com/problems/squares-of-a-sorted-array/
*/

// APPROACH ->
/*
Array already sorted hai → negative numbers left mein, positive numbers right mein.
low = 0 aur high = n-1 → dono ends se start karo.
abs(nums[low]) aur abs(nums[high]) compare karo → jiska absolute value bada, uska square bhi bada hoga.
ans ko right se fill karo because largest square last position par jaana chahiye.
Agar abs(nums[low]) > abs(nums[high]) → nums[low]² ko ans[i] mein daalo aur low++.
Otherwise → nums[high]² ko ans[i] mein daalo aur high--.
i ko n-1 se 0 tak move karo → har baar next largest square place hota jayega.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);

        int low = 0, high = n - 1;

        for(int i = n - 1; i >= 0; i--){

            if(abs(nums[low]) > abs(nums[high])){
                ans[i] = nums[low] * nums[low];
                low++;
            }

            else{
                ans[i] = nums[high] * nums[high];
                high--;
            }
        }

        return ans;
    }
};
