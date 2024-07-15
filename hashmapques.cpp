//tell if strings can be made equal
//we don't need toto transform strings by moving characters,each character should be present in multiple of length of array
// #include<iostream>
// #include<vector>
// #include<unordered_map
// using namespace std;
// bool canMakeEqual(vector<string> &v){
//     unordered_map<char,int> m;
//     for(auto str:v){
//         for(char c:v){
//             m[c]++;
//         }
//     }
//     int n=v.size();
//     for(auto ele:m){
//         if (ele.second%n!=0)
//         {
//             return false;
//         }   
//     }
//     return true;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<string> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>v[i];
//     }
//     cout<<(canMakeEqual(v))?"yes":"no"<<endl;

//     return 0;
// }
//time complexity O(N) where N is length of array space complexity -O(U) where U is number of unique characters
//check if 2 strings are anagram or not
#include<iostream>
#include<unordered_map>
using namespace std;
bool checkAnagram(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
        }
        unordered_map<char,int> m;
        for(auto ele:str1){ 
            m[ele]++;
            }
        for(auto el:str2){
            if (m.find(el)==m.end())
            {
                return false;
            }else{
                m[el]--; 
            }
        }
        for(auto ele:m){
            if(ele.second!=0){
                return false; 
            }
        }
        return true;
}
int main(){
    string str1,str2;
    cin>>str1;
    cin>>str2;
    cout<<(checkAnagram(str1,str2)?"YES":"NO")<<endl; 
    return 0;}
//Tc - O(S1+S2)  Sc-O(s1)
//check if two strings are isomorphic
#include<iostream>
#include<unordered_map>
using namespace std;
bool isIsomorphic(string s1,string s2){
    if (s1.length()!=s2.length())
    { 
        return false;
        }
    unordered_map<char,char> m;
    for (int i = 0; i < s1.length(); i++)
    {
        if (m.find(s1[i])!=m.end())
        {
            if (m[s1[i]]!=s2[i]) 
            {
                return false;
            }
        }else{
            m[s1[i]]=s2[i];
        }
    }
    m.clear();
    for (int i = 0; i < s2.length(); i++)
    { 
        if (m.find(s2[i])!=m.end())
        {
            if (m[s2[i]]!=s1[i])
            {
                return false;
            }
        }else{
            m[s2[i]]=s1[i];
            }
        }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<(isIsomorphic(s1,s2)?"YES":"NO")<<endl; 
    return 0;}
//TC-O(s1+s2)  SC-O(U) unique characters
//target sum problem
#include<iostream>
#include<unordered_map>
using namespace std;
vector<int> targetsumpair(vector<int> &v,int targetsum){
    unordered_map<int,int> m;
    vector<int> res(2);
    for (int i = 0; i < v.size(); i++)
    {
        if (m.find(targetsum-v[i])!=m.end())
        {
            res[0]=m.find(targetsum-v[i]);
            res[1]=i;
            return ans;
        }else{
            m[v[i]]=i;
        }
    }
    return ans;
}
int main(){
    int n,targetum;
    cin>>n>>targetsum;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> ans=targetsumpair(v);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;}
//TC-O(N)  
//length of longest subarray with sum=0
/*assume subarray is from l to r soa[0]+a[1]+....+a[r]-(a[0]+a[1]+a[2]+...a[l-1])=0prefix sum a[r]-prefix sum a[l-1]=0prefix sum a[r]=prefix sum a[l-1] */
#include<iostream>
#include<unordered_map>
using namespace std;
int maxLengthZeroSumSubarray(vector<int> &v){
    unordered_map<int,int> m;
    int prefixsum=0;
    int maxlen=INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        prefixsum+=v[i];
        if (prefixsum==0)
        {
            maxlen++;
        }
        if (m.find(prefixsum)!=m.end())
        {
            maxlen=max(maxlen,i-m[prefixsum]);
        }
        else{
                m[prefixsum]=i;
        }
    }
        return prefixsum;
        }
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>v[i];
    }
    cout<<maxLengthZeroSumSubarray(v)<<endl;
    return 0;
}
//TC- O(N)  SC-O(N)