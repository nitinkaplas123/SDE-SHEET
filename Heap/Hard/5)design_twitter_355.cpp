Code-:

class Twitter {
  public:
    vector<pair<int, int>> posts;
    map<int, set<int>> followee;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        int cnt = 0;
        vector<int> res;

       
        for (int i = posts.size() - 1; i >= 0 and cnt < 10; i--) {
            pair<int, int> x = posts[i];
            if ((x.first == userId) or
                (followee[userId].find(x.first) != followee[userId].end())) {
                cnt++;
                res.push_back(x.second);
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followee[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followee[followerId].erase(followeeId);
    }
};