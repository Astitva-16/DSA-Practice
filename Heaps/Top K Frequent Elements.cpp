/*347. Top K Frequent Elements
LeetCode link -> https://leetcode.com/problems/top-k-frequent-elements/
*/

// APPROACH ->
/*
unordered_map mein har number ki frequency count karo.
min-heap (priority_queue with greater) banao → {frequency, number} store karega.
Har (frequency, number) ko heap mein push karo.
Agar heap ka size k se bada ho → minimum frequency wala pop karo.
Isliye heap mein hamesha top K most frequent elements bache rahenge.
Heap se elements nikaal ke ans mein unke second (number) ko store karo.
*/
class Solution {
public:

    typedef pair<int, int> pp;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});

            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
