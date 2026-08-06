/*
Problem - Best Time to buy and sell stocks
LeetCode - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?roomId=EGXeLj
*/

//APPROACH -> Find minimum price till ith position and check if the profit till i is maximum or not

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxprof = 0;
        int mini = INT_MAX;
        
        for(int i = 0; i < n; i++){
            mini = min(mini, prices[i]);
            
            int prof = prices[i] - mini;
            
            maxprof = max(prof, maxprof);
        }
        
        return maxprof;
        
    }
};
