/*76. Minimum Window Substring
LeetCode link -> https://leetcode.com/problems/minimum-window-substring/
*/

// BRUTE FORCE
/*
  Start every substring from each index i.
  Keep adding characters by moving j.
  Store frequencies of the current substring.
  After every addition, check whether all characters of t are present with the required frequency.
  If yes, update the minimum window and stop expanding for this i.
*/
class Solution {
public:

    bool isValid(unordered_map<char, int>& freqS, unordered_map<char, int>& freqT){

        for(auto &it : freqT){

            if(freqS[it.first] < it.second)
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {

        int n = s.size();

        unordered_map<char, int> freqT;

        for(auto &ch : t)
            freqT[ch]++;

        int minLen = INT_MAX;
        int start = -1;

        for(int i = 0; i < n; i++){

            unordered_map<char, int> freqS;

            for(int j = i; j < n; j++){

                freqS[s[j]]++;

                if(isValid(freqS, freqT)){

                    if(j - i + 1 < minLen){

                        minLen = j - i + 1;
                        start = i;
                    }

                    break;
                }
            }
        }

        if(start == -1)
            return "";

        return s.substr(start, minLen);
    }
};




// OPTIMAL APPROACH
/*
  Store the frequency of all characters of t in a hashmap.
  Expand the window by moving j.
  Decrease the frequency of s[j].
  If the character was required (mp[ch] > 0), decrease cntreq.
  When cntreq == 0, the current window contains all characters of t.
  Shrink the window from the left (i) to make it as small as possible.
  Update the minimum window if the current one is smaller.
  Before removing s[i], increase its frequency.
  If its frequency becomes positive, it means a required character is removed, so increase cntreq and stop shrinking.
  Continue expanding until the end of s.
  Return the smallest valid window found.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        int m = t.size();

        if(m > n) return "";

        unordered_map<int, int> mp;

        for(auto ch : t){
            mp[ch]++;
        }

        int i = 0, j = 0, cntreq = m, minWindowSize = INT_MAX, start_i = 0;

        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0) cntreq--;

            mp[ch]--;

            while(cntreq == 0){
                //start shrinking

                int currWindowSize = j - i + 1;

                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    cntreq++;
                }

                i++;
            }

            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};
