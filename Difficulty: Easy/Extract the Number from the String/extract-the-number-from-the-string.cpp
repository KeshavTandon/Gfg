//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isCharacter(char ch) {
        return !(ch >= '0' && ch <= '9') && (ch != ' ');
    }

    long long ExtractNumber(string sentence)  {
        int i = 0;
        string str = "0";
        long long number = 0;
        bool contain9 = false;
        
        while(sentence[i] != '\0') {
            
            if(isCharacter(sentence[i])) {
                i++;
            }
            
            else if(sentence[i] == ' ') {
                    if(str != "0") {
                        long long num = stoll(str);
                    
                        if(num > number && !contain9) {
                            number = num;
                        }
                        
                        contain9 = false;
                        str = "0";
                    }
                    i++;
                }
                
            else {
                str += sentence[i];
                if(sentence[i] == '9') {
                    contain9 = true;
                }
                i++;
            }
        }
        
        long long last = stoll(str);
        
        if(last > number && contain9 == false) return last;
        else if(number > 0)  return number; 
        else  return -1; 
    }

};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends