//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
       unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++)
       {
           mp[s[i]]++; //calculating the freq of each character
       }
       
       int ans=0;
       for(int i=0;i<s.size();i++)
       {
           if((int(s[i])%2==0)&& mp[s[i]]!=-1)
           {
               if(mp[s[i]]%2==0){
               ans++;
               mp[s[i]]=-1;
               }
           }
           else if((int(s[i])%2!=0)&& mp[s[i]]!=-1)
           {
               if(mp[s[i]]%2!=0){
               ans++;
               mp[s[i]]=-1;
               }
           }
       }
       if(ans&1)
       return "ODD";
       else return "EVEN";
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends