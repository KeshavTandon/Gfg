//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int index,vector<int>&arr,int k,vector<int>&dp)
    {
        if(index == 0) return 0;
        //i have to make recursive call for k steps
        if(dp[index]!=-1) return dp[index];
        int ans=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int lt=INT_MAX;
            
            if(index-i>=0)
            lt=solve(index-i,arr,k,dp) + abs(arr[index]-arr[index-i]);
            
            ans=min(ans,lt);
        }
        return dp[index]=ans;
    }
    
    int minimizeCost(vector<int>& arr, int& k) {
       int n=arr.size();
       vector<int>dp(n,-1);
       return solve(n-1,arr,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends