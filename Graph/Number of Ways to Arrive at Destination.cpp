/*1976. Number of Ways to Arrive at Destination
Leetcode link -> https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/

// approach -> 
/*
Convert the road list into an adjacency list storing {neighbor, time}.
Initialize:
  dist[] with LLONG_MAX (minimum time to each node).
  way[] with 0 (number of shortest paths).
  Set dist[0] = 0 and way[0] = 1.
Use a min-heap (priority queue) storing {time, node} and start from node 0.
While the priority queue is not empty:
  Pop the node with the minimum current time.
  If the popped time is greater than the stored distance, skip it.
Traverse all neighbors:
  If a shorter path is found:
    Update dist[neighbor].
    Set way[neighbor] = way[current].
    Push the updated node into the priority queue.
  If another shortest path with the same distance is found:
    Add the number of ways:
    way[neighbor] = (way[neighbor] + way[current]) % mod.
Return way[n-1], which is the number of shortest paths to the destination.
*/

class Solution {
public:

    long long mod = 1e9 + 7;

    typedef pair<long long, int> p;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];

        for(auto& road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        vector<long long> dist(n, LLONG_MAX), way(n, 0);

        pq.push({0, 0});
        dist[0] = 0;
        way[0] = 1;

        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u]) continue;

            for(auto neigh : adj[u]){
                int adjNode = neigh.first;
                long long time = neigh.second;

                if((d + time) < dist[adjNode]){
                    dist[adjNode] = d + time;
                    pq.push({d + time, adjNode});
                    way[adjNode] = way[u];
                }

                else if(d + time == dist[adjNode]){
                    way[adjNode] = (way[adjNode] + way[u]) % mod;
                }
            }
        }

        return way[n - 1] % mod;
    }
};
