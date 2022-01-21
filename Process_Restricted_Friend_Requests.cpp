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
// Print Template
template <typename T>
void print(vector <T> v) { for (T i : v) cout << i << " "; cout << '\n'; }
template <typename T>
void print(vector <vector <T>>& v) { for (vector <T>& vv : v) { for (T& i : vv) cout << i << " "; cout << '\n'; } }
template <typename T>
void print(T&& t) {cout << t << '\n';}
template <typename T, typename... Args>
void print(T&& t, Args&&... args){ cout << t << " "; print(forward<Args>(args)...); }
class Solution {
public:
    vll p,r;
    ll find(ll x){
    if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    void Union(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x != y){
            p[y] = x;
        }
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& queries) {
        int m = res.size(); int q = queries.size();
        p.resize(n); r.resize(n);
        iota(all(p),0);
        vector<bool> ans(q,false);
        for(ll i=0;i<q;i++){
            ll x = queries[i][0]; ll y = queries[i][1];
            int p = find(x); int q = find(y);
            int ok = 1;
            if(p != q){
                for(int j=0;j<m;j++){
                    int np = find(res[j][0]); int nq = find(res[j][1]);
                    if((np == p and nq == q) or (np == q and nq == p)){
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok){
                ans[i] = true;
                Union(x,y);
            }
        }
        return ans;
    }
};

int main(){
	Solution nw =  Solution();
	// call above function and give your inputs
}