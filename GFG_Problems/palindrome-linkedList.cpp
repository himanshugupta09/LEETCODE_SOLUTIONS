//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    Node* reverseList(Node* nw) {
    Node* n1 = nw;
    Node* pre = NULL;

    while (n1) {
        Node* dum = n1->next;
        n1->next = pre;
        pre = n1;
        n1 = dum;
    }
    return pre; // Return the new head of the reversed list
}

bool isPalindrome(Node *head) {
    if (!head) return true; // Handle empty list

    Node* cur = head;
    int ln = 0;
    while (cur) { // Count the length of the list
        ln++;
        cur = cur->next;
    }

    cur = head;
    int mid = ln / 2;
    Node* nw = head;

    for (int n = 0; n < mid; n++) {
        nw = nw->next; // Move nw to the middle
    }

    if (ln % 2) { // If the length is odd, skip the middle node
        nw = nw->next;
    }

    nw = reverseList(nw); // Reverse the second half
    Node* l = head;

    while (l && nw) { // Compare both halves
        if (l->data != nw->data) {
            return false;
        }
        nw = nw->next;
        l = l->next;
    }
    return true; // If all values matched, it's a palindrome
}

};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends
