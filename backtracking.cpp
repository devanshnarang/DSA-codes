//program to write all permutations of the given string s in lexicographically sorted order
#include<iostream> 
using namespace std;
void permutation(string &str,int i){
        //base case//     
        if(i==str.size()){
                cout<<str<<endl;
                
            }//     
        for (int j =i ; j < str.size(); j++)// 
        {
            swap(str[i],str[j]);
            permutation(str,i+1);  
            swap(str[i],str[j]);     
            }
}
int main(){
    string str="abcd";
    permutation(str,0); 
    return 0; 
    }
//TC-O(n!)
//Rat in a maze
// #include<iostream>
// #include<vector>
// using namespace std;
// bool canWeGo(int a,int b,vector<vector<int>> &grid){
//     return (a<grid.size() and b<grid.size() and a>=0 and b>=0) and grid[a][b]==1;
// }
// int f(int i,int j,vector<vector<int>> &grid){
//     int n=grid.size();
//     if (i==n-1 && j==n-1)
//     {
//         return 1;
//     }
//     int ans=0;
//     grid[i][j]=2;
//     if (canWeGo(i,j+1,grid))
//right
//     {
//         /* code */
//         ans+=f(i+1,j,grid);
//     }
//     if (canWeGo(i,j-1,grid))
//down
//     {
//         /* code */
//         ans+=f(i,j+1,grid);
//     }
//     if (canWeGo(i-1,j,grid))
//left
//     {
//         /* code */
//         ans+=f(i,j+1,grid);
//     }
//     if (canWeGo(i,j+1,grid))
//up
//     {
//         /* code */
//         ans+=f(i,j+1,grid);
//     }
//     grid[i][j]=1;
//     return ans;    
// }
// int main(){
//     vector<vector<int>> grid={{1,1,1,1},{0,1,0,1},{0,1,1,1},{0,1,1,1}};
//     int res=f(0,0,grid);
//     cout<<res<<endl;
//     return 0;
// }
//N Queens
#include<iostream>
#include<vector>
using namespace std;
bool canPlaceQueen(int row,int col,vector<vector<int> &grid){
//is someone attacking from vertical  up    
for (int i = row-1; i >= 0; i--){
    if (grid[i][col]=='Q')
    {        /* code */
        return false;
    }
    //is someone attacking from diagonal left    
    for (int i= row-1,j=col-1; i >= 0,j>=0; i--,j--)
    {        /* code */
        if (grid[i][j]=='Q')
        {            /* code */
        return false;
        }
    }
    //is someone attacking from diagonal right    
    for (int i = row-1,j=col+1; i >=0,j<n; i--,j++)
    {        /* code */
        if (grid[i][j]=='Q')
        {            /* code */
            return false;
        }
    }
    return true;
}
void nqueen(int currRow,int n,vector<vector<int>> &grid){
    if(currRow==n) 
    {
        for(int i = 0; i < n; i++) 
        { 
            for (int j = 0; j < n; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    for(int col = 0; col < n; col++)
    { 
        if (canPlaceQueen(currRow,col,grid))
        {
            grid[currRow][col]='Q';
            nqueen(currRow+1,n,grid);
            grid[currRow][col]='.';
        } 
    }
}
int main(){ 
    int n=4;
    return 0;}