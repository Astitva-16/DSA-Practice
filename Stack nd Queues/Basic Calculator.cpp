/* 224. Basic Calculator
LeetCode link -> https://leetcode.com/problems/basic-calculator/
*/

/* stack approach - Build the number while reading digits.
                    On + or -, add the current number to the result and update the sign.
                    On (, save the current state (result and sign) in the stack.
                    On ), evaluate the bracket and merge it with the previous saved state.
*/

class Solution {
public:

    typedef long long ll;

    int calculate(string s) {
        int n = s.size();

        stack<int> st;

        ll number = 0;
        ll sign = 1;
        ll res = 0;

        for(auto ch : s){
            if(isdigit(ch)){

                number = number * 10 + (ch - '0'); //number bnaoo

            }

            else if(ch == '+'){
                //number bn chuka
                res += (number * sign);
                number = 0;
                sign = 1;

            }

            else if(ch == '-'){

                res += (number * sign);
                number = 0;
                sign = -1;

            }

            else if(ch == '('){

                st.push(res);
                st.push(sign);
                res = 0;
                number = 0;
                sign = 1;

            }

            else if(ch == ')'){

                res += (number * sign); //bracket solved
                number = 0;

                int old_sign = st.top();
                st.pop();

                int old_res = st.top();
                st.pop();

                res *= old_sign;
                res += old_res;

            }
        }

        res += (number * sign);

        return (int)res;
    }
};
