/*703. Kth Largest Element in a Stream
LeetCode link -> https://leetcode.com/problems/kth-largest-element-in-an-stream/
*/

// APPROACH ->
/*
min-heap banao jo k largest elements maintain karega.
Constructor mein k save karo aur saare nums heap mein push karo.
Agar heap ka size k se bada ho → smallest element pop karo.
add(val) mein new value heap mein push karo.
Phir agar size k se bada ho → smallest element remove karo.
Ab heap mein exactly k largest elements hain, isliye pq.top() = Kth largest element.
pq aur k ko class member banaya hai taaki add() ke multiple calls mein previous state maintain rahe.
*/
class KthLargest {
public:
    
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        
        this -> k = k;

        for(auto it : nums){
            pq.push(it);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        
        pq.push(val);

        if(pq.size() > k){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
