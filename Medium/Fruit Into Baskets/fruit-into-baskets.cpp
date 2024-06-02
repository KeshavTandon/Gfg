//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int left=0,right=0;
        unordered_map<int,int>mp;
        int maxi=0;
        while(right<N)
        {
            mp[fruits[right]]++;
            if(mp.size()>2)
            {
                mp[fruits[left]]--;
                
                if(mp[fruits[left]]==0){
                  mp.erase(fruits[left]);
                }
                
                left++;
            }
            if(mp.size()<=2)
            {
                maxi=max(maxi,right-left+1);
            }
            right=right+1;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends