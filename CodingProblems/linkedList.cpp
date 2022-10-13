#include <bits/stdc++.h>
#include<cassert>
#include<cstring>
using namespace std;
using ll = long long int; using ld = long double; using ull = unsigned long long;

template<typename T> istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' ';return os;}

const ll inf = 1e18, mod1 = 998244353, mod = 1e9 + 7;

class Node{
public:
    int data;
    Node* next;
    Node(){ data = 0; next = NULL; }
    Node(int x) { data = x; next = NULL; }

};

class linkedList{
    Node* head;
public:
    linkedList() { head = NULL; }
    void insertNode(int x){
        Node* newNode = new Node(x);
        if(!head) {
            head = newNode;
            return;
        }
        Node* t = head;
        while(t->next) t = t->next;
        t->next = newNode;
    }
    void deleteNode(int offset){
        if(!head) {
            cout << "List is Empty" << '\n';
            return;
        }
        int len = 0;
        Node *t1 = head, *t2 = NULL;
        while(t1){
            t1 = t1->next;
            len++;
        }
        if(offset > len){
            cout << "Index out of range" << '\n';
            return;
        }
        t1 = head;
        if(offset == 1){
            head = head->next;
            delete(t1);
            return;
        }
        for(int i=0;i<offset-1;i++){
            t2 = t1;
            t1 = t1->next;
        }
        t2->next = t1->next;
        delete(t1);
        return;
    }
    void print(){
        Node *t = head;
        while(t){
            cout << t->data << ' ' ;
            t = t->next;
        }
    }
};


void loop(){
    linkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.deleteNode(5);
    list.print();
}           




int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); ll t = 1;
    // cin>>t;
    for(ll i=0;i<t;i++){
        // cout << "Case #" << i+1 << ": ";
        loop();
    }
}