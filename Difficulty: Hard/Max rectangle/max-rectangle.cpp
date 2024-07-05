//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
public:
    int maxArea(int arr[MAX][MAX], int n, int m) {
        vector<int> v;
        for(int j = 0 ;j<m;j++)
        {
            v.push_back(arr[0][j]);
        }
        int mx = MAH(v);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    v[j] = 0;
                } else {
                    v[j] += arr[i][j];
                }
            }
            mx = max(mx, MAH(v));
        }
        return mx;
    }

private:
    int MAH(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i <= n; ++i) {
            int height = (i == n) ? 0 : heights[i];
            while (!st.empty() && height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        return maxArea;
    }
    };


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends