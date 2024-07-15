#include<iostream>
#include<math.h>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
#include<string.h>
#include<set>
#include<iomanip>
#include<map>
#include<cstdlib>
using namespace std;
 
#define SORT(arr) sort(arr.begin(),arr.end())
#define ull unsigned long long
#define ll long long
#define v(a) vector<a>
#define all(a) (a.begin(),a.end())
#define pq(a) priority_queue<a>
#define p(a,b) pair<a,b>
#define vv(a) vector<vector<a> >
#define ump(a,b) unordered_map<a,b>
#define mp(a,b) map<a,b>
#define omp(a,b) map<a,b>
#define ust(a) unordered_set<a>
#define ost(a) set<a>
#define pr(a,b) pair<a,b>
 

vv(ll) dp1;
vv(ll) dp2;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
long long power(long long A, long long B)
{
    if (B == 0)
        return 1;
 
    long long res = power(A, B / 2);
 
    if (B % 2)
        return res * res * A;
    else
        return res * res;
}

void dfs(v(ll) adjLi[],ll root,ll par,ll k){
	for(auto it:adjLi[root]){
		if(it!=par)dfs(adjLi,it,root,k);
	}
	dp1[root][0]=1;
	for (int  dis = 1; dis <= k;dis++)
	{
		dp1[root][dis]=0;
		for(auto it:adjLi[root]){
			if(it!=par){
				dp1[root][dis]+=dp1[it][dis-1];
			}
		}
	}
	return;
}
 
void f(vector<ll> adjLi[],ll root,ll par,ll k){
	for(ll dis=0;dis<=k;dis++){
		dp2[root][dis]=dp1[root][dis];
	}
	if(par!=0){
		dp2[root][1]+=dp2[par][0];
		for (ll dis = 2; dis <= k; dis++)
		{
			dp2[root][dis]+=dp2[par][dis-1];
			dp2[root][dis]-=dp1[root][dis-2]; 
		}
		
	}
	for(auto it:adjLi[root]){
		if(it!=par)f(adjLi,it,root,k);
	}
}
void solve(){
    ll n,k;
	cin>>n>>k;
	vector<ll> adjLi[n+1];
	for (ll i = 0; i < n-1; i++)
	{
		int u,v;
		cin>>u>>v;
		adjLi[u].push_back(v);
		adjLi[v].push_back(u);
	}
	dp1.clear();
	dp1.resize(n+1,v(ll) (k+1,0));
	dp2.clear();
	dp2.resize(n+1,v(ll) (k+1,0));
	dfs(adjLi,1,0,k);
	f(adjLi,1,0,k);
	ll ans=0;
	for (ll i = 1; i <= n ; i++)
	{
		ans+=dp2[i][k];
	}
	cout<<(ans/2)<<endl;
	return;
		
}
 
 
int main(){
    fastIO();
    solve(); 
    return 0;
}
//0000
//1010
