/*
Problem - Number of Flowers in Full Bloom
Leetcode - https://leetcode.com/problems/number-of-flowers-in-full-bloom/
*/

//APPROACH - Brute Force
//Time Complexity - O(n * f)
//Space Complexity - O(n)

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int f = flowers.size();

        int n = people.size();

        vector<int> ans(n);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < f; j++){

                int start = flowers[j][0];
                int end = flowers[j][1];

                if(people[i] >= start && people[i] <= end){

                    ans[i]++;
                }
            }
        }

        return ans;
    }
};



//APPROACH - Binary Search
//Time Complexity - O((n + f)logn)
//Space Complexity - O(n)

class Solution {
public:

    int bloom(vector<int>& arr, int target){

        int low = 0, high = arr.size() - 1;
        int ans = arr.size();

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    int death(vector<int>& arr, int target){

        int low = 0, high = arr.size() - 1;
        int ans = arr.size();

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int f = flowers.size();

        int n = people.size();

        vector<int> ans(n);

        vector<int> start(f);
        vector<int> end(f);

        for(int i = 0; i < f; i++){
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for(int i = 0; i < n; i++){
            int alive = bloom(start, people[i]);

            int died = death(end, people[i]);

            ans[i] = alive - died;
        }

        return ans;
    }
};
