//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
       int sum=0;
       int MOD=1e9+7;
       for(int i=0;i<n;i++)
       {
           sum+=arr[i];
       }
      if((sum+d)&1) return 0;
       int diff=(d+sum)/2;
        vector<vector<int>>dp(n+1,vector<int>(diff+1,0));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<diff+1;j++)
            {
                if(i==0)
                {
                    dp[0][j]=0;
                }
                if(j==0)
                {
                    dp[i][0]=1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<diff+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=(dp[i-1][j-arr[i-1]] %MOD + dp[i-1][j] %MOD)%MOD;
                }
                else{
                    dp[i][j]=dp[i-1][j] %MOD ;
                }
            }
        }
        return dp[n][diff] %MOD;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends