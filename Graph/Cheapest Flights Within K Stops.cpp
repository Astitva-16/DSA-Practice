/*787. Cheapest Flights Within K Stops
LeetCode link -> https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/

// approach ->
/*
Convert the flight list into an adjacency list storing {destination, cost}.
Initialize the dist array with INT_MAX and set dist[src] = 0.
Start BFS from the source using a queue storing {node, currentCost}.
Process the graph level by level, where each level represents one stop.
For every neighbor:
  If currentCost + flightCost < dist[neighbor], update the distance.
  Push the neighbor with the updated cost into the queue.
Stop the BFS after k + 1 levels (i.e., at most k stops).
If dist[dst] is still INT_MAX, return -1; otherwise return the minimum cost.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);

        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];
            adj[u].push_back({v, wt});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, int>> q;
        q.push({src, 0});
        dist[src] = 0;

        int steps = 0;

        while(!q.empty() && steps <= k){

            int N = q.size();

            while(N--){
                int u = q.front().first;
                int d = q.front().second;

                q.pop();

                for(auto& neigh : adj[u]){
                    int v = neigh.first;
                    int cost = neigh.second;

                    if(d + cost < dist[v]){
                        dist[v] = d + cost;

                        q.push({v, d + cost});
                    }
                }
            }

            steps++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
