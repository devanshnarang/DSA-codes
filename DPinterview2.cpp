//UNIQUE PATHS 2
#include<iostream>
using namespace std;
int f(int i,int j){
    if(i==(n-1) and j==(m-1))return 1;
    if(i<0 or j<0 or i>=n or j>=n)return 0;
    if(grid[i][j]==1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=f(i,j+1)+f(i+1,j);
}
int main()
{
    vector<vector<int>> dp;
    dp.resize(m,vector<int> (n,-1));
    if(grid[m-1][n-1]==1)return 0;
   return 0;
}
//MAXIMUM PATH SUM
int f(int i,int j){
    if(i==m or j==n)return 0;
    if(i==(m-1) or j==(n-1))return grid[i][j];
    return grid[i][j]+min(f(i+1,j),f(i,j+1));
}
//Partition equal Subset Problem
#include<iostream>
using namespace std;
bool f(vector<int> &arr,int i,int k){
    if(k==0)return true;
    if (i==arr.size())return false;
    if(dp[i][k]!=-1)return dp[i][k];
    if (arr[i]<=k)
    {
        /* code */
        return dp[i][k]=f(arr,i+1,k-arr[i]) or f(arr,i+1,k);
    }
    else{
        return dp[i][k]=f(arr,i+1,k);
    }
    
}
int main()
{
    vector<vector<int>> dp;
    dp.clear();
    dp.resize(205,vector<int> (20005,-1));
    int s=0;
    for (int  i = 0; i < arr.size(); i++)
    {
        /* code */
        s+=nums[i];
    }
    if (s%2!=0)
    {
        /* code */
        return false;
    }
    return f(nums,0,s/2);
    int n=nums.size();
    int k=s/2;
    for (int i = 0; i < n; i++)
    {
        /* code */
        dp[i][0]=true;
    }
    
    for (int i = n-1; i>=0; i--)
    {
        /* code */
        for (int j = 1; j < k; j++)
        {
            /* code */
            if(nums[i]<=j)dp[i][j]=dp[i][j-arr[i]] or dp[i+1][j];
            else{
                dp[i][j]=dp[i+1][j];
            }

        }
        return dp[0][k];
    }
    
   return 0;
}
//Unique Binary search Trees
#include<iostream>
using namespace std;
int f(int n){
    if (n==0 || n==1)return 1;
    if (n==2)return 2;
    int sum=0;
    for (int k = 1; k <= n; k++)
    {
        /* code */
        sum+=f(k-1)*f(n-k);
    }
    return sum;
           
}
int main()
{
    
    return f(n);
   return 0;
}