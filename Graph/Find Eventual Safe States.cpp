/*802. Find Eventual Safe States
LeetCode link -> https://leetcode.com/problems/find-eventual-safe-states/
*/

// approach ->
/*
Build the reverse graph and calculate the outdegree of every node.
Push all terminal nodes (nodes with outdegree = 0) into a queue.
Perform Kahn's Topological Sort on the reverse graph:
  Pop a safe node.
  Add it to the answer.
  For every previous node in the reverse graph, decrease its outdegree.
  If a node's outdegree becomes 0, push it into the queue (it is also safe).
After processing all safe nodes, sort the answer.
Return the sorted list of safe nodes.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> rev(n); // reverse graph
        vector<int> outDegree(n, 0);

        // Build reverse graph and outdegree
        for (int u = 0; u < n; u++) {
            outDegree[u] = graph[u].size();

            for (int v : graph[u]) {
                rev[v].push_back(u);
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int prev : rev[node]) {

                outDegree[prev]--;

                if (outDegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
