//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		bool flag=false;
		int findFirstOccurence(int start,int end,int nums[],int target)
    {
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                flag=true;
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
    
    int findLastOccurence(int start,int end,int nums[],int target)
    {
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
	int count(int arr[], int n, int x) {
	    int ans1=findFirstOccurence(0,n-1,arr,x);
	    if(!flag) return 0;
        int ans2=findLastOccurence(0,n-1,arr,x);
        return ans2-ans1+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends