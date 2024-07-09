//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        int maxi=max(K1,K2);
        int sum=0;
        priority_queue<int>maxH;
        for(int i=0;i<N;i++)
        {
            maxH.push(A[i]);
            if(maxH.size()>maxi)
            maxH.pop();
        }
        vector<int>smallestElements;
        while(!maxH.empty())
        {
            // cout << maxH.top() << " ";
            smallestElements.push_back(maxH.top());
            maxH.pop();
        }
        // for(int i=0;i<maxi;i++)
        // {
        //     cout << smallestElements[i] << " ";
        // }
        reverse(smallestElements.begin(),smallestElements.end());
        int element1=smallestElements[K1-1];
        int element2=smallestElements[K2-1];
        // cout << element1 << " " << element2 << endl;
        for(int i=0;i<N;i++)
        {
            if(A[i]>element1 && A[i]<element2)
            sum+=A[i];
        }
        return sum;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends