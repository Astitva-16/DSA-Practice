/*1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
leetCode link -> https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
*/

// approach ->
/*
Create a distance matrix and initialize all distances to INT_MAX.
Fill the matrix using the given edges and set dist[i][i] = 0 for every city.
Apply the Floyd-Warshall Algorithm:
  Take every city k as an intermediate node.
  Update the shortest distance:
  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]).
After finding the shortest paths between all pairs, count for every city how many cities are reachable within distanceThreshold.
Keep track of the city with the smallest reachable count.
If multiple cities have the same count, return the city with the largest index (cnt <= cntCity handles this).
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // Initialize the distance matrix with a large value (INT_MAX)
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        
        // Set the distance for each edge
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];  // Set the distance from city1 to city2
            dist[it[1]][it[0]] = it[2];  // Set the distance from city2 to city1
        }
        
        // Set the diagonal to 0, as the distance from a city to itself is 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // Apply Floyd-Warshall Algorithm to find the shortest paths between all pairs of cities
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update the distance if a shorter path is found
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Initialize variables to track the city with the least reachable cities
        int cntCity = n;
        int cityNo = -1;

        // Check each city and count the number of cities within the threshold distance
        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                // If the distance to the adjacent city is within the threshold, increment count
                if (dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            // Update the city with the least number of reachable cities
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};
