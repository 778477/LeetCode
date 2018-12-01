/**
 [[5,15],[3,19],[6,7],[2,10],[5,16],[8,14],[10,11],[2,19]]
 
 1,  6   finish 7day         continue
 1,  10  continue            continue
 6,  8   continue            continue
 8,  2   finish 9day         finish 3day
 10, 5   finish 14day        finish 8day
 11, 5   contiue             finish 13day
 16, 3   finish 17day        finish 16day
 17, 2                       finish 18day
 
 
 
 6,7         6 < 7
 2,10        2 + 6 < 7
 10,11       2 + 6 < 11
 8,14        2 + 6 < 14
 5,15        2 + 5 + 6 < 15
 5,16        2 + 5 + 5 < 16
 2,19        2 + 2 + 5 + 5 < 19
 3,19        2 + 2 + 3 + 5 + 5 < 19
 
 96 / 96 test cases passed.
 Status: Accepted
 Runtime: 288 ms
 */

static int x=[](){ios::sync_with_stdio(false); cin.tie(NULL); return 0;}();

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<int> c;
        
        sort(courses.begin(), courses.end(), [](const vector<int> a,
                                                const vector<int> b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        int total = 0;
        for(vector<int> cour : courses){
            if(cour[0] + total <= cour[1]){
                total += cour[0];
                c.insert(lower_bound(c.begin(),c.end(), cour[0]),
                         cour[0]);
            } else if(!c.empty() &&
                      cour[0] < c.back() &&
                      total + cour[0] - c.back() <= cour[1]){
                total -= c.back();
                c.pop_back();
                total += cour[0];
                c.insert(lower_bound(c.begin(),c.end(), cour[0]),
                         cour[0]);
            }
        }
        return c.size();
    }
};

