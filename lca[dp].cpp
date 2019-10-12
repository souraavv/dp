#include<bits/stdc++.h>
using namespace std;
#define LG 11
#define N 1024
int P[N][20];
int lvl[N];
vector<int>adj[N];

void dfs(int u,int par){
    P[u][0]=par;
    lvl[u]=1+lvl[par];
    for(int v:adj[u]){
        if(v==par)continue;
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(lvl[u]<=lvl[v])swap(u,v);
    int lg;
    for(lg=0;lvl[u]>=(1<<lg);++lg);
    lg--;
    
    for(int i=lg;i>=0;--i){
        if(lvl[u]-(1<<i)>=lvl[v])
            u=P[u][i];
    }
    
    if(u==v)
      return u;
    
    for(int i=lg;i>=0;--i){
        if( P[u][i]!=-1 and P[u][i]!=P[v][i]){
            u=P[u][i],v=P[v][i];
        }
    }
    
    return P[u][0];
}


int main(){
    int n;
    cin>>n;

    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int j=0;j<20;++j)for(int i=0;i<=n;++i)P[i][j]=-1;
    lvl[0]=-1;
    dfs(1,0);
    
    for(int i=1; i<LG; i++){
        for(int j=1;j<=n;++j)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}

    
    
    cout<<lca(10,3);
    
}


/*

#include<bits/stdc++.h>
using namespace std;

// learning centroid decomposition;

const int N=int(1e5)+10;
const int LOGN= 20;
const int INF = int(1e9);
set<int> g[N];
int par[N],sub[N],level[N],ans[N];
int dp[LOGN][N];
int n,m;

//----- Pre-Processing ----- 

void dfs0(int u,int par){
    for(auto v: g[u]){
        if(v!=dp[0][u]){
            dp[0][v]=u;
            level[v]=1+level[u];
            dfs(v);
        }
    }
}

void preprocess(){
    level[0]=0;
    dp[0][0]=0;
    dfs0(0,-1);
    for(int i=1;i<LOGN;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=dp[i-1][dp[i-1][j]];
}

int lca(int a,int b){
    if(level[a]>level[b])swap(a,b);
    
    int d=level[b]-level[a];
    
    for(int i=0;i<LOGN;++i)
        if(d&(1<<i))
            b=dp[i][b]; // modified b to its parent at w^i;
        
    if(a==b)return a;
    for(int i=LOGN-1;i>=0;i--)
        if(dp[i][a]!=dp[i][b])
            a=dp[i][a],b=dp[i][b];
            
    return dp[0][a];
            
}

int dist(int u,int v){
    return level[u]+level[v]-2*level[lca(u,v)];
}


//---------- Decomposition Part---------------------

int nn;

void dfs1(int u,int par){
    sub[u]=1;
    nn++;
    for(auto v: g[u]){
        if(v==par)continue;
        dfs(v,u);
        sub[u]+=sub[v];
    }
}

int dfs2(int u,int par){
    for(auto v: g[u])
        if(v!=par and sub[v]>nn/2)
            return dfs(v,u);
    return u;
}


void decompose(int root, int p){
    nn=0;
    dfs1(root,root);
    int centroid=dfs2(root,root);
    if(p==-1)p=centroid;
    par[centroid]=p;
    
    for(auto v: g[centroid]){
        g[v].erase(centroid);
        decompose(v,centroid);
    }
    g[centroid].clear();
}


//------------------ Handle the Queries -------------------

void update(int u){
    int x=u;
    while(1){
        ans[x]=min(ans[x],dist(x,u));
        if(x==par[x])break;
        x=par[x];
    }
}

int query(int u){
    
    int x=u;
    int ref=INF;
    while(1){
        ret =min(ret,dist(u,x)+ans[x]);
        if(x==par[x])break;
        x=par[x];
    }
    return ret;
}
int main(){
    
    
    
    return 0;
}

	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u-1].insert(v-1);
		g[v-1].insert(u-1);
	}
	preprocess();
	decompose(0,-1);
	for(int i=0;i<n;i++)
		ans[i]=INF;
	update(0);//first node is initially painted red
	while(m--)
	{
		int t,v;
		scanf("%d %d",&t,&v);v--;
		if(t==1)
			update(v);
		else
			dout(query(v));
	}
	return 0;

*/
