#include<iostream>
#include<vector>
using namespace std;
vector<int> ZHelper(string a){
   vector<int> z(a.size());
   z[0]=0;
   int l=0,r=0;
   for (int k = 0; k < a.size(); k++)
   {
      if(k>r){
         l=k;r=k;
         while(r<a.size() && a[r-l]==a[r]){
            r++;
         }
         z[k]=r-l;
         r--;
      }else{
         int k1=k-l;
         if(z[k1]<r-k+1){
            z[k]=z[k1];
         }
         else{
            l=k;
            while(r<a.size() && a[r]==a[r-l]){
               r++;
            }
            z[k]=r-l;
            r--;
         }
      }
   }
   return z;
}
int main()
{

   vector<int> zvector2=ZHelper("map$mmapnapie");
   for (int i = 0; i < zvector2.size(); i++)
   {
    cout<<zvector2[i]<<" &";
   }
   
   return 0;
}

//0  1  0  0  0  2  2  1  0  2  7  1  0  0  0  2  1
//0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16