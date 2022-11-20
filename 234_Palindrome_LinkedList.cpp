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
    
    /*
    To check if the LinkedList is Palindrome or Not, firstly, we need to reach the Middle of the LinkedList using our Slow and Fast pointers approach.
After that, Slow pointer points to the Node just before the Middle of the Linked-List. 
We reverse the LinkedList from Middle of the Linkedlist. 
And then we have 2 pointers - Start & Mid. Mid points to Middle of the LinkedList(now reversed) & Start point to the Head of the LinkedList.
Before returning, we revert the same Linkedlist.
*/
    
    ListNode *reverse(ListNode* head)
    {
        /*
        We need Slow to point to a Node just before the Middle-most Node of the LinkedList
        That's why we make Fast move to the Second Last Node of the LinkedList only
        */
        
        if(head == NULL)
        {
            return head;
        }
        ListNode *p = NULL;
        ListNode *c = head;
        ListNode *n = head->next;
        
        while(c != NULL)
        {
            c->next = p;
            p = c;
            c = n;
            
            if(n != NULL)
            {
                n = n->next;
            }
            
        }
        return p;
        
        
    }
    
    
    
    bool isPalindrome(ListNode* head) {
        
        /*
         Slow pointer is now at the Node just before Middle Of the LinkedList
        We need to reverse the LinkedList from the Middle Of the LinkedList,that is, Slow's Next Node
         We need to attach the Reversed List into Slow's Next
         
         After reversing, we will check if the LinkedList is Palindrome or not using 2 pointers - Start and Mid
        Start will begin from Head and Mid will start from Slow's Next
        If at any moment, there's value doesn't match, we can directly return false
        Otherwise, we will keep moving them. If at any moment, Mid becomes NULL, it means the LinkedList is Palindrome, so before moving, we again make the Original Connections and return true
         */
        
        ListNode *s = head;
        ListNode *f = head;
        
        while(f->next !=NULL && f->next->next != NULL)
        {
            s = s->next;
            f = f->next->next;
            
        }
        
        s->next = reverse(s->next);
        
        ListNode *st = head;
        ListNode *md = s->next;
        
        while(md != NULL)
        {
            if(md->val != st->val)
            {
                return false;
            }
            st = st->next;
            md = md->next;
            
            
        }
        return true;
        
        
    }
};
