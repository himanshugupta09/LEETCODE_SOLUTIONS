//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head)
    {
        Node* prev = NULL;
        Node* cur = head;
        Node* nxt = cur;
        while(nxt != NULL)
        {
            nxt = nxt->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        Node* res = new Node(0);
        Node* nxt = res;
        
        int car = 0;
        while(num1 != NULL || num2 != NULL || car != 0)
        {
            int sum = car;
            if(num1 != NULL)
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if(num2 != NULL)
            {
                sum += num2->data;
                num2 = num2->next;
            }
            nxt->next = new Node(sum%10);
            car = sum/10;
            nxt = nxt->next;
            
        }
        res=reverseList(res->next);
        Node *p1 = res;
        while(p1->data == 0)
        {
            p1=p1->next;
        }
        res = p1;
       
        return res;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
