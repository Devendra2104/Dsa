#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int target;
  cin>>target;
  vector<bool> dp(target+1);
  dp[0] = true;
  for(int i=0;i<n;i++){
    for(int j=target;j>=a[i];j--){
      dp[j] = dp[j] | dp[j-a[i]];
    }
  }
  cout << (dp[target] ? "YES" : "NO") << '\n';
}