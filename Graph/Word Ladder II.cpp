/*126. Word Ladder II
LeetCode link -> https://leetcode.com/problems/word-ladder-ii/
*/

// approach ->
/*
Use BFS from start to find the minimum level (steps) at which every reachable word is visited. Store each word's level in a hash map (mpp).
During BFS, generate all possible words by changing one character at a time. If a generated word exists in the set, assign it steps + 1, push it into the queue, and remove it from the set.
Stop BFS once end is reached since only the shortest paths are needed.
Start DFS (backtracking) from end towards start.
At each step, generate all one-letter transformations. Move only to words whose level is exactly one less (mpp[next] = mpp[curr] - 1), ensuring we follow only the shortest path.
When start is reached, reverse the current sequence and store it in the answer.
*/

class Solution {
public:
    void dfs(string curr, string start, unordered_map<string, int>& mpp,
             vector<vector<string>>& ans, vector<string>& seq) {
        string temp = seq.back();

        if (curr == start) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        for (int i = 0; i < temp.length(); i++) {
            char org = temp[i];
            int steps = mpp[temp];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (mpp.find(temp) != mpp.end() && mpp[temp] < steps) {
                    seq.push_back(temp);
                    dfs(temp, start, mpp, ans, seq);
                    seq.pop_back();
                }
            }
            temp[i] = org;
        }
    }

    vector<vector<string>> findLadders(string start, string end, vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        queue<string> q;
        unordered_map<string, int> mpp;
        vector<vector<string>> ans;

        q.push(start);
        st.erase(start);
        mpp[start] = 1;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            if (word == end){
                break;
            }
            int steps = mpp[word];

            for (int i = 0; i < word.length(); i++) {
                char org = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        mpp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = org;
            }
        }

        vector<string> sequence;
        sequence.push_back(end);

        dfs(end, start, mpp, ans, sequence);
        return ans;
    }
};
