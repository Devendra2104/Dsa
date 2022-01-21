#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define readInputFile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define eb emplace_back
#define sz(a) ll(a.size())
#define mem(a, b) memset(a, (b), sizeof(a))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define Sum(a) {accumulate(all(a),0LL)}
#define f first
#define s second
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<' ';}cout<< endl;}}
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<ld> vld;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
// print
template <typename T>
void print(vector <T> v) { for (T i : v) cout << i << " "; cout << "\n"; }
template <typename T>
void print(vector <vector <T>>& v) { for (vector <T>& vv : v) { for (T& i : vv) cout << i << " "; cout << "\n"; } }
template <typename T>
void print(T&& t) {cout << t << "\n";}
template <typename T, typename... Args>
void print(T&& t, Args&&... args){ cout << t << " "; print(forward<Args>(args)...); }
// input
template<typename T>  istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>  ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
//debug template
void __print(int x) {cerr << x;} void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;} void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;} void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;} void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;} void __print(char x) {cerr << '"' << x << '"';}
void __print(const char *x) {cerr << '"' << x << '"';} void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
//Print Template.
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second);
cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ',' : ' '),
__print(i); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n == 1) return (gas[n-1] >= cost[n-1] ? 0 : -1);
        int start = n-1; int stop = n-2;
        int have = gas[start];
        while(start != stop){
            if(have - cost[start] >= 0){
                have = have - cost[start];
                start = (start + 1) % n;
                have = have +  gas[start];
            }
            else{
                have = have - cost[stop] + gas[stop];
                stop = (stop - 1 + n) % n;
            }
        }
        if(have - cost[stop] >= 0) return (stop + 1) % n;
        return -1;
    }
};
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Solution nw;
    ll n;
    cin>>n;
    vector<int> t(n); cin>>t;
    vector<int> c(n); cin>>c;
    int ans = nw.canCompleteCircuit(t,c);
    print(ans);
}