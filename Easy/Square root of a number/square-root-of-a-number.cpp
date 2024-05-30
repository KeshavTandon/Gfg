//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        int start=1,end=sqrt(x);
        long long int ans=1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            long long int num=mid*mid;
            if(num==x)
            return mid;
            else if(num>x)
            {
                end=mid-1;
            }
            else
            {
                ans=mid;
                start=mid+1;
            }
        }
        return floor(ans);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends