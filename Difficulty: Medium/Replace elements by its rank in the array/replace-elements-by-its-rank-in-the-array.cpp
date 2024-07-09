//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
typedef pair<int,int>pi;
    vector<int> replaceWithRank(vector<int> &arr, int N){
        //minHeap
        priority_queue<pi,vector<pi>,greater<pi>>minH;
        int mini=*min_element(arr.begin(),arr.end());
        for(int i=0;i<N;i++)
        {
            minH.push({abs(mini-arr[i]),arr[i]});
        }
        unordered_map<int,pair<int,int>>mp;
        int count=1;
        while(!minH.empty())
        {
            if(mp.find(minH.top().first)==mp.end())
            {
                mp[minH.top().first]={minH.top().second,count};
                count++;
            }
            else{
                int rank=mp[minH.top().first].second;
                mp[minH.top().first]={minH.top().second,rank};
            }
            minH.pop();
        }
        
        for(int i=0;i<N;i++)
        {
            arr[i]=mp[abs(arr[i]-mini)].second;
        }
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends