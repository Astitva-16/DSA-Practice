/*15. 3Sum
LeetCode link -> https://leetcode.com/problems/3sum/
*/

// APPROACH ->
/*
Pehle nums ko sort karo → duplicates handle karna aur two-pointer approach easy ho jaati hai.
i ko fix karo → ab left = i+1 aur right = n-1 se two pointers use karo.
nums[i] + nums[left] + nums[right] ka sum calculate karo.
Agar sum == 0 → valid triplet mil gaya, ans mein add karo.
Duplicate triplets avoid karne ke liye matching ke baad duplicate left aur right values skip karo.
sum < 0 → sum badhana hai → left++.
sum > 0 → sum kam karna hai → right--.
i ke duplicates bhi skip karo → same triplet dobara generate nahi hoga.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++){

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while(left < right){

                int sum = nums[left] + nums[i] + nums[right];

                if(sum == 0){
                    ans.push_back({nums[left], nums[i], nums[right]});

                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }

                else if(sum < 0){
                    left++;
                }

                else right--;

            }
        }

        return ans;
    }
};
