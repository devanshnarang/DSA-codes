//sudoku solver
// #include<iostream>
// #include<vector>
// using namespace std;
bool canWePlace(vector<vector<int>> &board,int row,int col,int num){
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j]==num)
        {
            return false;
        }
        }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col]==num)
        {
            return false;
        }
    }
    int r=(row/3)*3;
    int c=(col/3)*3;
    for (int i = r; i < (r+3); i++)
    {
        for (int j = c; j < (c+3); j++)
        {
            if (board[i][j]==num)
            {
                return false;
            }
        } 
    }
}
bool sudoku(vector<vector<char>> &board,int row,int col){
    if (col==9)
    {
        return sudoku(board,row+1,0);
    }
    if (row==9)
    {
        return true;
    } 
    if (board[row][col]=='.')
    {
        for (int num = 1; num < 9; num++)
        {
            if (canWePlace(board,row,col,'0'+num))
            {
                board[row][col]='0'+num;
                bool res=sudoku(board,row,col+1);
                if (res)
                {
                    return true;
                }
                board[row][col]='.'; 
            } 
        }  
    }
else{
    sudoku(board,row,col+1)
    };
}
// int main(){
//     sodoku(board,0,0)
//     return 0;
// }
//Place K knights
// #include<iostream>
// #include<vector>
// using namespace std;
// bool canWPlace(vector<vector<char>> &grid,int i,int j){
//     if (i-1>=0 and j-2>=0 and grid[i-1][j-2]=='K')
//     {
//         return false;
//     }
//     if (i-2>=0 and j-1>=0 and grid[i-2][j-1]=='K')
//     {
//         return false;
//     }
//     if (i-1>=0 and j+2>=0 and grid[i-1][j+2]=='K')
//     {
//         return false;
//     }
//     if (i-2>=0 and j+1>=0 and grid[i-2][j+1]=='K')
//     {
//         return false;
//     }
//     return true;    
// }
// void knights(int m,int n,vector<vector<char>> &grid,int k,int i,int j){
//     if (k==0)
//     {
//         
//all knights palced
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0;j < n; j++)
//             {
//                 cout<grid[i][j]<<"  ";
//             }
//             cout<<endl;
//         }
//         return;
//     }
//     if (j==n)
//     {
//         return knights(m,n,grid,k,i+1,0);
//     }
//     if (i==m)
//     {
//         return;
//     }
//     for (int row = i; row < m; row++)
//     {
//         for (int col = (row==i?j:0); col < n; col++)
//         {
//             /* code */
//             if (canWeplace(grid,row,col))
//             {
//                 grid[i][j]='K';
//                 knights(m,n,grid,k-1,row,col+1);
//                 grid[i][j]='.';
//             }    
//         }        
//     }                 
// }
// int main(){
//     return 0;
// }
// #include<iostream>
// #include<vector>
// using namespace std;
// void f(vector<vector<int> &grid,int i,int j,int n,int cnt){
//     if (i<0 or j<0 or i>=n or j>=n or grid[i][j]>=0)
//     {
//         return;
//     }
//     if (count==n*n-1)
//     {
//         for (int row = 0; row < n; row++)
//         {
//             for (int col = 0; col < n; col++)
//             {
//                 cout<<grid[row][col]<<" ";
//             }
//             cout<<endl;
//         }
//         return true;   
//     }
//     grid[i][j]=cnt;
//     f(grid,i-1,j-2,cnt+1) return true;
//     f(grid,i-2,j-1,cnt+1)return true;
//     f(grid,i+1,j-2,cnt+1)return true;
//     f(grid,i+2,j-1,cnt+1)return true;
//     f(grid,i+1,j+2,cnt+1)return true;
//     f(grid,i+2,j-1,cnt+1)return true;
//     f(grid,i-1,j+2,cnt+1)return true;
//     f(grid,i-2,j+1,cnt+1)return true;
//     grid[i][j]=-1;
// }
// int main(){
    //     return 0;
    // }
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> result;void f(vector<int> &c,int idx,int t,vector<int> &v){
    if (t==0)
    {
        result.push_back(v);
        return;
    }
    if (idx==x.size())
    {
        return;
    }
    if (c[idx]<=t)
    {
        v.push_back(c[idx]);
        f(c,idx,t-c[idx],v);
        v.pop_back();
    }
    int j=idx+1;
    while (j<c.size() and c[j]==c[j-1])
    {
        j++;
    }
    f(c,j,t,v);
}
vector<vector<int>> combinationSum2(vector<int>&c,int target){
    result.clear();
    sort(c.begin(),c.end());
    vector<int> v;}int main(){
        return 0;
}