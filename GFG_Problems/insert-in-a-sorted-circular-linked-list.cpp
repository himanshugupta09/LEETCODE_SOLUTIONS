/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* pre = head;
        Node* cur = head->next;
        while(cur != head && cur->data < data)
        {
            cur = cur->next;
            pre = pre->next;
        }
        Node*  nw = new Node(data);
        pre->next = nw;
        nw->next = cur;
        if(data <= head->data)
        {
            swap(head->data,nw->data);
        }
        return head;
    }
};
