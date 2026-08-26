/*215. Kth Largest Element in an Array
LeetCode link -> https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

// APPROACH ->
/*
Min-heap banao → priority_queue with greater<int>.
Array ke har element ko heap mein push karo.
Agar heap ka size k se bada ho → smallest element pop karo.
Isse heap mein hamesha k largest elements rahenge.
In k elements mein sabse chhota = Kth largest element.
Finally pq.top() return karo.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};
