//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int>tempMapper;
       int left=0,right=0,n=s.size();
       for(int i=0;i<n;i++)
       {
           tempMapper[s[i]]++;
       }
       if(tempMapper.size()<k) return -1;
       
       
       unordered_map<char,int>mp;
       int ans=0;
       while(right<n)
       {
           mp[s[right]]++;
           if(mp.size()>k)
           {
               mp[s[left]]--;
               if(mp[s[left]]==0)
               mp.erase(s[left]);
               left++;
           }
           if(mp.size()<=k)
           {
               ans=max(ans,right-left+1);
           }
           right++;
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends