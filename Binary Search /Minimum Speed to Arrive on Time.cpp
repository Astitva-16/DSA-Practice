/*
Problem - Minimum Speed to Arrive on Time
LeetCode - https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
*/

//APPRAOCH - 1 Brute Force -> Linear Search on speed from 1 to 10e7
//Time Complexity - O(n * 10e7)
//Space Complexity - O(1)

class Solution {
public:

    bool canReach(vector<int>& dist, double hour, int speed, int n){
        double time = 0;

        //before n - 1 as last train should have nrml division
        for(int i = 0; i < n - 1; i++){
            time += ceil((double)dist[i] / speed);
        }

        time += (double)dist[n - 1] / speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        for(int speed = 1; speed <= 10e7; speed++){
            if(canReach(dist, hour, speed, n)) return speed;
        }

        return -1;
    }
};



//APPROACH - 2 Optimised Way -> Binary Search on speed between 1 to 10e7
//Time Complexity - O(n * log 10e7)
//Space Complexity - O(1)

class Solution {
public:

    bool canReach(vector<int>& dist, double hour, int speed, int n){
        double time = 0;

        //before n - 1 as last train should have nrml division
        for(int i = 0; i < n - 1; i++){
            time += ceil((double)dist[i] / speed);
        }

        time += (double)dist[n - 1] / speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        if(hour <= n - 1) return -1;

        int low = 1, high = 10e7, ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canReach(dist, hour, mid, n)){
                ans = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return ans;
    }
};
