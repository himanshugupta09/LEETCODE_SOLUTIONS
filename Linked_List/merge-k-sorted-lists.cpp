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
 class cmp
 {
     public:
        bool operator()(ListNode *a , ListNode *b)
        {
            return a->val > b->val;
        }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

       
       priority_queue<ListNode* , vector<ListNode*> , cmp>pq;
       
       for(int i=0;i<lists.size();i++)
       {
           if(lists[i] != NULL)
           {
               pq.push(lists[i]);
           }
       }

       ListNode *dum = new ListNode(-1);
       ListNode *tail = dum;

       while(pq.size())
       {
           ListNode *temp = pq.top();
           pq.pop();

           tail->next = temp;
           tail = temp;

           if(temp->next != NULL)
           {
               pq.push(temp->next);
           }
       }
       return dum->next;
        
        
    }
};
