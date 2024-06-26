//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0){
                if(i-1>=0) //top
                {
                    ans+=matrix[i-1][j];
                }
                if(j-1>=0) //left
                {
                    ans+=matrix[i][j-1];
                }
                if(i+1<row) //bottom
                {
                    ans+=matrix[i+1][j];
                }
                if(j+1<col)
                {
                    ans+=matrix[i][j+1];
                }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends