#include<bits/stdc++.h>
#include<cstring>
#include<cassert>
using namespace std;
using ll = long long int;

class Trie{
public:
    bool isEnd;
    Trie* ch[26];
    Trie(){
        isEnd = false;
        for(ll i=0;i<26;i++) ch[i] = nullptr;
    }
    void insert(string w){
        Trie *root = this;
        for(ll i=0;i<w.size();i++){
            if(!root->ch[w[i]-'a']) root->ch[w[i]-'a'] = new Trie();
            root = root->ch[w[i]-'a'];
        }
        root->isEnd = true;
    }
    bool search(string w){
        Trie *root = this;
        for(ll i=0;i<w.size();i++){
            if(!root->ch[w[i]-'a']) return 0;
            root = root->ch[w[i]-'a'];
        }
        return root and root->isEnd;
    }
    bool isEmpty(Trie* root){
        for(ll i=0;i<26;i++)
            if(root->ch[i]) return 0;
        return 1;
    }
    Trie* Delete(Trie* root,string w, ll depth = 0){
        if(!root) return root;
        if(depth == w.size()){
            if(root->isEnd) root->isEnd = false; // this will delete the key
            if(isEmpty(root)){
                delete(root);
                root = nullptr;
            }
            return root;
        }
        root->ch[w[depth]-'a'] = Delete(root->ch[w[depth]-'a'],w,depth+1);
        if(isEmpty(root) and !root->isEnd){
            delete(root);
            root = nullptr;
        }
        return root;
    }   
};

int main(){
    char str[] = "";
    char *p = NULL;
    cout << *str << '\n';
}
