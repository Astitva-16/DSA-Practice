/*207. Course Schedule
LeetCode link -> https://leetcode.com/problems/course-schedule/
*/

// approach ->
/*
Build an adjacency list and calculate the indegree of every course.
Push all courses with indegree = 0 into a queue (courses with no prerequisites).
Perform Kahn's Topological Sort:
  Pop a course from the queue.
  Increment the count of processed courses.
  For each neighbor, decrease its indegree.
  If a neighbor's indegree becomes 0, push it into the queue.
After processing, check the count:
  If all courses are processed (count == numCourses), return true.
  Otherwise, a cycle exists, so return false.
*/

class Solution {
public:
    bool check(unordered_map<int, vector<int>> &adj, int n, vector<int> &inDeg){
        queue<int> q;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(inDeg[i]==0){ 
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
                    cnt++;
                    q.push(neighbour);
                }
            }
        }

        if(cnt==n) return true;//was able to finish all courses
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        // vector<vector<int>> adj(numCourses);
        unordered_map<int, vector<int>> adj;
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }

        return check(adj, numCourses, inDeg);
    }
};
