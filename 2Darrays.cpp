// 
/*multidimensional array - array of arrays
// #declaration-datatype array_name[size1][size2]...[sizeN]
// uses of multidimensional arrays-representing grids
// faster access,predefined size*/
// //matrix multiplication
// /*#include<iostream>
// using namespace std;
// int main(){
//     int r1;c1,r2,c2;
//     cin>>r1>>c1;
//     cin>>r2>>c2;
//     int mat1[r1][c1];
//     int mat2[r2][c2];
//     int mat3[r1][c2];
//     for (int i = 0; i < r1; i++)
//     {
//         for (int j = 0; j < c2; j++)
//         {
//             int value=0;
//             for (int k = 0; k <r2 ; k++)
//             {
//                 value+=mat1[i][k]*mat2[k][j];
//             }
//             mat3[i][j]=value;            
//         }        
//     }    
//     return 0;
// }*/
// 
//transpose of a matrix
// #include<iostream>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int m1[n][m];
//     int m2[m][n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin>>m1[i][j];
//         }        
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             m2[i][j]=m1[j][i];                            
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout<<m2[i][j]<<" ";
//         }
//         cout<<endl;        
//     }            
//     return 0;
// }
