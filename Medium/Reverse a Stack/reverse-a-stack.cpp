//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void insert_at_bottom(int x,stack<int>&st)
{
    if(st.empty())
    {
        st.push(x);
    }
    else{
        int a=st.top();
        st.pop();
        insert_at_bottom(x,st);
        st.push(a);
    }
    
}
void reverse(stack<int>&st)
{
    if(st.size()>0)
    {
        int x=st.top();
        st.pop();
        reverse(st);
        insert_at_bottom(x,st);
        
    }
}
    
    void Reverse(stack<int> &st){
        reverse(st);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends