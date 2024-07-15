//Overlapping subproblems-also called repeating subproblems,as in fibanocci series
//optimal substructure-if we are able to divide bigger problem into smaller subproblem and we have optimal solution of smaller
//subproblem and using that optimal soln if we have solved bigger problem(optimal answer) then that structuree is known as optimal substructure
//if for a problem optimal substructure exists and overlapping subproblems exist then we can use DP
//Various Approaches of DP
//1. Top Down(Memoization)(recursive) 2. Bottom Up(Tabulation)(iterative)
//Solving DP
//Identify state of the DP(subproblems of DP)
//how the subproblems are related/identify formula b/w them
//storing the results once computed
//Solving fibanocci
//state=based on value of n we can uniquely identify the state
//total n+1 states like for f(2) states are f(2),f(1),f(0)
//formula=f(n)=f(n-1)+f(n-2)
//TOP DOWN APPROACH MEMOIZATION-since we are going from bigger to smaller problems and storing them
#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int f(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(dp[n]!= -1) return dp[n];
    return dp[n]=f(n-1)+f(n-2);
}
//Fibanocci using Tabulation
int fbu(int n){
    if(n==0 || n==1)return n;
    dp.resize(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for (int i = 2; i <=n; i++)
    {
        /* code */
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    
}
//Fibanocci using Tabulation optimised
int fbuo(int n){
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c
}
int main()
{
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    cout<<f(n)<<"\n";
    cout<<fbu(n)<<"  "<<fbuo(n)<<endl;
   return 0;
}
// dp[i]-> -1
// that the ith state is not yet computed
// dp[i] != -1
// that the ith states is already computed

//if we can represent state of DP using 1 variable then we use 1D array
//while if we need 2 variables then we at max require 2D array but can sometimes be solved in 1D array
//House robber problem
#include<iostream>
using namespace std;
vector<int> dp;
//TOP DOWN
int f(int i,vector<int> &arr){
    if(i>=arr.size())return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(arr[i]+f(i+2,arr),f(i+1,arr));
}
//BOTTOM UP
int fbu(int i,vector<int> &arr){
    int n=arr.size();
    dp[n-1]=arr[n-1];
    if(n==1)return arr[n-1];
    dp[n-2]=max(arr[n-1],arr[n-2]);
    for (int i = n-3; i >=0; i--)
    {
        /* code */
        dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
    }
    
}
int main()
{
    dp.resize(arr.size()+10,-1);
   return 0;
}
