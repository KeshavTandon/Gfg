//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[start]<=nums[mid])
            {
                //left part is sorted
                if(nums[start]<=target && nums[mid]>target)
                {
                    end=mid-1; 
                }
                else start=mid+1;
            }
            else{
                //right part is sorted
                if(nums[mid]<target && nums[end]>=target)
                {
                    start=mid+1;
                }
                else end=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends