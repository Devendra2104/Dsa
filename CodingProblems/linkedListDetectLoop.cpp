class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node *slow = head; Node * fast = head;
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return 1;
        }
        return 0;
    }
};