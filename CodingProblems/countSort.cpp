#include <bits/stdc++.h>
#include<cassert>
#include<cstring>
using namespace std;
using ll = long long int; using ld = long double; using ull = unsigned long long;

template<typename T> istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' ';return os;}

const ll inf = 1e18, mod1 = 998244353, mod = 1e9 + 7;

void countSort(int a[], int n){
    int cnt[10];
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    for(int i=1;i<10;i++){
        cnt[i] += cnt[i-1];
    }
    int sorted[n];
    for(int i=0;i<n;i++){
        sorted[cnt[a[i]]-1] = a[i];
        cnt[a[i]]--;
    }
    for(int i=0;i<n;i++){
        a[i] = sorted[i];
    }
}

void loop(){
    int a[] = {8,7,1,2,1,3,4,5,2,6,6,8,9,9,2,4,5,2,3,3};
    int n = sizeof(a) / sizeof (a[0]);
    countSort(a,n);
    for(int i=0;i<n;i++) cout << a[i] << ' ';
}           




int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); ll t = 1;
    // cin>>t;
    for(ll i=0;i<t;i++){
        // cout << "Case #" << i+1 << ": ";
        loop();
    }
}