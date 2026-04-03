/*
Problem - Koko Eating Bananas
LeetCode - https://leetcode.com/problems/koko-eating-bananas/
*/

//APPROACH - 1 Brute Force -> Divide Speed k with each pile and check time of less than h
//Time Complexity - O(n × max(piles))
//Space Complexity - O(1)

class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        k = no. of bananas / hour

        int k = 1;

        while(true){
            int time = 0;
            for(int i = 0; i < n; i++){
                int t = ceil((double)piles[i] / k);

                time += t;
            }

            if(time <= h) return k;

            k++;
        }
    }
};



//APPROACH - 2 Optimised Way -> Divide Speed k with each pile and check time of less than h
//Time Complexity - O(n × log(max(piles))
//Space Complexity - O(1)

class Solution {
public:

    bool canEat(vector<int> &piles, int mid, int h){
        int actualTime = 0;

        for(auto &it : piles){
            int t = ceil((double)it / mid);
            
            actualTime += t;

            if(actualTime > h) return false;
        }

        return true;
        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = low + (high - low) / 2;

            if(canEat(piles, mid, h)) high = mid;

            else low = mid + 1;
        }

        return low;

    }
};
