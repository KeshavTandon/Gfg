//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int,int>mp;
        int sum=0;
        int length=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum==k)
            length=i+1;
            
            if(mp.find(sum-k)!=mp.end())
            length=max(length,i-mp[sum-k]);
            
            if(mp.find(sum)==mp.end())
            mp[sum]=i;
        }
        return length;
    } 

};
//

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends