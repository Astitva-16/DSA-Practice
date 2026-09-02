/*16. 3Sum Closest
LeetCode link -> https://leetcode.com/problems/3sum-closest/
*/

// APPROACH ->
/*
Pehle nums ko sort karo → two-pointer approach possible ho jaati hai.
ans ko initially first 3 elements ka sum rakho → current closest sum.
Har i ko fix karo, phir left = i+1 aur right = n-1 se two pointers chalao.
sum = nums[i] + nums[left] + nums[right] calculate karo.
Agar abs(target - sum) < abs(target - ans) → current sum target ke zyada close hai, so ans = sum.
Agar sum == target → exact answer mil gaya → directly target return.
Agar sum < target → sum badhana hai → left++.
Agar sum > target → sum kam karna hai → right--.
Saare possible combinations check hone ke baad ans return karo.
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++){
            
            int left = i + 1, right = n - 1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if(abs(target - sum) < abs(target - ans)) ans = sum;

                if(sum == target) return target;

                else if(sum < target) left++;
                
                else right--;
            }
        }

        return ans;
    }
};
