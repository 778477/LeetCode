//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//


#include <cstdio>
#include <cstdlib>

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 
 355. Design Twitter
 
 Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
 
 postTweet(userId, tweetId): Compose a new tweet.
 getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
 follow(followerId, followeeId): Follower follows a followee.
 unfollow(followerId, followeeId): Follower unfollows a followee.
 Example:
 
 Twitter twitter = new Twitter();
 
 // User 1 posts a new tweet (id = 5).
 twitter.postTweet(1, 5);
 
 // User 1's news feed should return a list with 1 tweet id -> [5].
 twitter.getNewsFeed(1);
 
 // User 1 follows user 2.
 twitter.follow(1, 2);
 
 // User 2 posts a new tweet (id = 6).
 twitter.postTweet(2, 6);
 
 // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
 twitter.getNewsFeed(1);
 
 // User 1 unfollows user 2.
 twitter.unfollow(1, 2);
 
 // User 1's news feed should return a list with 1 tweet id -> [5],
 // since user 1 is no longer following user 2.
 twitter.getNewsFeed(1);
 
 */


/**
 
 23 / 23 test cases passed.
 Status: Accepted
 Runtime: 48 ms
 
 */


class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        _postID = 0;
        userPost.clear();
        userFollow.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!userPost[userId]){
            userPost[userId] = new vector<pair<int, unsigned>>();
        }
        userPost[userId]->push_back(make_pair(tweetId, _postID++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, unsigned>> feeds;
        
        if(userPost[userId]){
            for( pair<int, unsigned> post : *userPost[userId]){
                feeds.push_back(post);
            }
        }
        
        if(userFollow[userId]){
            for( int followerId : *userFollow[userId] ){
                if(!userPost[followerId]) continue;
                for( pair<int, unsigned> post : *userPost[followerId]){
                    feeds.push_back(post);
                }
            }
        }
        
        sort(feeds.begin(), feeds.end(), [](const pair<int, unsigned> a, const pair<int, unsigned> b){
            return a.second > b.second;
        });
        
        vector<int> ans;
        auto len = feeds.size() > 10 ? 10 : feeds.size();
        
        for(auto i = 0; i < len ; i++){
            ans.push_back(feeds[i].first);
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return; // can't follwer self
        
        if(!userFollow[followerId]){
            userFollow[followerId] = new vector<int>();
        }
        
        if(!binary_search(userFollow[followerId]->begin(), userFollow[followerId]->end(), followeeId)){
            userFollow[followerId]->insert(lower_bound(userFollow[followerId]->begin(), userFollow[followerId]->end(), followeeId), followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(!userFollow[followerId]) return ;
        if(!binary_search(userFollow[followerId]->begin(), userFollow[followerId]->end(), followeeId)) return;
        
        userFollow[followerId]->erase(lower_bound(userFollow[followerId]->begin(), userFollow[followerId]->end(), followeeId));
    }
private:
    unsigned _postID;
    map<int,vector<pair<int,unsigned>> *> userPost;
    map<int,vector<int> *> userFollow;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(){
    return 0;
}
