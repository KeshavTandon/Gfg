//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int>nextGreatertoLeft;
       stack<int>st;
       for(int i=0;i<n;i++)
       {
           if(st.empty())
           nextGreatertoLeft.push_back(-1);
           else if(!st.empty() && price[st.top()]>price[i])
           nextGreatertoLeft.push_back(st.top());
           else if(!st.empty() && price[st.top()] <=price[i])
           {
               while(!st.empty() && price[st.top()] <=price[i])
               {
                   st.pop();
               }
               if(st.empty())
               nextGreatertoLeft.push_back(-1);
               else
               nextGreatertoLeft.push_back(st.top());
           }
           st.push(i);
       }
       for(int i=0;i<n;i++)
       {
           nextGreatertoLeft[i]=i-nextGreatertoLeft[i];
       }
       return nextGreatertoLeft;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends