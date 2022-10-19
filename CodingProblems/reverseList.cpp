class Solution
{
    public:
    //Function to reverse a linked list
    struct Node* dfs(Node* root){
        if(!root) return root;
        if(root->next == nullptr) return root;
        Node* what = dfs(root->next);
        root->next->next = root;
        root->next = nullptr;
        return what;
    }
    struct Node* reverseList(struct Node *head)
    {
        return dfs(head);
    }
    
};