/*846. Hand of Straights
LeetCode link -> https://leetcode.com/problems/hand-of-straights/
*/

// APPROACH ->
/*
Pehle check karo n % groupSize != 0 → agar divisible nahi hai, groups nahi ban sakte, so false.
min-heap mein saare cards push karo → smallest card hamesha top par.
prev = previous selected card, curr = current group mein kitne cards hain.
Heap se smallest card nikalo:
  prev == -1 → group ka first card.
  top - prev == 1 → consecutive card, group mein add karo.
  Otherwise → abhi use nahi kar sakte, temp mein temporarily store karo.
Jab curr == groupSize → ek complete consecutive group ban gaya.
temp ke cards ko wapas heap mein push karo → next group banane ke liye available rahenge.
End mein agar curr != 0 → last group incomplete hai → false; otherwise → true.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        int curr = 0, prev = -1;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it : hand) pq.push(it);

        vector<int> temp;

        while(!pq.empty()){
            
            int top = pq.top();
            pq.pop();

            if(prev == -1 || top - prev == 1){
                prev = top;
                curr++;
            }

            else{

                temp.push_back(top);
            }

            if(curr == groupSize){

                curr = 0;
                prev = -1;

                for(auto it : temp) pq.push(it);

                temp = {};
            }
        }

        return curr ? false : true;
    }
};
