#include<bits/stdc++.h>
#include<cassert>
#include<cstring>

using namespace std;


int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size(); int m=t.size();
    vector<int> lps(m);
    int i=1; int j=0;
    while(i<m){
        if(t[i]==t[j]){
            lps[i] = ++j;
            i++;
        }
        else{
            if(j) j = lps[j-1];
            else i++;
        }
    }
    i=0;j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++; j++;
        }
        else{
            if(j) j = lps[j-1];
            else i++;
        }
        if(j==m){
            cout << "Index :" << i << '\n';
            j = lps[j-1];
        }
    }
}




