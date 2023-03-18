class DoublyLinkedList
{
    public:
        string data;
        DoublyLinkedList *prev,*next;

    DoublyLinkedList(string url)
    {
        data = url;
        prev = NULL;
        next = NULL;
    }
};
class BrowserHistory {
public:
    DoublyLinkedList* linkedList_head;
    DoublyLinkedList* current;
    BrowserHistory(string homepage) {
        linkedList_head = new DoublyLinkedList(homepage);
        current = linkedList_head;

    }
    
    void visit(string url) {
        DoublyLinkedList* nw = new DoublyLinkedList(url);
        current->next = nw;
        nw->prev = current;
        current = nw;
    }
    
    string back(int steps) {
        while(steps > 0 && current->prev != NULL)
        {
            current = current->prev;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while(steps > 0 && current->next != NULL)
        {
            current = current->next;
            steps--;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
