//Euclid's algorithm
/*if we subtract a smaller number from a larger one (we can reduce the large number)
but the gcd will not change
Eg-gcd-54,18      
=gcd-18,54-18
=gcd-18,36-18
and gcd-54,72
=gcd-54,72%54
#include<iostream>
#include<cmath>
using namespace std;
int f(int x,int y){
    if(y==0){
        return x ;
    }
    f(y,x%y);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<f(a,b);
    return 0;
}*/


//Factors
// void f(ll n){
//     vector<int> fac;
//     for(ll i=1;i<=sqrt(n);i++){
//         if(n%i==0){
//             if(i==sqrt(n))fac.push_back(i);
//             else{
//                 fac.push_back(i);
//                 fac.push_back(n/i);
//             }
//         }
//     }
//     return fac;
// }

