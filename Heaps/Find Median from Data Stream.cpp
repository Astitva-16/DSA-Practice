/*295. Find Median from Data Stream
LeetCode link -> https://leetcode.com/problems/find-median-from-data-stream/
*/

// APPROACH ->
/*
2 heaps use kiye:
  max_heap → smaller half ke elements
  min_heap → larger half ke elements
num < max_heap.top() → num smaller half mein → max_heap.push(), otherwise min_heap.push().
Balance maintain karo → max_heap ka size min_heap se 1 se zyada nahi hona chahiye, aur min_heap bada ho toh uska top max_heap mein shift karo.
Is arrangement mein max_heap.top() = smaller half ka largest, aur min_heap.top() = larger half ka smallest.
Equal sizes → even elements → median = (max_heap.top() + min_heap.top()) / 2.0.
max_heap 1 element bada → odd elements → median = max_heap.top().
*/
class MedianFinder {
public:

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(max_heap.empty() || num < max_heap.top()){
            max_heap.push(num);
        }

        else{
            min_heap.push(num);
        }

        //always keep max_heap size greater than or equal to min_heap size

        if(abs((int)max_heap.size() - (int)min_heap.size()) > 1){
            min_heap.push(max_heap.top());

            max_heap.pop();
        }

        else if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());

            min_heap.pop();
        }

    }
    
    double findMedian() {
        
        if(max_heap.size() == min_heap.size()){ // mtlb even no. of elements h
            double mean = (max_heap.top() + min_heap.top()) / 2.0;

            return mean;
        }

        //else hmare paas odd no. of elements h

        return (double)max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
