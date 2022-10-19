int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *fast = head;
       while(n-- and fast){
           fast = fast->next;
       }
       if(!fast and n>=0) return -1;
       Node *slow = head;
       while(fast){
           slow = slow->next;
           fast = fast->next;
       }
       return slow->data;
}