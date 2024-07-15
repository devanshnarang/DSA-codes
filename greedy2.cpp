//minimum cost to cut a board into squares
//if we have divided the grid in rectangles & a cut
//later will be done on multiple rectangles,
//then cost of the cut should be considered on each rectangle
//vertical cuts increase horizontal blocks
//horizontal cuts increase vertical blocks
bool cmp(int x,int y){
    return x>y;
}
ll minCostToBreakGrid(int n,int m,vector<ll> &vertical,vector<ll> &horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz=1;
    int vr=1;
    int h=0,v=0;
    ll ans=0;
    while(h<horizontal.size() and v<vertical.size()){
        if(vertical[v]>horizontal[h]){
            ans+=vertical[v]*vr;
            hz++;
            v++;
        }
        else{
            ans+=horizontal[h]*hz;
            vr++;
            h++;
        }
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]*hz;
        vr++;
        h++;  
    }
    while(v<vertical.size()){
        ans+=vertical[v]*vr;
        hz++;
        v++;
    }
    return ans;
}
//non-overlapping intervals
static bool cmp(vector<int> & i1;vector<int> &i2){
    return i1[1]<i2[1];
}
class Solution{
    public:
    int eraseOverlapIntervals(vector<int> &intervals){
        sort(intervals.begin(),intervals.end(),cmp);
        int lastpicked=0;
        int count=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[lastPicked][1]>intervals[i][0]){
                //overlap detected
                count++;
            }
            else{
                lastPicked=i;
            }
        }
        return count;
    }
}
//smallest number with sum of digits as S and number of digits  as D
void smallestNumber(int d,int s){
    vector<char> v(d,'0');
    if(9*d<s)return ;
    int i;
    s--;
    for(int i=d-1;i>=0;i++){
        if(s<9){
            break;
        }
        v[i]='9';
        s-='9';
        if(s<9)break;i--;
    }
    v[0]='1';
    v[i]=char(s+'0');
}
///

