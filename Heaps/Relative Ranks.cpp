/*506. Relative Ranks
LeetCode link -> https://leetcode.com/problems/relative-ranks/
*/

// APPROACH ->
/*
max-heap mein {score, index} store karo → highest score top par.
ans vector banao of size n, taaki original positions maintain rahein.
Heap se highest score nikalo aur uska index lo.
rank == 1 → "Gold Medal"
rank == 2 → "Silver Medal"
rank == 3 → "Bronze Medal".
Baaki ke liye → rank ko string mein convert karke store karo.
Har element ke baad rank++.
ans[index] mein store karne ki wajah se original order maintain rehta hai.
*/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < n; i++){
            pq.push({score[i], i});
        }

        vector<string> ans(n);

        int rank = 1;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int idx = top.second;

            if(rank == 1) ans[idx] = "Gold Medal";

            else if(rank == 2) ans[idx] = "Silver Medal";

            else if(rank == 3) ans[idx] = "Bronze Medal";

            else{
                ans[idx] = to_string(rank);
            }

            rank++;

        }

        return ans;
    }
};
