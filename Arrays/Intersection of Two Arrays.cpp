/*349. Intersection of Two Arrays
LeetCode link -> https://leetcode.com/problems/intersection-of-two-arrays/
*/

// APPROACH ->
/*
Pehle dono arrays ko sort karo → two-pointer approach possible ho jaati hai.
i aur j ko 0 se start karo → dono arrays ke current elements compare karenge.
Agar nums1[i] < nums2[j] → nums1[i] smaller hai → i++.
Agar nums2[j] < nums1[i] → nums2[j] smaller hai → j++.
Agar dono equal hain → common element mil gaya → ans mein add karo, phir i++ aur j++.
ans.empty() || ans.back() != nums1[i] → duplicate common elements ko answer mein dobara add hone se rokta hai.
Jab kisi ek array ke elements khatam ho jaayein → loop stop, aur ans return.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;

        int i = 0, j = 0;
        
        while(i < n1 && j < n2){

            if(nums1[i] < nums2[j]) i++;

            else if(nums2[j] < nums1[i]) j++;

            else{
                if(ans.empty() || ans.back() != nums1[i]) ans.push_back(nums1[i]);

                i++;
                j++;
            }
        }

        return ans;
    }
};
