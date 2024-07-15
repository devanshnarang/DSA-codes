// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n+1,0);
//     for (int i = 1; i < n+1; i++)
//     {
//         cin>>v[i];
//     }
//     //calculate prefix sum array
//     for (int i = 1; i < n; i++)
//     {
//         v[i]+=v[i-1];
//     }
//     int q;
//     cin>>q;
//     while(q>0){
//         int l,r;
//         cin>>l>>r;
//         int x=v[r]-v[l-1];
//         cout<<x;
//         q--; 
        
//     }
    
    
//     return 0;
    
// }
// #include<iostream>
// #include<vector>
// using namespace std;
// void vectormultiplication(vector<vector<int>> &v1,vector<vector<int>> &v2,int n,int m,int p){    
//     vector<vector<int>> v3(n,vector<int> (p));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < p;j++)
//         {
//             for (int k = 0; k < m; k++)
//             { 
//                 v3[i][j]+=(v1[i][k]*v2[k][j]);
//                 } 
//         }
//                 }
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < p; j++)
//                 {
//                     cout<<v3[i][j]<<" ";
//                      }
//                      cout<<endl;}}
//     int main(){
//         int n,m,p; 
//         cin>>n>>m>>p;
//         vector<vector<int>> v1(n,vector<int> (m));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++){
//                 cin>>v1[i][j]; 
//             }
//         }
//         vector<vector<int>> v2(m,vector<int> (p));
//         for (int i = 0; i < m; i++){
//             for (int j = 0; j < p; j++){
//                 cin>>v2[i][j];
//             }
//         }
//         vectormultiplication(v1,v2,n,m,p);
//         return 0;}


// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     int arr2[n];
//     int k;
//     cin>>k;
//     int j=0;
//     for (int i = n-k; i < n; i++)
//     {
//         arr2[j]=arr[i];
//         j++;
//     }
//     int l=k;
//     for (int i = 0; i < n-k; i++)
//     {
//         arr2[l]=arr[i];
//         l++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr2[i]<<"  ";
//     }
    
    
    

    
    
    
//     return 0;
// }


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int arr2[n];
    int k;
    cin>>k;
    int j=0;
    for (int i = n-k; i < n; i++)
    {
        arr2[j]=arr[i];
        j++;
    }
    int l=k;
    for (int i = 0; i < n-k; i++)
    {
        arr2[l]=arr[i];
        l++;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr2[i]<<"  ";
    }
    
    
    

    
    
    
    return 0;
}



