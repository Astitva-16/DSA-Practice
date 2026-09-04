/*18. 4Sum
LeetCode link -> https://leetcode.com/problems/4sum/
*/

// APPROACH ->
/*
Pehle nums ko sort karo → duplicates handle karna aur two-pointer approach easy ho jaati hai.
i ko fix karo → phir j ko fix karo, aur remaining 2 elements ke liye left aur right pointers use karo.
sum = nums[i] + nums[j] + nums[left] + nums[right] calculate karo.
Agar sum < target → sum badhana hai → left++.
Agar sum > target → sum kam karna hai → right--.
Agar sum == target → valid quadruplet mil gaya → ans mein add karo.
i aur j ke duplicates skip karo → same quadruplet dobara na aaye.
Valid quadruplet milne ke baad left aur right ke duplicate values bhi skip karo, phir left++ aur right--.
1LL use kiya hai taaki sum calculate karte waqt integer overflow na ho.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n; j++){

                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while(left < right){

                    long long sum = 1LL*nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum < target) left++;

                    else if(sum > target) right--;

                    else{

                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while(left < right && nums[left] == nums[left + 1]) left++;

                        while(left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
