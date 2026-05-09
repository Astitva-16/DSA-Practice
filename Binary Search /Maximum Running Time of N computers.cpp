/*
Problem - Maximum Running Time of N Computers
LeetCode - https://leetcode.com/problems/maximum-running-time-of-n-computers/
*/

//APPROACH - Binary Search -> For every minute from min of batteries time to total number of time each computer needs
//Time Complexity - O(s * log(high - low))
//Space Complexity - O(1)

class Solution {
public:

    typedef long long ll;

    bool possible(int n, vector<int>& batteries, ll mid){

        ll target = 1LL * n * mid;

        for(int i = 0; i < batteries.size(); i++){

            target -= min(mid, (ll)batteries[i]);

            if(target <= 0) return true;
        }

        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

        int s = batteries.size();

        ll sum = 0; 

        for(auto &it : batteries){

            sum += it;
        }

        ll low = *min_element(begin(batteries), end(batteries));

        ll high = sum / n;

        ll ans = 0;

        while(low <= high){

            ll mid = low + (high - low) / 2;

            if(possible(n, batteries, mid)){
                ans = mid;
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }

        return ans;

    }
};
