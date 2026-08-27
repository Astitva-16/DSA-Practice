/*632. Smallest Range Covering Elements from K Lists
LeetCode link -> https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
*/

// APPROACH ->
/*
min-heap mein har list ka first element push karo → {value, listIndex, elementIndex}.
currMax maintain karo → heap mein currently present elements ka maximum value.
Heap ka top() = current minimum value.
Current range = [minVal, currMax]; agar ye smaller hai → range update karo.
Jis list se minVal aaya, uska next element heap mein push karo.
currMax ko next element ke saath update karo.
Agar kisi list ka last element consume ho gaya → break, because ab har list se element present rakhna possible nahi hai.
range[1] - range[0] == 0 → range length 0, jo minimum possible hai → directly return.
*/

class Solution {
public:

    typedef pair<int, pair<int, int>> pp;

    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n = nums.size();

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        int currMax = INT_MIN;

        for(int i = 0; i < n; i++){
            if(!nums[i].empty()){

                pq.push({nums[i][0], {i, 0}});

                currMax = max(currMax, nums[i][0]);
            }
        }

        vector<int> range = {pq.top().first, currMax};

        while(true){

            auto top = pq.top();
            pq.pop();

            int minVal = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if(currMax - minVal < range[1] - range[0]){

                range = {minVal, currMax};

                if(range[1] - range[0] == 0) return range;
            }

            if(y + 1 == nums[x].size()) break;

            int nextVal = nums[x][y + 1];

            pq.push({nextVal, {x, y + 1}});

            currMax = max(currMax, nextVal);
        }

        return range;
    }
};
