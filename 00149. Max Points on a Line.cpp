
//	Accepted	104 ms	cpp
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        map<float,int> kmap;
        map<float,int>::iterator it;
        int size = points.size();
        if(size < 3) return size;
        int ans = 2;
        for(int i=0;i<size;i++)
        {
            kmap.clear();
            int yy = 1;
            int same = 0;
            float k;
            for(int j=0;j<size;j++)
            {
                if(i == j) continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    same++;
                    continue;
                }
                if(points[i].x == points[j].x) yy++;
                else
                {
                    k = (points[i].y-points[j].y)*1.0/(points[i].x-points[j].x);
                    if(kmap.find(k) != kmap.end())
                        kmap[k]++;
                    else
                        kmap[k] = 2;
                }
            }
            for(it = kmap.begin();it!=kmap.end();it++)
                if(it->second > yy) yy = it->second;
            yy+=same;
            if(yy > ans) ans = yy;
        }
        return ans;
    }
};
