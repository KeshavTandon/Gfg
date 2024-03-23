//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        int MOD=1e9+7;
        vector<int>dp(n+1);
        vector<int>ans;
        ans.push_back(0);
        if(n>=1)
        ans.push_back(1);
        if(n>=2)
        ans.push_back(1);
        dp[0]=0,dp[1]=1,dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
            ans.push_back(dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends