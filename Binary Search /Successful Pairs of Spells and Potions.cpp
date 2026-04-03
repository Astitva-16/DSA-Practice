/*
Problem - Successful Pairs of Spells and Potions
LeetCode - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
*/

//APPROACH - 1 Brute Force -> Simply check each spell with each potion
//Time Complexity - O(N^2)
//Space Complexity - O(N)

class Solution {
public:
    typedef long long ll;

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        
        vector<int> ans;

        for(int i = 0; i < n; i++){

            int cnt = 0;

            for(int j = 0; j < m; j++){
                ll str = spells[i] * potions[j];

                if(str >= success) cnt++;

            }

            ans.push_back(cnt);
        }

        return ans;
    }
};



//APPROACH - 2 Optimised Way - Sort potion, check if mid can success, then all biggen than mid can
//Time Complexity - O(n * log n)
//Space Complexity - O(N)

class Solution {
public:
    typedef long long ll;

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        
        vector<int> ans;

        sort(potions.begin(), potions.end());

        for(int i = 0; i < n; i++){
            
            int low = 0, high = m - 1;

            while(low <= high){
                int mid = low + (high - low) / 2;

                ll str = (1LL)*spells[i] * potions[mid];

                if(str >= success) high = mid - 1;

                else low = mid + 1;
            }

            ans.push_back(m - high - 1);
        }

        return ans;
    }
};
