// approach
/*
Dijkstra's Algorithm (Priority Queue) – Short Revision
Convert the edge list into an adjacency list storing {neighbor, weight}.
Initialize the dist array with INT_MAX and set dist[src] = 0.
Push {0, src} into a min-heap (priority queue).
While the priority queue is not empty:
  Pop the node with the smallest distance.
  If the popped distance is greater than the stored distance, skip it.
Traverse all adjacent nodes:
  If currentDist + edgeWeight < dist[adjNode], update the distance and push the new {distance, adjNode} into the priority queue.
After all nodes are processed, return the dist array containing the shortest distance from the source to every node.
*/

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto top = pq.top();
            int d = top.first;
            int node = top.second;
            pq.pop();
            
            if(d > dist[node]) continue;
            
            for(auto neigh : adj[node]){
                int adjNode = neigh.first;
                int wt = neigh.second;
                
                if(d + wt < dist[adjNode]){
                    dist[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        
        return dist;
        
    }
};
