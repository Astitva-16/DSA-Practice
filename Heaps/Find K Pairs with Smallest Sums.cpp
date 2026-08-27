/*373. Find K Pairs with Smallest Sums
LeetCode link -> https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/

// APPROACH ->
/*
max-heap mein {sum, {num1, num2}} store karo → largest sum top par.
Sirf first min(n,k) and min(m,k) elements check karo, because k smallest pairs ke liye itne elements sufficient hain.
Har pair ka sum = nums1[i] + nums2[j] calculate karo.
Agar heap mein < k pairs hain → directly push.
Agar heap already k ka hai aur current sum < pq.top().first → largest sum remove karke current pair add karo.
Agar sum >= pq.top().first → break, because arrays sorted hain, so next j ke sums aur bade honge.
Finally heap mein k smallest-sum pairs hain → unhe ans mein push karo.
*/

class Solution {
public:

    typedef pair<int, pair<int, int>> pp;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<pp> pq;

        for(int i = 0; i < min(n, k); i++){
            for(int j = 0; j < min(m, k); j++){

                int sum = nums1[i] + nums2[j];

                if(pq.size() < k){
                    pq.push({sum, {nums1[i], nums2[j]}});
                }

                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }

                else break;
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});

            pq.pop();
        }

        return ans;

    }
};
