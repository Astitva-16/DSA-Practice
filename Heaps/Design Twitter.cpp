/*355. Design Twitter
LeetCode link -> https://leetcode.com/problems/design-twitter/
*/

// APPROACH ->
/*
unordered_map mein har user ki tweets store karo → {time, tweetId}.
time har new tweet par increase hota hai → latest tweet ka time sabse bada.
follows map mein store karo ki kaunsa user kisko follow karta hai.
getNewsFeed() mein:
  User ki khud ki tweets heap mein push karo.
  Jinko user follow karta hai, unki tweets bhi heap mein push karo.
max-heap use kiya hai → latest tweet (time largest) top par.
Heap se maximum 10 tweets nikaalo → unke tweetId ko ans mein add karo.
follow() → follower ke follow-set mein followee add karo.
unfollow() → followee ko follow-set se remove karo.
*/
class Twitter {
public:

    int time = 0;

    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        time++;
        
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int, int>> pq;

        for(auto t : tweets[userId]) pq.push(t);

        for(auto f : follows[userId]){

            for(auto t : tweets[f]) pq.push(t);
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
