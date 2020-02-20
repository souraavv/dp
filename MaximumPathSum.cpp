#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>adj[100];
int dp[100],dp1[100];
int a[100];

void dfs(int u,int par){
    dp1[u]=dp[u]=a[u];
    parent[u]=par;
    
    int mx=INT_MIN;
    for(int v:adj[u]){
        if(v==par)continue;
        dfs(v,u);
        mx=max(mx,dp[v]);
        dp1[u]+=dp[v];
    }
    if(mx<0)mx=0;
    dp[u]+=mx;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=1;i<=n;++i)cin>>a[i];
   for(int i=1;i<n;++i){
       int a,b;
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
   }
   int ans=0;
   dfs(1,0); // O(n)
 
   for(int i=1;i<=n;++i){ //O(n)
      dp[i]=max(dp[i],dp1[i]);
      ans=max(ans,dp[i]);
   }
   
   cout<<ans;

  
    
    
    return 0;
}

// Problem:  https://codeforces.com/contest/802/problem/J
// Solution: https://codeforces.com/contest/208/submission/71412132

// Problem 1: https://codeforces.com/contest/802/problem/K
// solution : https://codeforces.com/contest/802/submission/70599690
