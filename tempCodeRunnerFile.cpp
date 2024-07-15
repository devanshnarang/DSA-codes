#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
bool isPalindrome(string &t){
    int i=0,j=t.size()-1;
    while (i<=j)
    {
        if(t[i]!=t[j])return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<string> arr(n);
    map<string,int> palindromes;
    map<string,int> strings;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for(auto it:arr){
        if(isPalindrome(it)){
            palindromes[it]++;
        }
        else{
            strings[it]++;
        }
    }
    int maxiSingleLength=0;
    int len=0;
    for(auto it:palindromes){
        if(it.second%2==0)len+=(2*it.first.size());
        else{
            if(it.first.size()>maxiSingleLength){
                maxiSingleLength=it.first.size();
            }
        }
    }
    int normalLength=0;
    for(auto it:strings){
        string t=it.first;
        reverse(t.begin(),t.end());
        if(strings.find(t)!=strings.end()){
            int sz=t.size();
            normalLength=max(normalLength,2*sz);
        }
    }
    cout<<(len+maxiSingleLength+normalLength)<<endl;
    return 0;
}