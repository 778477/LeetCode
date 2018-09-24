//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;

//https://github.com/778477/LeetCode

/**
 
 911. Online Election
 
 In an election, the i-th vote was cast for persons[i] at time times[i].
 
 Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.
 
 Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.
 
 
 
 Example 1:
 
 Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
 Output: [null,0,1,1,0,0,1]
 Explanation:
 At time 3, the votes are [0], and 0 is leading.
 At time 12, the votes are [0,1,1], and 1 is leading.
 At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
 This continues for 3 more queries at time 15, 24, and 8.
 
 
 Note:
 
 1 <= persons.length = times.length <= 5000
 0 <= persons[i] <= persons.length
 times is a strictly increasing array with all elements in [0, 10^9].
 TopVotedCandidate.q is called at most 10000 times per test case.
 TopVotedCandidate.q(int t) is always called with t >= times[0].
 
 */

/**
 
 97 / 97 test cases passed.
 Status: Accepted
 Runtime: 512 ms
 
 */
class TopVotedCandidate {
private:
    unordered_map<unsigned, unsigned> votes;
    vector<int> topVote;
    vector<int> _times;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        votes.clear();
        topVote = vector<int>(times.size(), 0);
        _times = times;
        
        for(auto i = 0; i<persons.size(); ++i){
            int vote = persons[i];
            ++votes[vote];
            
            if(i == 0 || votes[vote] >= votes[topVote[i - 1]]){
                topVote[i] = vote;
            } else{
                topVote[i] = topVote[i - 1];
            }
            
        }
        
    }
    
    int q(int t) {
        return topVote[bfind(_times,t)];
    }
    
    unsigned long bfind(vector<int> times, int t){
        if(!times.empty() && t >= times.back()){
            return times.size() - 1;
        }
        unsigned long l = 0, r = times.size();
        unsigned long mid =  l + ((r - l)>>1);
        
        while(l < r){
            mid = l + ((r - l)>>1);
            if(times[mid] > t){
                r = mid;
            } else if(times[mid] < t){
                if(l+1 <= r && times[l+1] > t) return l;
                l = mid;
            } else {
                return mid;
            }
        }
        return l;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */


/**
 
 case 1:
 {0,1,1,0,0,1,0},{0,5,10,15,20,25,30},{3,12,25,15,24,8}
 
 case 16:
 ["TopVotedCandidate","q","q","q","q","q","q","q","q","q","q"]
 [[[0,0,1,1,2],[0,67,69,74,87]],[4],[62],[100],[88],[70],[73],[22],[75],[29],[10]]
 */

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    TopVotedCandidate *tvc = new TopVotedCandidate({0,1,0,1,1},{24,29,31,76,79});
    
    vector<int> ts = {28,24,29,77,30,25,76,75,81,80};
    
    for(auto t : ts){
        cout<<tvc->q(t)<<",";
    }
    return 0;
}

