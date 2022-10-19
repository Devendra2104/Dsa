class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        map<int,int> m;
        Node *u = new Node(-1);
        Node *r = u;
        for(Node *t=head;t;t=t->next){
            if(m[t->data]) continue;
            u->next = t;
            u = u->next;
            m[t->data] = 1;
        }
        u->next = NULL;
        return r->next;
    }
};