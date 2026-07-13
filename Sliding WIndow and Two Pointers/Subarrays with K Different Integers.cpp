/*992. Subarrays with K Different Integers
LeetCode link -> https://leetcode.com/problems/subarrays-with-k-different-integers/
*/

/* sliding window approach- BRUTE FORCE
  Start every subarray from each index i.
  Use a hashmap to store the frequency of elements in the current subarray.
  Extend the subarray one element at a time (j).
  If distinct elements become more than k, stop checking further.
  Whenever the number of distinct elements becomes exactly k, increase the answer by 1.
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;

        for(int i = 0; i < n; i++){  

            unordered_map<int, int> mp;

            for(int j = i; j < n; j++){
                mp[nums[j]]++;

                if(mp.size() > k) break;

                else if(mp.size() == k) cnt++;

            }

        }

        return cnt;
    }
};




/* Optimal approach - two pointer
  Expand the window by moving j and add nums[j] to the frequency map.
  If the window becomes invalid (distinct > k):
  Move i until there are only k distinct elements left.
  Update i_bada = i because any subarray starting before i is invalid.
  Remove extra duplicate elements from the left:
  While freq[nums[i]] > 1, decrease its frequency and move i.
  Now [i...j] is the smallest valid window ending at j.
  
  Count valid subarrays:
  
  If distinct == k, then every starting index from i_bada to i forms a valid subarray.
  So add:
  count += (i - i_bada + 1)
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        int i = 0, j = 0, i_bada = 0, cnt = 0;

        while(j < n){
            freq[nums[j]]++;

            //handle invalid subarrays
            while(freq.size() > k){

                freq[nums[i]]--;
                if(freq[nums[i]] == 0) freq.erase(nums[i]);
            
                i++;
                i_bada = i;
            }

            //handle to find the smallest valid subarray ending at j
            while(freq[nums[i]] > 1){

                freq[nums[i]]--;
                i++;

            }

            if(freq.size() == k){
                cnt += (1 + i - i_bada);
            }

            j++;

        }

        return cnt;
    }
};
