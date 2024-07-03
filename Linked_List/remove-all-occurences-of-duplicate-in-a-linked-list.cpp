//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if (!head || !head->next) {
        return head;
    }

    Node* dum = new Node(0);
    dum->next = head;
    Node* pre = dum;
    Node* slo = head;

    while (slo) {
        bool isDuplicate = false;
        while (slo->next && slo->data == slo->next->data) {
            slo = slo->next;
            isDuplicate = true;
        }
        if (isDuplicate) {
            // Skip all duplicates
            slo = slo->next;
            continue;
        }
        // If no duplicates, link pre to slo
        pre->next = slo;
        pre = pre->next;
        slo = slo->next;
    }
    // Disconnect the last part of the list
    pre->next = NULL;
    return dum->next;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
