class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* last = head, *p = head;
        for(int i=0;i<k-1;i++){
            last = last->next;
        }
        while(p->next) p = p->next;
        p->next = head;
        Node* res = last->next;
        last->next = nullptr;
        return res;
    }
};