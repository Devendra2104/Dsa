class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head; Node *fast = head;
        Node *prv;
        while(slow and fast and fast->next){
            prv = slow;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                prv = fast;
                fast = fast->next;
            }
            prv->next = nullptr;
        }
    }
};