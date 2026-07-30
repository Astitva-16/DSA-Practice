/*210. Course Schedule II
LeetCode link -> https://leetcode.com/problems/course-schedule-ii/
*/

// approach ->
/*
Build an adjacency list and calculate the indegree of every course.
Push all courses with indegree = 0 into a queue and add them to the answer.
Perform Kahn's Topological Sort:
  Pop a course from the queue.
  Decrease the indegree of all its neighbors.
  If a neighbor's indegree becomes 0, push it into the queue and add it to the answer.
Count the number of processed courses.
If all courses are processed (count == numCourses), return the topological order.
Otherwise, a cycle exists, so return an empty vector {}.
*/

class Solution {
public:

    vector<int> toposort(unordered_map<int, vector<int>> &adj, int n, vector<int> &inDeg){
        vector<int> ans;
        queue<int> q;

        int cnt=0;

        for(int i=0; i<n; i++){
            if(inDeg[i]==0){
                ans.push_back(i);
                cnt++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto &neighbour : adj[u]){
                inDeg[neighbour]--;

                if(inDeg[neighbour]==0){
                    q.push(neighbour);
                    ans.push_back(neighbour);
                    cnt++;
                }
            }
        }
        if(cnt==n) return ans;

        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDeg(numCourses, 0);
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }

    return toposort(adj, numCourses, inDeg);
    }
};
