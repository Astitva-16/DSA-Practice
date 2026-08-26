/*973. K Closest Points to Origin
LeetCode link -> https://leetcode.com/problems/k-closest-points-to-origin/
*/

// APPROACH ->
/*
Har point ka distance from origin calculate karo: x² + y².
max-heap mein {distance, point} store karo → farthest point top par.
Har point push karo, aur agar heap size k se bada ho → farthest point pop karo.
Isse heap mein hamesha k closest points rahenge.
Heap se points nikaal kar res mein store karo.
sqrt() nahi liya because x² + y² compare karna enough hai — smaller squared distance = closer point.
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue<pair<int, vector<int>>> pq;

        for(auto it : points){
            int x = it[0];
            int y = it[1];

            int dist = (x*x) + (y*y);

            pq.push({dist, it});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
