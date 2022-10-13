#include <bits/stdc++.h>
#include<cassert>
using namespace std;
using ll = long long int; using ld = long double; using ull = unsigned long long;

template<typename T> istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' ';return os;}

const ll inf = 1e18, mod1 = 998244353, mod = 1e9 + 7;

int partition(int a[], int l, int r){
    srand(time(NULL));
    int random =  l + rand() % (r - l);
    swap(a[random], a[r]);
    int pivot = a[r];
    int piIdx = l;
    for(int i=l;i<r;i++){
        if(a[i] <= pivot){
            swap(a[piIdx], a[i]);
            piIdx++;
        }
    }
    swap(a[piIdx],a[r]);
    return piIdx;
}

void quickSort(int a[], int l, int r){
    if(l >= r) return;
    int pivot = partition(a,l,r);
    quickSort(a,l,pivot-1);
    quickSort(a,pivot+1,r);
}

void loop(){
    int a[] = {1,6,3,5,1,3,2,8};
    int sz = sizeof(a) / sizeof(a[0]);
    quickSort(a,0,sz-1);
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