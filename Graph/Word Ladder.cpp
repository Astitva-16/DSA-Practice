/*127. Word Ladder
LeetCode link -> https://leetcode.com/problems/word-ladder/
*/

//approach ->
/*
Start BFS from beginWord with steps = 1.
Store all words from wordList in an unordered_set for O(1) lookup and remove beginWord.
While the queue is not empty:
  Pop the current word and its step count.
  If it is endWord, return the current steps.
For each character position in the current word:
  Replace it with every letter from 'a' to 'z'.
  If the new word exists in the set, remove it (mark visited) and push it into the queue with steps + 1.
If BFS ends without reaching endWord, return 0.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == endWord) return steps;
            
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                
                word[i] = original;
            }
        }
        
        return 0;
    }
};
