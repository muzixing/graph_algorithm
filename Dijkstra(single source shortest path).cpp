#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
#define md 998244353 
#define INF INT_MAX
#define vl vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define ml map<ll,ll>
#define mi map<int,int>
#define m(a,b) map<a,b>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mxn 100005
#define printfloat(y) cout<<fixed<<setprecision(9)<<y<<endl;
#define YesNo(f) if(f){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;continue;}
#define setval(a,val) memset(a,val,sizeof(a)) 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//WORKS IF THERE IS NO NEGATIVE EDGE    WORKING TIME O(nlogn+m)

vpi adj[mxn];
ll dist[mxn],parent[mxn];
void dijkstra(int source){
    priority_queue<pi> q;
    bool processed[mxn];
    setval(processed,false);
    dist[source]=0;
    q.push({0,source});
    while (!q.empty()) {
        int a=q.top().second; 
        q.pop();
        if(processed[a]){
            continue;
        }
        processed[a]=true;
        for(auto u :adj[a]){
            int b=u.first;
            ll w=u.second;
            if(dist[a]+w<dist[b]){
                dist[b]=dist[a]+w;
                parent[b]=a;
                q.push({-dist[b],b});
            }
        }
    }
}
void printPath(int source,int destination){
    vi path;
    path.pb(destination);
    while(destination!=source){
        path.pb(parent[destination]);
        destination=parent[destination];
    }
    reverse(path.begin(), path.end());
    for(auto i: path){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    fastIO;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m,source=1,destination;
        cin>>n>>m;
        destination=n;
        for(int j=0;j<m;j++){
            int a,b;
            ll w;
            cin>>a>>b>>w;
            adj[a].pb(mp(b,w));
            adj[b].pb(mp(a,w));
        }
        for(int i=1;i<=n;i++){
            dist[i]=1e12;
        }
        // cin>>source;  //if source is given
        // cin>>destination; // if destination is given
        dijkstra(source);
        // cout<<dist[n];
        if(dist[n]==1e12){
            cout<<-1<<endl;
        }else{
            // cout<<dist[n]<<endl;
            printPath(source,destination);
        }

    }

return 0;
}