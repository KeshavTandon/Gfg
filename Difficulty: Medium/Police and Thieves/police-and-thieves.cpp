//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P')
            {
                //either i can go to left or right i-k or i+k
                int left=max(0,i-k);
                int right=min(i+k,n);
                for(int j=left;j<=right;j++)
                {
                    if(arr[j]=='T')
                    {
                        arr[j]='C';
                        ans++;
                        break;
                    }
                }
               
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends