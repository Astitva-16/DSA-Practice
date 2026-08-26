/*451. Sort Characters By Frequency
LeetCode link -> https://leetcode.com/problems/sort-characters-by-frequency/
*/

// APPROACH ->
/*
unordered_map mein har character ki frequency count karo.
max-heap banao with {frequency, character}.
Har (frequency, character) ko heap mein push karo → highest frequency top par.
Heap se top element nikalo:
freq = character kitni baar aaya
ch = kaunsa character hai
ans.append(freq, ch) → ch ko freq times answer mein add karo.
Jab tak heap empty nahi hota, repeat karo.
Finally ans return → characters frequency ke decreasing order mein sorted.
*/
class Solution {
public:

    typedef pair<int, char> pp;

    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        for(auto ch : s){
            mp[ch]++;
        }

        priority_queue<pp> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        string ans;

        while(!pq.empty()){

            int freq = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            ans.append(freq, ch);
        }

        return ans;
    }
};
