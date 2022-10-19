Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node *u = new Node(-1);
    Node *res = u;
    while(head1 or head2){
        if(head1 and head2){
            if(head1->data < head2->data){
                u->next = head1;
                head1 = head1->next;
            }
            else{
                u->next = head2;
                head2 = head2->next;
            }
        }
        else if(head1){
            u->next = head1;
            head1 = head1->next;
        }
        else{
            u->next = head2;
            head2 = head2->next;
        }
        u = u->next;
    }
    return res->next;
} 