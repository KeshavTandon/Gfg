//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int ori(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3){
        long long val = (x3-x2)*(y2-y1) - (x2-x1)*(y3-y2);
        if(val>0) return 1;
        if(val == 0) return 0;
        return 2;
    }
    bool onSeg(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3){
        return (x3>=min(x1,x2) and x3<=max(x1,x2) and y3>=min(y1,y2) and y3<=max(y1,y2));
    }
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        
        long long x1 = p1[0];
        long long y1 = p1[1];
        long long x2 = q1[0];
        long long y2 = q1[1];
        long long x3 = p2[0];
        long long y3 = p2[1];
        long long x4 = q2[0];
        long long y4 = q2[1];
        long long o1 = ori(x1,y1,x2,y2,x3,y3);
        long long o2 = ori(x1,y1,x2,y2,x4,y4);
        long long o3 = ori(x3,y3,x4,y4,x1,y1);
        long long o4 = ori(x3,y3,x4,y4,x2,y2);
        if(o1 != o2 and o3 != o4) return "true";
        if(o1 == 0 and onSeg(x1,y1,x2,y2,x3,y3)) return "true";
        if(o2 == 0 and onSeg(x1,y1,x2,y2,x4,y4)) return "true";
        if(o3 == 0 and onSeg(x3,y3,x4,y4,x1,y1)) return "true";
        if(o4 == 0 and onSeg(x3,y3,x4,y4,x2,y2)) return "true";
        return "false";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends