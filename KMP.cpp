#include<iostream>
#include<vector>
using namespace std;
vector<int> KMPHelper(string a){
    vector<int> lps(a.size());
    int pre=0,suff=1;
    lps[0]=0;
    while (suff<a.size())
    {
        if(a[pre]==a[suff]){
            lps[suff]=pre+1;
            pre++;
            suff++;
        }
        else{
            if(pre==0){
                lps[suff]=0;
                suff++;
            }
            else{
                pre=lps[pre-1];
            }
        }
    }
    return lps;
}
int main()
{
    string s="dc$dcba";
    vector<int> z =KMPHelper(s);
    for(auto itr:z){
        cout<<itr<<" ";
    }
   return 0;
}