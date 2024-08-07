//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int ans=0,d=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            int j=i+1,k=arr.size()-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                int diff=abs(target-sum);
                if(diff<d) //
                {
                  ans=sum;
                  d=diff;
                }
                else if(d==diff)
                ans=max(ans,sum);
                
                if(sum<target)
                {
                    j++;
                }
                else if(sum>target)
                {
                    k--;
                }
                else return sum;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends