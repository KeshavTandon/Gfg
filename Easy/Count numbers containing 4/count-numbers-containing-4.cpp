//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool isFour(int n)
  {
      while(n!=0)
      {
          int rem=n%10;
          if(rem==4) return true;
          n/=10;
      }
      return false;
  }
    int countNumberswith4(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(isFour(i)) ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends