class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<pair<int,Node*>> pq;
        for(int i=0;i<K;i++){
            pq.push(make_pair(-arr[i]->data,arr[i]));
        }
        Node *u = new Node(-1), *res = u;
        while(!pq.empty()){
            int _ = pq.top().first;
            Node *cur = pq.top().second;
            pq.pop();
            u->next = cur;
            u = u->next;
            if(cur->next) pq.push(make_pair(-cur->next->data,cur->next));
        }
        return res->next;
    }
};