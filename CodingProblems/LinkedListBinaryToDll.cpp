class Solution
{
    public: 
    Node *head = NULL, *prv = NULL;
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(!root) return root;
        bToDLL(root->left);
        if(!prv) head = root;
        else{
            prv->right = root;
            root->left = prv;
        }
        prv = root;
        bToDLL(root->right);
        return head;
    }
};