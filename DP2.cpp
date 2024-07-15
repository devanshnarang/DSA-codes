//DECODE WAYS
#include<iostream>
using namespace std;
int string_to_int(string s){
    if(s.size()==1)return s[0]-'0';
    return (s[0]-'0')*10+(s[1]-'0');
}
int f(string str,int idx){
    //return number of decodings of the string from index idx to n-1
    if(idx==str.size()-1){
        if(str[idx]=='0')return 0;
        if(idx==str.size())return 0;
        if(str[idx]=='0'){
            return 0;
        }
        else{
            return 1;
        }
        if(idx==str.size()-2){
            bool can_form_2_digits=string_to_int(str.substr(idx,2))<=26;
            return can_form_2_digits+((str[idx]!='0')? f(str,idx+1):0);
        }
    }
    if(dp[idx]!=-1)return dp[idx];
    bool can_form_2_digits=string_to_int(str.substr(idx,2));
    return dp[idx]=((str[idx]!='0')? f(str,idx+1):0)+((can_form_2_digits)?f(str,idx+2):0);

}
int fu(string str){
    dp.clear();
    dp.resize(105,0);
    dp[n-1]=str[n-1]=='0'?0:1;
    if(str[n-2]==0)dp[n-2]=0;s
    dp[n-2]=dp[n-1]+ string_to_int(str.substr(n-2,2))<=26;
    int n=str.size();
    for(int i=n-3;i>=0;i--){
        if(str[i]=='0')dp[i]=0;continue;
        bool can_form_2_digits=string_to_int(str.substr(idx,2))<=26;
        dp[i]=dp[i+1]+ ((can_form_2_digits)?dp[i+2]:0);
    }
}
int main()
{
    dp.resize(105,-1);
    return f(str,0)
   return 0;
}

//B-FROG 2 PROBLEM
#include<iostream>
#include<vector>
using namespace std;
int f(vector<int> &heights,int i,int k){
    if (i==heights.size()-1)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        /* code */
        if (i+j>=heights.size())
        {
            break;
        }
        ans=min(ans,abs(heights[i]-heights[i+j])+f(heights,i+j,k));
        
    }
    return dp[i]=ans;
}
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000
// {900,910} {950,1120}  {1100,1130}  {940,1200}  {1500,1900}  {1800,2000}
int fbu(vector<int> &heights,int i,int k){
    int n=heights.size();
    dp[n-1]=0;
    for (int i = n-2; i >=0; i--)
    {
        for (int j = 1; j <=k; i++)
        {
            /* code */
            if(i+j>=n)break;
            dp[i]=min(dp[i],abs(heights[i]-heights[i+j])+dp[i+j]);
        }
        return dp[0];       
    }   
}
int main()
{
    int n;
    cin>>n;
    dp.clear();
    dp.resize(10005,-1);
    int k;
    cin>>k;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>v[i];
    }
    cout<<f(v,0,k)<<endl;
    return 0;
}

//COINS PROBLEMS
#include<iostream>
using namespace std;
int fbu(vector<int> &coins,int x,int n){
    vector<int> dp(1000005,0);
    int MOD=1000000007;
    dp[0]=1;
    for (int j = 0; j < n; j++)
    {
        //go to each coin
        for (int i = 1; i <= x; i++)
        {
            /* code */
            if(i-coins[j]<0)continue;
            dp[i]=(dp[i]+dp[i-coins[j]])%MOD;
        }
        return dp[x];
        

    }
    
}
int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> coins(n);
    for (int i = 0; i <n; i++)
    {
        /* code */
        cin>>coins[i];
    }
    
   return 0;
}


