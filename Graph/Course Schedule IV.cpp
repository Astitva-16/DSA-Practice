/*1462. Course Schedule IV
LeetCode link -> https://leetcode.com/problems/course-schedule-iv/
*/

// approach ->
/*
Build an adjacency list and calculate the indegree of every course.
Push all courses with indegree = 0 into a queue (Kahn's Topological Sort).
Maintain pre[i], an unordered_set storing all prerequisites of course i.
While processing each course in topological order:
  For every neighbor:
    Add the current course as its prerequisite.
    Copy all prerequisites of the current course into the neighbor's prerequisite set.
    Decrease the neighbor's indegree and push it into the queue when it becomes 0.
After processing all courses, answer each query:
  If u exists in pre[v], return true; otherwise return false.
Return the answer for all queries.
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto pre : prerequisites){
            int u = pre[0];
            int v = pre[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<unordered_set<int>> pre(numCourses);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto neigh : adj[curr]){
                pre[neigh].insert(curr);

                for(auto p : pre[curr]){
                    pre[neigh].insert(p);
                }

                inDegree[neigh]--;
                if(inDegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }


        vector<bool> ans;

        for(auto& q : queries){
            int u = q[0];
            int v = q[1];

            ans.push_back(pre[v].count(u));
        }

        return ans;
    }
};
