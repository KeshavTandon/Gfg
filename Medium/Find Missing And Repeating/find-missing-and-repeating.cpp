//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        long long n=N;
        long long Sn=(n*(n+1)/2);
        long long S2n=(n*(n+1)*(2*n+1))/6;
        long long sumOfArray=0,sumOfSquareArray=0;
        for(int i=0;i<n;i++)
        {
            sumOfArray+=arr[i];
            sumOfSquareArray+=(long)arr[i]*(long)arr[i];
        }
        // cout << Sn << " " << S2n << " " << sumOfArray << " " << sumOfSquareArray;
        long long num1=sumOfArray-Sn;
        // cout << num1 << endl;
        long long num2=sumOfSquareArray-S2n; //3
        // cout << num2 << endl;
        num2=num2/num1;
        long long ans1=(num2+num1)/2; //2
        // cout << ans1 << endl;
        long long ans2=num2-ans1;
        // cout << ans2 << endl;
        // cout << "ans1" << ans1 << "ans2" << ans2 << endl;
        vector<int>ans={(int)ans1,(int)ans2};
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends