//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        int n=arr.size();
        vector<bool>left(n);
        vector<bool>right(n);
        int maxi=arr[0];
        left[0]=false,right[n-1]=false;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>maxi){
            left[i]=true;
            maxi=arr[i];
            }
            else left[i]=false;
        }
        int mini=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<mini)
            {
                right[i]=true;
                mini=arr[i];
            }
            else{
                right[i]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(left[i] && right[i])
            return arr[i];
        }
        return -1;
    }
};
//

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends