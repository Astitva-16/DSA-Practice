/*402. Remove K Digits
LeetCode link -> https://leetcode.com/problems/remove-k-digits/
*/

/*Approach: Monotonic Increasing Stack.
Short Logic: Chhota number banane ke liye stack mein increasing order maintain karo aur bade elements k baar remove karo.

Empty stack (ya string as stack) banao.
Number ki digits ko traverse karo.
Jab tak k > 0 hai aur stack ka top current digit se bada hai, pop karke k decrement karo.
Current digit ko stack mein push karo.
Agar k bacha hai toh last se k elements remove kar do.
Leading zeros ko remove karke final string construct karo.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();

        stack<char> st;

        if(k == n) return "0";

        for(int i = 0; i < n; i++){

            while(!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')){
                st.pop();
                k--;
            }

            st.push(num[i]);

        }

        while(k > 0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        while(ans.size() != 0 && ans.back() == '0'){
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        if(ans.empty()) return "0";

        return ans;
        
    }
};
