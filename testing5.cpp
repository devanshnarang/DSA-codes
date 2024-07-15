#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define flush cout<<flush;

/* -----------------------------------------integer ranges----------------------------------*/
#define imax INT_MAX
#define imin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define mod (int)(1e9 + 7)
#define ll long long
#define int ll

// data structures methods
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define Sort(arr) sort(arr.begin(), arr.end())
#define Dsort(arr) sort(arr.begin(), arr.end(), greater<int>())
#define rev(arr) reverse(arr.begin(), arr.end())
#define all(cont) cont.begin(), cont.end()
#define Sum(v, initial_sum) accumulate(v.begin(), v.end(), initial_sum)

// data structures
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define vv(a) vector<vector<a>>
#define ump(a, b) unordered_map<a, b>
#define omp(a, b) map<a, b>
#define ust(a) unordered_set<a>
#define ost(a) set<a>
#define maxheap(a) priority_queue<a>
#define minheap(a) priority_queue<a, vector<a>, greater<a>>

// take inputs and debug
#define debug(i) cout << i << endl;
#define input(arr)                       \
    for (int i = 0; i < arr.size(); i++) \
        cin >> arr[i];
#define print(arr)                       \
    for (int i = 0; i < arr.size(); i++) \
        cout << arr[i] << " ";
#define nline cout << endl
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

/*-------------------some specific functions---------------*/
#define iseven(n) ((n % 2) == 0)
#define isodd(n) ((n % 2) != 0)
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll exp(int a, int b){if (b == 0){return 1;}if (b == 1)return a;ll res = exp(a, b / 2);if (b&1) return res * res * a;return res * res;}
ll expMod(ll a, ll b, ll Mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % Mod; a = (a * a) % Mod; b = b >> 1;} return res;}
#define LCM(a,b) (a*b)/(__gcd(a,b))

/*------------------------ main code-----------------------*/

class SegmentTree
{

private:
    vector<int> seg;

public:
    void build(v(p(int,int)) &arr)
    {
        int size = arr.size();
        seg.resize(4 * size + 1);
        buildSegment(0, 0, size - 1, arr);
    }

    int Q(int ind, int low, int high, int l, int r)
    {

        if(r>l){
            return INT_MIN;
        }
        // no overlapping
        //[low high l r] or [l r low high]
        if (high < l || r < low)
        {
            return INT_MIN;
        }

        // complete overlapping
        // [l low high r]
        if (l <= low && high <= r)
        {
            return seg[ind];
        }

        // partial overlapping
        int mid = (low + high) >> 1;

        int left = Q(2 * ind + 1, low, mid, l, r);
        int right = Q(2 * ind + 2, mid + 1, high, l, r);

        return max(left , right);
    }

    void update(int ind, int low, int high, int i, int val)
    {

        if (low == high)
        {
            // you are the the index i
            seg[ind] = val;
            return;
        }

        // check where is the index i is present
        int mid = (low + high) >> 1;
        if (low <= i && i <= mid)
        {
            update(ind * 2 + 1, low, mid, i, val);
        }

        else
            update(ind * 2 + 2, mid + 1, high, i, val);

        seg[ind] = max(seg[ind * 2 + 1] , seg[ind * 2 + 2]);
    }

    // helper function to buildSegment segement of build()
    void buildSegment(int ind, int low, int high, v(p(int,int)) &arr)
    {

        if (low == high)
        {
            seg[ind] = arr[low].second;
            return;
        }

        int mid = (low + high) >> 1;

        buildSegment(ind * 2 + 1, low, mid, arr);
        buildSegment(ind * 2 + 2, mid + 1, high, arr);

        seg[ind] = max(seg[ind * 2 + 1] , seg[ind * 2 + 2]);
    }
};
void testcases(int testcase)
{

    int n;
    cin>>n;
    v(p(int,int))arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
    }

    int budget;
    cin>>budget;

    Sort(arr);

    v(int)cost(n);
    for(int i=0;i<n;i++){
        cost[i]=arr[i].first;
    }

    SegmentTree sgt;
    sgt.build(arr);
    int ans=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int y=budget-arr[i].first;

        int up=upper_bound(all(cost),y)-cost.begin();
        up--;
        int maxSec=sgt.Q(0,0,n-1,i+1,up);
        if(maxSec==INT_MAX)continue;
        ans=max(ans,arr[i].second+maxSec);
    }
    if(maxi<=0)cout<<-1<<endl;
    else{
        cout<<maxi<<endl;
    }
}

signed main()
{
    fastio();
    // int te;
    // cin >> te;
    // for (int i = 1; i <= te; i++) {
        testcases(0);
    // }
    return 0;
}