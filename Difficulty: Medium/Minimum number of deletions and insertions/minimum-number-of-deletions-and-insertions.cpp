//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
	    for(int i=0;i<str1.size()+1;i++)
	    {
	        for(int j=0;j<str2.size()+1;j++)
	        {
	            if(i==0 || j==0)
	            dp[i][j]=0;
	        }
	    }
	    
	    for(int i=1;i<str1.size()+1;i++)
	    {
	        for(int j=1;j<str2.size()+1;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	            }
	        }
	    }
	    return str1.size()+str2.size()-2*dp[str1.size()][str2.size()];
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends