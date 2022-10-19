int intersectPoint(Node* head1, Node* head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    if(ptr1 == nullptr or ptr2 == nullptr) return -1;
    while(ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(ptr1 == nullptr) ptr1 = head2;
        if(ptr2 == nullptr) ptr2 = head1;
    }
    return ptr1->data;
}