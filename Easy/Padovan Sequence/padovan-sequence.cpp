//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int padovanSequence(int n) {
        int MOD=1e9+7;
  vector<long long>hash(n+1);
  hash[0]=1,hash[1]=1,hash[2]=1;
  for(int i=3;i<=n;i++)
  {
      hash[i]=(hash[i-2]%MOD+hash[i-3]%MOD)%MOD;
  }
        return hash[n];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends