/**
The Sierpinski Fractal

Description

Consider a regular triangular area, divide it into four equal triangles of half height and remove the one in the middle. Apply the same operation recursively to each of the three remaining triangles. If we repeated this procedure infinite times, we'd obtain something with an area of zero. The fractal that evolves this way is called the Sierpinski Triangle. Although its topological dimension is 2, its Hausdorff-Besicovitch dimension is log(3)/log(2)~1.58, a fractional value (that's why it is called a fractal). By the way, the Hausdorff-Besicovitch dimension of the Norwegian coast is approximately 1.52, its topological dimension being 1.

For this problem, you are to outline the Sierpinski Triangle up to a certain recursion depth, using just ASCII characters. Since the drawing resolution is thus fixed, you'll need to grow the picture appropriately. Draw the smallest triangle (that is not divided any further) with two slashes, to backslashes and two underscores like this:
 /\
/__\

To see how to draw larger triangles, take a look at the sample output.
Input

The input contains several testcases. Each is specified by an integer n. Input is terminated by n=0. Otherwise 1<=n<=10 indicates the recursion depth.
Output

For each test case draw an outline of the Sierpinski Triangle with a side's total length of 2n characters. Align your output to the left, that is, print the bottom leftmost slash into the first column. The output must not contain any trailing blanks. Print an empty line after each test case.
Sample Input

3
2
1
0
Sample Output

       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\

   /\
  /__\
 /\  /\
/__\/__\

 /\
/__\


Accepted	4352K	313MS	C++	1212B

*/

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF ){
        if(n == 0) break;
        vector<string> strs;
        strs.push_back(" /\\");
        strs.push_back("/__\\");
        for(int i = 2; i<=n; i++){
            int len = (1<<i);
            vector<string> bottom;
            for(int j = 0; j<strs.size(); j++) {
                string str = strs[j];
                string tmp = str;
                while(tmp.length() < len) tmp += " ";
                bottom.push_back(tmp + str);
            }
            vector<string> next;
            for(int j = 0; j<strs.size(); j++) {
                string str = strs[j];
                string space = "";
                for(int j = 0; j<bottom.size(); j++) space += " ";
                next.push_back(space + str);
            }
            for(int j = 0; j<bottom.size(); j++) {
                string b = bottom[j];
                next.push_back(b);
            }
            strs = next;
        }

        for(int i = 0; i<strs.size(); ++i){
            cout<<strs[i]<<endl;
        }
        cout<<endl;
    }

    return 0;
}