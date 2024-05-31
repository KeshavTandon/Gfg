//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
bool isPossible(vector<int>&stalls,int mid,int k,int n)
{
    int cows=1,dis=stalls[0];
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-dis>=mid)
        {
            cows++;
            dis=stalls[i];
        }
    }
    return cows>=k;
}
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int start=1,end=stalls[n-1];
        int ans=1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(stalls,mid,k,n))
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends