/*
Suppose we have at our disposal, two pointers. One of them points to the node A and the other one points to the node B. Let's call these pointers prev and cur respectively. We can simply use these two pointers to reverse the link between A and B.

cur.next = prev
The only problem with this is, we don't have a way of progressing further i.e. once we do this, we can't reach the node C. That's why we need a third pointer that will help us continue the link reversal process. So, we do the following instead.

third = cur.next
cur.next = prev
prev = cur
cur = third
We do the above iteratively and we will achieve what the question asks us to do. Let's look at the steps for the algorithm now.

We need two pointers, prev and cur as explained above.

The prev pointer should be initialized to None initially while cur is initialized to the head of the linked list.

We progress the cur pointer one step at a time and the prev pointer follows it.

We keep progressing the two pointers in this way until the cur pointer reaches the m^{th}m 
th
  node from the beginning of the list. This is the point from where we start reversing our linked list.

An important thing to note here is the usage of two additional pointers which we will call as tail and con. The tail pointer points to the m^{th}m 
th
  node from the beginning of the linked list and we call it a tail pointer since this node becomes the tail of the reverse sublist. The con points to the node one before m^{th}m 
th
  node and this connects to the new head of the reversed sublist. Let's take a look at a figure to understand these two pointers better.


The tail and the con pointers are set once initially and then used in the end to finish the linked list reversal.

Once we reach the m^{th}m 
th
  node, we iteratively reverse the links as explained before using the two pointers. We keep on doing this until we are done reversing the link (next pointer) for the n^{th}n 
th
  node. At that point, the prev pointer would point to the n^{th}n 
th
  node.

We use the con pointer to attach to the prev pointer since the node now pointed to by the prev pointer (the n^{th}n 
th
  node from the beginning) will come in place of the m^{th}m 
th
  node due after the reversal. Similarly, we will make use of the tail pointer to connect to the node next to the prev node i.e. (n+1)^{th}(n+1) 
th
  node from the beginning.
  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        if(curr->next == NULL){
            return curr;
        }
        while(left>1){
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* con = prev;
        ListNode* tail = curr;
        ListNode* third = NULL;
        while(right>0)
        {
            third = curr->next;
            curr->next = prev;
            prev = curr;
            curr = third;
            right--;
        }
        if(con!=NULL){
            con->next = prev;
        }else{
            head = prev;
            
        }
        tail->next = curr;
        return head;
        
    }
};
  
