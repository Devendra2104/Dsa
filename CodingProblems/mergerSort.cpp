#include <bits/stdc++.h>
#include<cassert>
using namespace std;
using ll = long long int; using ld = long double; using ull = unsigned long long;

template<typename T> istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' ';return os;}

const ll inf = 1e18, mod1 = 998244353, mod = 1e9 + 7;

void merge(int a[], int l, int r, int mid){
    int b[r-l+1];
    int k =0;
    int i=l; int j=mid+1;
    while(i <= mid and j <= r){
        if(a[i]<=a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int i=0;i<k;i++){
        a[l+i] = b[i];
    }
}

void mergeSort(int a[], int l , int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,r,mid);
}

void loop(){
    int a[] = {1,6,3,5,1,3,2,8};
    int sz = sizeof(a) / sizeof(a[0]);
    mergeSort(a,0,sz-1);
    for(int i=0;i<sz;i++) cout << a[i] << ' ';
}           




int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); ll t = 1;
    // cin>>t;
    for(ll i=0;i<t;i++){
        // cout << "Case #" << i+1 << ": ";
        loop();
    }
}