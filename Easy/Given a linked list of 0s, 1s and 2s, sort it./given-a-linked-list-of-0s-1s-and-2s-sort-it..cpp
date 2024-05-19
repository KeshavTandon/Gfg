//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        vector<int>storeLL;
        Node* current=head;
        while(current!=NULL)
        {
            storeLL.push_back(current->data);
            current=current->next;
        }
        //all my numbers will get stores in vector
        int start=0,middle=0,end=storeLL.size()-1;
        while(middle<=end)
        {
            if(storeLL[middle]==0){
                swap(storeLL[start],storeLL[middle]);
                start++,middle++;
            }
            else if(storeLL[middle]==1)
            {
                middle++;
            }
            else //middle->2
            {
                swap(storeLL[middle],storeLL[end]);
                end--;
            }
        }
        Node* answer=new Node(-1);
        Node* ans=answer;
        for(int i=0;i<storeLL.size();i++)
        {
            ans->next=new Node(storeLL[i]);
            ans=ans->next;
        }
        return answer->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends