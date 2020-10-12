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

//WORKS BETTER IN SPARSE GRAPH USE PRIM'S ALGO FOR DENSE GRAPH
// TIME COMPLEXITY ElogE

struct edge{
	int a,b,w;
};
bool comp(edge p,edge q){
	return p.w<q.w;
}
const int mxN=20005;    //1 based node system
int reprs[mxN];
int size[mxN];
int findrep(int n){     //finds representative of a set
	return n==reprs[n]?n:reprs[n]=findrep(reprs[n]);//uses path compression
}
void unionsets(int x,int y){   //connects two set
	int p=findrep(x);		   //joins smaller one to the larger one
	int q=findrep(y);
	if(size[p]<size[q]){
		swap(p,q);
	}
	size[p]+=size[q];
	reprs[q]=p;
}
bool ifMakingCycle(int x,int y){  //checks if two nodes are in same set
	if(findrep(x)==findrep(y)){   //here used to check formation of cycle
		return true;
	}
	return false;
}

int KruskalsMST(vector<edge> edgeList,vector<edge> &mstEdges){
	int weight=0;
	for(edge i: edgeList){
		if(ifMakingCycle(i.a,i.b)){
			continue;
		}
		unionsets(i.a,i.b);
		weight+=i.w;
		mstEdges.pb(i);
	}
	return weight;
}

int main()
{
	fastIO;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int t=1;
	// cin>>t;
	while(t--){
		int n,m,x,y;
		cin>>n>>m;
		vector<edge> edgeList(m);
		for(int j=0;j<m;j++){
			cin>>edgeList[j].a>>edgeList[j].b>>edgeList[j].w;
		}
		sort(edgeList.begin(), edgeList.end(),comp);

		for(int i=1;i<=n;i++){
			size[i]=1;
			reprs[i]=i;
		}
		vector<edge> mstEdges; //stores edges in the mst
		int weight=KruskalsMST(edgeList, mstEdges);  //stores weight of the MST

		cout<<weight<<endl;

		for(auto i: mstEdges){  //Printing edges in the MST
			cout<<i.a<<" "<<i.b<<" "<<i.w<<endl;
		}
	}

return 0;
}
/* Testing Graph: 1 
6 8
5 6 2
1 2 3
3 4 9
4 6 7
2 5 6
2 3 5
3 6 3
1 5 5
  Testing Graph: 2 
6 8
2 4 2
4 6 2
5 3 8
5 1 7
1 2 6
1 3 3
3 4 3
3 2 4
 Testing Graph: 3 
6 9
5 4 9
4 3 5
3 6 8
6 2 7
2 1 2
1 5 4
1 4 1
2 4 3
3 2 3
*/