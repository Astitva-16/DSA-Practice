/* 901. Online Stock Span
LeetCode link -> https://leetcode.com/problems/online-stock-span/
*/

//stack approach same a nge...monotonic stack...keep popping until top is greater becomes greater than currrent

class StockSpanner {
public:

    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        while(!st.empty() && st.top().first <= price){

            span += st.top().second;

            st.pop();

        }

        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
