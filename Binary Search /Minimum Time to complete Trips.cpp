/*
Problem - Minimum Time to Complete Trips
LeetCode - https://leetcode.com/problems/minimum-time-to-complete-trips/
*/

//APPRAOCH - 1 Brute Force -> For every t from t = 1 calculate trips for each index
//Time Complexity - O(n * t)
//Space Complexity - O(1)

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int t = 1;

        while(true){
            long long trips = 0;

            for(int i = 0; i < n; i++){
                trips += t / time[i];

                if(trips >= totalTrips) return t;
            }

            t++;
        }
    }
};



//APPRAOCH - 2 Optimised way -> Binary search on trips from 1 to min_element * totalTrips
//Time Complexity - O(n * log(t))
//Space Complexity - O(1)

class Solution {
public:

    typedef long long ll;

    bool possible(vector<int> &time, ll mid, int totalTrips){
        ll actualTrips = 0;

        for(auto &it : time){
            actualTrips += mid / it;

            if(actualTrips >= totalTrips) return true;
        }

        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        ll low = 1, high = (ll) *min_element(time.begin(), time.end()) * totalTrips;

        while(low < high){
            ll mid = low + (high - low) / 2;

            if(possible(time, mid, totalTrips)) high = mid;

            else low = mid + 1;
        }

        return low;
    }
};
