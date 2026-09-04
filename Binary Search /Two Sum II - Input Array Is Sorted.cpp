/*167. Two Sum II - Input Array Is Sorted
LeetCode link -> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

// APPROACH ->
/*
Ye approach sorted array ke liye hai → low = 0, high = n-1.
nums[low] + nums[high] ka sum calculate karo.
Agar sum == target → required pair mil gaya → loop break.
Agar sum < target → sum badhana hai → low++.
Agar sum > target → sum kam karna hai → high--.
Finally {low + 1, high + 1} return karo → 1-based indices required hain.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low < high){

            int sum = nums[low] + nums[high];

            if(sum == target){
                break;
            }

            else if(sum < target){
                sum = 0;
                low++;
            }

            else{
                sum = 0;
                high--;
            }
        }

        return {low + 1, high + 1};        
    }
};
