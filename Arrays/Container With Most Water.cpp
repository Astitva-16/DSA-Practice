/*11. Container With Most Water
LeetCode link -> https://leetcode.com/problems/container-with-most-water/
*/

// APPROACH ->
/*
low = 0 aur high = n-1 → two pointers, dono ends se start.
Area/volume calculate karo:
min(nums[low], nums[high]) * (high - low).
Har step par maxi mein maximum area store karo.
Jis side ki height chhoti hai, us pointer ko move karo:
  nums[low] < nums[high] → low++
  Otherwise → high--
Smaller height wale pointer ko move karna zaroori hai, kyunki width already decrease ho rahi hai; area improve karne ka chance sirf smaller height badhne se hai.
Jab low >= high → saare possible containers check ho gaye.
Finally maxi return karo.
*/
class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;

        int maxi = INT_MIN;

        while(low < high){

            int vol = (min(nums[low], nums[high])) * (high - low);

            maxi = max(vol, maxi);

            if(nums[low] < nums[high]) low++;

            else high--;
        }

        return maxi;
    }
};
