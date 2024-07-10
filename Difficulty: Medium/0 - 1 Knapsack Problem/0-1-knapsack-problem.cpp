//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int calculateKnapsack(int w,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        //Base Case
        if(n==0 || w==0)
        return 0;
        
        if(dp[n-1][w]!=-1) return dp[n-1][w];
        if(wt[n-1]<=w)
        {
            //include or exclude
            int include=val[n-1] + calculateKnapsack(w-wt[n-1],wt,val,n-1,dp);
            int exclude=calculateKnapsack(w,wt,val,n-1,dp);
            return dp[n-1][w]=max(include,exclude);
        }
        else return dp[n-1][w]=calculateKnapsack(w,wt,val,n-1,dp);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
      return calculateKnapsack(W,wt,val,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends