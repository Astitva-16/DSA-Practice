/*1081. Smallest Subsequence of Distinct Characters
LeetCode link -> https://leetcode.com/problems/smallest-subsequence-of-distinct-characters
*/

//approach
/*
Store the last occurrence of every character in the string.
Maintain:
  A stack (here, a string) to build the answer.
  An inStack array to check if a character is already included.
Traverse the string character by character.
If the current character is already in the stack, skip it.
Otherwise, while:
  the stack is not empty,
  the top character is lexicographically larger than the current character,
  and the top character appears again later (last[top] > currentIndex),
pop it from the stack and mark it as not present.
Push the current character into the stack and mark it as present.
The final stack/string is the lexicographically smallest subsequence containing each distinct character exactly once.
*/

class Solution {
public:
    string smallestSubsequence(string s) {

        int n = s.size();

        vector<int> last(26);

        //last orrurrence of every character
        for(int i = 0; i < n; i++){
            last[s[i] - 'a'] = i;
        }

        vector<bool> inStack(26, false);
        string st;

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(inStack[ch - 'a']) continue;

            //remove larger characters from stack if they appear in future
            while(!st.empty() && st.back() > ch && last[st.back() - 'a'] > i){
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            inStack[ch - 'a'] = true;
        }

        return st;
    }
};
