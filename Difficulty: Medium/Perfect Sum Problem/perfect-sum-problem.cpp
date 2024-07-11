//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int nums[], int n, int target)
	{
	    int MOD=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
            for(int i=0;i<n+1;i++)
            {
                for(int j=0;j<target+1;j++)
                {
                    if(i==0)
                        dp[i][j]=0;
                    if(j==0)
                        dp[i][j]=1;
                }
            }
            
            for(int i=1;i<n+1;i++)
            {
                for(int j=0;j<target+1;j++)
                {
                    if(nums[i-1]<=j)
                    {
                        dp[i][j]=(dp[i-1][j-nums[i-1]] %MOD + dp[i-1][j] %MOD)%MOD;
                    }
                    else dp[i][j]=dp[i-1][j] %MOD ;
                }
            }
            return dp[n][target] % MOD;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends