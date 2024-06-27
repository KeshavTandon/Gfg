//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int>&p1,pair<int,int>&p2)
    {
        return p1.second<p2.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>meetings(n);
       for(int i=0;i<n;i++)
       {
           meetings[i].first=start[i];
           meetings[i].second=end[i];
       }
       //on the basis of end time
       sort(meetings.begin(),meetings.end(),comp);
       int count=1;
       int freeTime=meetings[0].second;
       for(int i=1;i<n;i++)
       {
           if(meetings[i].first>freeTime)
           {
               freeTime=meetings[i].second;
               count++;
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends