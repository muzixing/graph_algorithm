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
#define YesNo(f) if(f){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;continue;}
#define setval(a,val) memset(a,val,sizeof(a)) 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int PrimsMST(int n,vpi adj[],vpi &mstedges){ // 1 based node system

	priority_queue< pi,vector<pi>,greater<pi> >q;

	int start=1;  //Taking any node to start building the MST
	vi weight(n+1,INF);  //ith position stores min value edge ending at i
	vpi parent(n+1,mp(-1,INF));	//stores parent of a node in the mst
	vi inMST(n+1,false); //stores if node i is included in MST

	q.push(mp(0,start)); //starting the MST
	weight[start]=0;

	while(!q.empty()){
		int u=q.top().S;
		q.pop();
		inMST[u]=true; //includes node u in MST

		for(auto i: adj[u]){
			int v=i.F;
			int w=i.S;
			if(!inMST[v] && w<weight[v]){ //makes the weight minimum to
				weight[v]=w;				//include node v in MST using 
				q.push(mp(w,v));			//included nodes in MST
				parent[v]=mp(u,w);
			}
		}
	}
	int mstWeight=0;
	for(int i=1;i<=n;i++){
		if(parent[i].F==-1){
			continue;
		}
		mstWeight+=parent[i].S;
		mstedges.pb(mp(i,parent[i].F));
	}
	return mstWeight;
}	

int main()
{
	fastIO;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int t=1;
	// cin>>t;
	while(t--){
		int n,m,x,y,w;
		cin>>n>>m;
		vpi adj[n+1];
		for(int i=0;i<m;i++){
			cin>>x>>y>>w;
			adj[x].pb(mp(y,w));
			adj[y].pb(mp(x,w));
		}
		vpi mstEdges; // stores the edges in MST
		int weight=PrimsMST(n,adj,mstEdges); //stores weight of the MST

		cout<<weight<<endl;

		for(auto i: mstEdges){  //Printing edges in the MST
			cout<<i.F<<" "<<i.S<<endl;
		}
	}

return 0;
}
/* Testing Graph: 1 
9 13
1 2 4
1 8 8
2 3 8
2 9 11
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 9 6
8 9 7
*/