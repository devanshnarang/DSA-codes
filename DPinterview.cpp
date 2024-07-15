//TRIANGLE PROBLEM
#include<iostream>
using namespace std;
int f(int r,int c){
    if (r==grid.sizee()-1)
    {
        /* code */
        return grid[r][c];
    }
    if(dp[r][c]!=INT_MAX)return dp[r][c];
    return dp[r][c]=grid[r][c]+min(f(r+1,c),f(r+1,c+1));
}
int fbu(int r,int c){
    //base case
    int rows=grid.size();
    for (int i = 0; i < grid[rows-1].length; i++)
    {
        /* code */
        dp[rows-1][i]=grid[row-1][i];
    }
    for (int i = rows-2; i>=0; i--)
    {
        /* code */
        for (int j = 0; i < grid[i].size(); j++)
        {
            /* code */
            dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        } 
    }
    return dp[0][0];
    
    
}
int main()
{
    vector<vector<int>> dp;
    dp.clear();
    dp.resize(205,vector<int> (205,INT_MAX));
   return 0;
}
//LONGEST COMMON SUBSEQUENCE
#include<iostream>
int f(string &a,string &b,int i,int j){
    if(i==a.size() || b==j.size())return 0;
    if(dp[i][j]!=INT_MAX)return dp[i][j];
    if (a[i]!=b[j])
    {
        /* code */
        return dp[i][j]=max(f(a,b,i+1,j),f(a,b,i,j+1));
    }
    else{
        return dp[i][j]=1+f(a,b,i+1,j+1);
    }  
}
int fbu(string &a,string &b,int i,int j){
    int n=a.size();
    int m=b.size();
    for(int i=n-1,i>=0,i--){
        for(int j=m-1;j>=0;j--){
            if (a[i]!=b[j])
            {
                /* code */
                dp[i][j]=max(dp[i+1][j],dp[i],[j+1]);
            }
            else{
                dp[i][j]=1+dp[i+1][j+1];
            } 
        }
    }
    return dp[0][0];
}
using namespace std;
int main()
{
    vector<vector<int>> dp;
    dp.resize(1005,vector<int> (1005,0));
    return f(text1,texxt2,0,0);
   return 0;
}
//LONGEST INCREASING SUBSEQUENCE
#include<iostream>
using namespace std;
int f(int i){
    if (i==0)
    {
        return dp[0]=1;
    }
    int mx=INT_MIN;
    if(dp[i]!=-1)return dp[i];
    for (int j = 0; j<=i-1; j++)
    {
        if (arr[j]<arr[i])
        {
            /* code */
            mx=max(mx,f(j));
        }   
    }
    if(mx==INT_MIN)return dp[i]=1;
    return dp[i]=1+mx;
    
    
}
int main()
{
    vector<int> dp;
    dp.resize(2505,-1);
    int ans=INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        ans=max(ans,f(i));
    } 
   return 0;
}
//MATRIX MULTIPLICATION
#include<iostream>
using namespace std;
vector<vector<int>> dp;
int f(int i,int j,vector<int> &arr){
    if (i==j || i+1==j)return 0;
    if (dp[i][j]!=-1)return dp[i][j];    
    int ans=INT_MAX;
    for (int k = i+1; i < j; i++)
    {
        ans=min(ans,f(i,k,arr)+f(k,j,arr)+arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j]=ans;       
}
for(int len=3;len<=n;len++){
    for(int i=0;i+len-1<n;i++){
        int j=i+len-1;
        dp[i][j]=INT_MAX;
        for (int k = i+1; i < j; i++)
        {
            dp[i][j]=min(dp[i][j],dp[i][k]+d[k][j]+arr[i]*arr[k]*arr[j]);
        }
    }
}

int main()
{
   return 0;
}