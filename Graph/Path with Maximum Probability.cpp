/*1514. Path with Maximum Probability
LeetCode link -> https://leetcode.com/problems/path-with-maximum-probability/
*/

// approach ->
/*
Convert the edge list into an adjacency list storing {neighbor, probability}.
Initialize the prob[] array with 0 and set prob[start] = 1 (100% probability at the start node).
Use a max-heap (priority queue) storing {probability, node} so that the node with the highest probability is processed first.
While the priority queue is not empty:
  Pop the node with the maximum current probability.
  If the popped probability is smaller than the stored probability, skip it.
Traverse all neighbors:
  Compute the new probability:
    newProb = currentProb × edgeProb.
  If newProb > prob[neighbor], update prob[neighbor] and push it into the priority queue.
After processing all nodes, return prob[end_node], which is the maximum success probability.
*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        priority_queue<pair<double, int>> pq;

        vector<double> prob(n, 0);

        pq.push({1, start_node});
        prob[start_node] = 1;

        while(!pq.empty()){
            double currProb = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(currProb < prob[node]) continue;

            for(auto neigh : adj[node]){
                int adjNode = neigh.first;
                double adjProb = neigh.second;

                if(currProb * adjProb > prob[adjNode]){
                    prob[adjNode] = currProb * adjProb;
                    pq.push({currProb * adjProb, adjNode});
                }
            }
        }

        return prob[end_node];
    }
};
