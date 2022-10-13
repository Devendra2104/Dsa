#include <bits/stdc++.h>
#include<cassert>
using namespace std;
using ll = long long int; using ld = long double; using ull = unsigned long long;

template<typename T> istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' ';return os;}

const ll inf = 1e18, mod1 = 998244353, mod = 1e9 + 7;

void heapify(int a[], int n, int i){
    int maximum = i; int L = 2*i+1; int R = 2*i+2;
    if(L<n and a[L] > a[maximum]){
        maximum = L;
    }
    if(R<n and a[R] > a[maximum]){
        maximum = R;
    }
    if(maximum != i){
        swap(a[maximum], a[i]);
        heapify(a,n,maximum);
    }
}

void heap(int a[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }   
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]); // this is the deletion operation in heap
        heapify(a,i,0);
    }
}

void insertHeap(vector<int> &v, int n){
    if(n == 0) return;
    int cur = n;
    int parent = ((cur + 1) / 2) - 1;
    if(v[parent] < v[cur]){
        swap(v[parent],v[cur]);
        insertHeap(v,parent);
    }
}

void loop(){
    int a[] = {1,6,3,5,1,3,2,8};
    int sz = sizeof(a) / sizeof(a[0]);
    heap(a,sz);
    for(int i=0;i<sz;i++) cout << a[i] << ' ';


    // this is online heap - sort by building heap everytime we insert

    int a[] = {10,20,15,30,40,4,5,610,23,35,89};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
        insertHeap(v,i);
    }
    cout << v << '\n';
}           




int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); ll t = 1;
    // cin>>t;
    for(ll i=0;i<t;i++){
        // cout << "Case #" << i+1 << ": ";
        loop();
    }
}