#include<bits/stdc++.h>
using namespace std;
const int N =1e6;
vector<int>adj[N];
int a[N];
int h[N];
int tovisit[N];
set<int>s;
int n,m;
int dp[N];
#define inf 9999999
void dfs(int u,int par){
     h[u]=1+h[par];
     int f=0;
     for(int v: adj[u]){
         if(v==par)continue;
         dfs(v,u);
         f=1;
     }
     if(not f)s.insert(u);
}
 
void dfs2(int u,int par){
    for(int v:adj[u]){
        if(v==par)continue;
        if(dp[u]>=inf){
                dp[v]=inf;
        }
        else{
            if(a[v]){
                dp[v]=1+dp[u];
                if(dp[v]>m)dp[v]=inf;
                }
                 
            }
        dfs2(v,u);
    }
 }
 
      
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1,0);
    if(a[1])dp[1]=1;
    dfs2(1,0);
    int ans=0;
    for(auto it: s)
        if(dp[it]<inf)
          ans++;
         
    cout<<ans<<endl;
   
    return 0;
}


// Problem: https://codeforces.com/contest/580/problem/C
