/*881. Boats to Save People
LeetCode link -> https://leetcode.com/problems/boats-to-save-people/
*/

// APPROACH ->
/*
Pehle people ko sort karo → smallest person low par, heaviest high par.
low aur high se 2 people ko boat mein lene ki try karo.
Agar people[low] + people[high] <= limit → dono ek boat mein ja sakte hain → low++.
Agar pair fit nahi hota → sirf heaviest person ko boat mein bhejo; low ko move nahi karo.
Har iteration mein high-- aur cnt++ → ek boat use ho gayi.
Jab low > high → saare people boats mein aa gaye → cnt return.
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());

        int cnt = 0;

        int low = 0, high = n - 1;

        while(low <= high){
            
            if(people[low] + people[high] <= limit){
                low++;
            }

            cnt++;
            high--;
        }

        return cnt;
    }
};
